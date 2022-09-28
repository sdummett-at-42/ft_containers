#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <functional>			// Required for std::less<Key>
#include <memory>				// Required for std::allocator<T>
#include "pair.hpp"				// Required for ft::pair<const key_type,mapped_type>
#include "make_pair.hpp"
#include "rbnode.hpp"
#include "rbtree_iterator.hpp"
#include "rbtree_reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"

#define BLACK	0
#define RED		1

namespace ft {

	// Note: define private/public member functions
	template<
			typename Key,
			typename T,
			typename Compare = std::less<const Key>,
			typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class rbtree {

		public:

		/* ------------- Typedefs ------------- */

		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::rbtree_iterator<value_type>		iterator;
		typedef ft::rbtree_const_iterator<value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		protected:
		key_compare				_comp;
		allocator_type			_alloc;
		size_type				_size;
		ft::rbnode<value_type>	*_tree_root;
		ft::rbnode<value_type>	*_tnull;

		public:
		/* ------------- Constructors ------------- */

		rbtree( const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type()) :
			_comp(comp),
			_alloc(alloc),
			_size(0) {
			_tnull = init_tnull();
			_tree_root = _tnull;
		}

		template <class InputIterator>
			rbtree (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) :
			_comp(comp),
			_alloc(alloc),
			_size(0) {
			_tnull = init_tnull();
			_tree_root = _tnull;
			while (first != last) {
				insert(*first);
				++first;
			}
		}

		rbtree(const rbtree& x) :
			_comp(x._comp),
			_alloc(x._alloc),
			_size(0) {
			_tnull = init_tnull();
			_tree_root = _tnull;
			*this = x;
		}

		/* ------------- operator= ------------- */

		void recursive_copy(rbnode<value_type> *to_copy, const rbtree& x) {
			if (to_copy == x._tnull)
				return ;
			recursive_copy(to_copy->left, x);
			recursive_copy(to_copy->right, x);
			insert(*(to_copy->content));
		}

		rbtree& operator= (const rbtree& x) {
			clear();
			recursive_copy(x._tree_root, x);
			return *this;
		}


		/* ------------- Allocator ------------- */

		allocator_type get_allocator() const {
			return _alloc;
		}


		/* ------------- Destructor ------------- */

		~rbtree() {
			destroy_tree(_tree_root);
			delete _tnull;
		}


		/* ------------- Iterators ------------- */

		iterator begin() {
			iterator it(lowest(), _tree_root, _tnull);
			return static_cast<iterator>(it);
		}
		const_iterator begin() const {
			const_iterator cit(lowest(), _tree_root, _tnull);
			return static_cast<const_iterator>(cit);
		}
		iterator end() {
			iterator it(_tnull, _tree_root, _tnull);
			return static_cast<iterator>(it);
		}
		const_iterator end() const {
			const_iterator cit(_tnull, _tree_root, _tnull);
			return static_cast<const_iterator>(cit);
		}

		reverse_iterator rbegin() {
			reverse_iterator rit(end());
			return static_cast<reverse_iterator>(rit);
		}
		const_reverse_iterator rbegin() const {
			const_reverse_iterator crit(end());
			return static_cast<const_reverse_iterator>(crit);
		}
		reverse_iterator rend() {
			reverse_iterator rit(begin());
			return static_cast<reverse_iterator>(rit);
		}
		const_reverse_iterator rend() const {
			const_reverse_iterator crit(begin());
			return static_cast<const_reverse_iterator>(crit);
		}


		/* ------------- Element access ------------- */

		rbnode<value_type>* recursive_search(rbnode<value_type> *root_, key_type key) const {
			if (root_ != _tnull && key == root_->content->first)
				return root_;
			else if (root_ != _tnull && _comp(key, root_->content->first)) {
				if (root_->left != _tnull)
					return recursive_search(root_->left, key);
			}
			else if (root_ != _tnull) {
				if (root_->right != _tnull)
					return recursive_search(root_->right, key);
			}
			return _tnull;
		}

		mapped_type& at( const key_type& key ) {
			rbnode<value_type>* found = recursive_search(_tree_root, key);

			if (found == _tnull) {
				std::cout << "map::at";
				throw std::out_of_range("");
			}
			return static_cast<mapped_type&>(found->content->second);
		}

		const mapped_type& at( const key_type& key ) const {
			rbnode<value_type>* found = recursive_search(_tree_root, key);

			if (found == _tnull) {
				std::cout << "map::at";
				throw std::out_of_range("");
			}
			return static_cast<const mapped_type&>(found->content->second);
		}

		// Note: Error when using operator[] with a different type :
		// implicit conversion from 'long' to 'ft::map<int, int>::mapped_type'
		// (aka 'int') changes value from 133333333337 to 189347161
		mapped_type& operator[] (const key_type& k) {
			rbnode<value_type>* found = recursive_search(_tree_root, k);

			if (found == _tnull)
				insert(ft::pair<key_type, mapped_type>(k, mapped_type()));
			found = recursive_search(_tree_root, k);
			return found->content->second;
		}


		/* ------------- RBTree utils ------------- */

		rbnode<value_type> *lowest() const {
			ft::rbnode<value_type> *lowest = _tree_root;
			while (lowest->left != _tnull)
				lowest = lowest->left;
			return lowest;
		}
		rbnode<value_type> *greatest() const {
			ft::rbnode<value_type> *greatest = _tree_root;
			while (greatest->right != _tnull)
				greatest = greatest->right;
			return greatest;
		}

		void rb_transplant(rbnode<value_type> *u, rbnode<value_type> *v) {
			if (u->parent == _tnull)			// u is root
				_tree_root = v;
			else if (u == u->parent->left)	// u is left child
				u->parent->left = v;
			else							// u is right child
				u->parent->right = v;
			v->parent = u->parent;
		}

		rbnode<value_type> *minimum(rbnode<value_type> *x) const {
			while (x->left != _tnull)
				x = x->left;
			return x;
		}

		rbnode<value_type>	*init_tnull() {
			rbnode<value_type> *_tnull = new rbnode<value_type>;
			_tnull->parent = _tnull;
			_tnull->left = _tnull;
			_tnull->right = _tnull;
			_tnull->color = RED;
			return _tnull;
		}

		rbnode<value_type>	*init_new_node(value_type val) {
			rbnode<value_type> *new_node = new rbnode<value_type>;
			new_node->content = _alloc.allocate(sizeof(value_type));
			_alloc.construct(new_node->content, val);
			new_node->parent = _tnull;
			new_node->left = _tnull;
			new_node->right = _tnull;
			new_node->color = RED;
			return new_node;
		}

		rbnode<value_type>	*get_root() const {
			return _tree_root;
		}
		rbnode<value_type>	*get_tnull() const {
			return _tnull;
		}

		/* ------------- Capacity ------------- */

		size_type size() const {
			return _size;
		}

		bool empty() const {
			if (_size == 0)
				return true;
			return false;
		}

		key_compare key_comp() const {
			return _comp;
		}

		size_type max_size() const {
			return _alloc.max_size();
		}


		/* ------------- RBTree rotation ------------- */

		void	left_rotation(rbnode<value_type> *x) {
			rbnode<value_type>	*y = x->right;
			x->right = y->left;
			if (y->left != _tnull)
				y->left->parent = x;

			y->parent = x->parent;
			if (x->parent == _tnull	)
				_tree_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;

			y->left = x;
			x->parent = y;
		}

		void	right_rotation(rbnode<value_type> *x) {
			rbnode<value_type>	*y = x->left;
			x->left = y->right;
			if (y->right != _tnull)
				y->right->parent = x;

			y->parent = x->parent;
			if (x->parent == _tnull)
				_tree_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;

			y->right = x;
			x->parent = y;
		}


		/* ------------- Modifiers ------------- */
		void erase( iterator pos ) {
			rb_delete(pos.base());
		}

		void erase( iterator first, iterator last ) {
			rbnode<value_type>* to_del;

			while (first != last) {
				to_del = first.base();
				first++;
				rb_delete(to_del);
			}
		}
		size_type erase( const Key& key ) {
			rbnode<value_type>* found = recursive_search(_tree_root, key);

			if (found == _tnull)
				return 0;
			rb_delete(found);
			return 1;
		}

		void swap (rbtree& x) {
			key_compare tmp_comp = _comp;
			allocator_type tmp_alloc = _alloc;
			size_type tmp_size = _size;
			ft::rbnode<value_type>* tmp_root = _tree_root;
			ft::rbnode<value_type>* tmp_tnull = _tnull;

			_comp = x._comp;
			_alloc = x._alloc;
			_size = x._size;
			_tree_root = x._tree_root;
			_tnull = x._tnull;

			x._comp = tmp_comp;
			x._alloc = tmp_alloc;
			x._size = tmp_size;
			x._tree_root = tmp_root;
			x._tnull = tmp_tnull;
		}


		/* ------------- Lookup ------------- */

		iterator find (const key_type& k) {
			iterator it(recursive_search(_tree_root, k), _tree_root, _tnull);
			return static_cast<iterator>(it);
		}
		const_iterator find (const key_type& k) const {
			const_iterator cit(recursive_search(_tree_root, k), _tree_root, _tnull);
			return static_cast<const_iterator>(cit);
		}
		size_type count (const key_type& k) const {
			if (recursive_search(_tree_root, k) != _tnull)
				return 1;
			return 0;
		}

		rbnode<value_type>* recursive_search_lower_bound(rbnode<value_type> *root_, mapped_type key) {
			if (root_ != _tnull && !_comp(key, root_->content->first))
				return root_;
			else if (root_ != _tnull) {
				if (root_->right != _tnull)
					return recursive_search(root_->right, key);
			}
			return _tnull;
		}
		iterator lower_bound (const key_type& k) {
			iterator it(minimum(_tree_root), _tree_root, _tnull);
			while (it.base() != _tnull && k != it->first && !_comp(k, it->first))
				it++;
			return static_cast<iterator>(it);
		}
		const_iterator lower_bound (const key_type& k) const {
			const_iterator it(minimum(_tree_root), _tree_root, _tnull);
			while (it.base() != _tnull && k != it->first && !_comp(k, it->first))
				it++;
			return static_cast<const_iterator>(it);
		}
		iterator upper_bound (const key_type& k) {
			iterator it(minimum(_tree_root), _tree_root, _tnull);
			while (it.base() != _tnull && !_comp(k, it->first))
				it++;
			return static_cast<iterator>(it);
		}
		const_iterator upper_bound (const key_type& k) const {
			const_iterator it(minimum(_tree_root), _tree_root, _tnull);
			while (it.base() != _tnull && !_comp(k, it->first))
				it++;
			return static_cast<const_iterator>(it);
		}

		ft::pair<iterator,iterator> equal_range (const key_type& k) {
			ft::pair<iterator,iterator> pr;
			pr.first = lower_bound(k);
			pr.second = upper_bound(k);
			return pr;
		}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			ft::pair<const_iterator,const_iterator> pr;
			pr.first = lower_bound(k);
			pr.second = upper_bound(k);
			return pr;
		}

		/* ------------- RBTree insertion ------------- */

		ft::pair<iterator, bool>	insert(value_type val) {
			rbnode<value_type> *new_node = init_new_node(val);
			ft::pair<iterator, bool> pr;

			if (_tree_root == _tnull) {
				_tree_root = new_node;
				new_node->color = BLACK;
				pr.first = iterator(new_node, _tree_root, _tnull);
				pr.second = true;
				++_size;
			}
			else {
				pr = recursive_insertion(_tree_root, new_node);
				if (pr.second == true) {
					rb_insert_fixup(new_node);
					++_size;
				}
				else
					destroy_node(new_node);
			}
			return pr;
		}

		iterator insert (iterator position, const value_type& val) {
			rbnode<value_type> *new_node = init_new_node(val);
			ft::pair<iterator, bool> pr;

			if (_tree_root == _tnull) {
				_tree_root = new_node;
				new_node->color = BLACK;
				pr.first = iterator(new_node, _tree_root, _tnull);
				pr.second = true;
				++_size;
			}
			else {
				pr = recursive_insertion(position.base(), new_node);
				if (pr.second == true) {
					rb_insert_fixup(new_node);
					++_size;
				}
				else
					destroy_node(new_node);
			}
			return pr.first;
		}


		// Note: Fix duplicate keys in rbtree

		/* Go deep down to tree until a leaf is found
		*/
		ft::pair<iterator, bool> recursive_insertion(rbnode<value_type> *root_, rbnode<value_type> *new_node) {
			if (root_ != _tnull && new_node->content->first == root_->content->first)
				return ft::pair<iterator,bool>(iterator(root_, _tree_root, _tnull), false);
			if (root_ != _tnull && _comp(new_node->content->first,
				root_->content->first)) {
				if (root_->left != _tnull)
					return recursive_insertion(root_->left, new_node);
				else
					root_->left = new_node;
			}
			else if (root_ != _tnull) {
				if (root_->right != _tnull)
					return recursive_insertion(root_->right, new_node);
				else
					root_->right = new_node;
			}
			new_node->parent = root_;
			return ft::pair<iterator, bool>(iterator(new_node, _tree_root, _tnull), true);
		}

		void rb_insert_fixup(rbnode<value_type> *new_node) {
			if (new_node->parent == _tnull)
				new_node->color = BLACK;
			else if (new_node->parent->color == BLACK)
				return ;
			else if (new_node->uncle() && new_node->uncle()->color == RED) {
				new_node->parent->color = BLACK;
				new_node->uncle()->color = BLACK;
				new_node->grandparent()->color = RED;
				rb_insert_fixup(new_node->grandparent());
			}
			else {
				if (new_node == new_node->grandparent()->left->right) {
					left_rotation(new_node->parent);
					new_node = new_node->left;
				}
				else if (new_node == new_node->grandparent()->right->left) {
					right_rotation(new_node->parent);
					new_node = new_node->right;
				}
				if (new_node == new_node->parent->left)
					right_rotation(new_node->grandparent());
				else
					left_rotation(new_node->grandparent());

				new_node->parent->color = BLACK;
				new_node->sibling()->color = RED;
			}
		}


		/* ------------- RBTree deletion ------------- */

		void	rb_delete(rbnode<value_type> *z) {
			rbnode<value_type> *x;
			rbnode<value_type> *y = z;
			bool y_original_color = y->color;

			if (z->left == _tnull) {			// no children or only right
				x = z->right;
				rb_transplant(z, z->right);
			}
			else if (z->right == _tnull) {	// only left chilldren
				x = z->left;
				rb_transplant(z, z->left);
			}
			else {							// both children
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z) {		// y is direct child of z
					x->parent = y;
				}
				else {
					rb_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rb_transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (y_original_color == BLACK)
				rb_delete_fixup(x);
			destroy_node(z);
			--_size;
		}


		// Note: Add comment that explain each case.
		void rb_delete_fixup(rbnode<value_type> *x) {
			rbnode<value_type> *w;
			while (x != _tree_root && x->color == BLACK) {
				if (x == x->parent->left) {
					w = x->parent->right;
					/* case 1 */
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						left_rotation(x->parent);
						w = x->parent->right;
					}
					/* case 2 */
					if (w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					}
					/* case 3 or 4 */
					else {
						/* case 3 */
						if (w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							right_rotation(w);
							w = x->parent->right;
						}
						/* case 4 */
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						left_rotation(x->parent);
						x = _tree_root;
					}
				}
				else {
					w = x->parent->left;
					/* case 1 */
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						right_rotation(x->parent);
						w = x->parent->left;
					}
					/* case 2 */
					if (w->right->color == BLACK && w->left->color == BLACK) {
						w->color = RED;
						x = x->parent;
					}
					/* case 3 or 4 */
					else {
						/* case 3 */
						if (w->left->color == BLACK) {
							w->right->color = BLACK;
							w->color = RED;
							left_rotation(w);
							w = x->parent->left;
						}
						/* case 4 */
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						right_rotation(x->parent);
						x = _tree_root;
					}
				}
			}
			x->color = BLACK;
		}

		void destroy_node(rbnode<value_type> *to_destroy) {
			_alloc.destroy(to_destroy->content);
			_alloc.deallocate(to_destroy->content, sizeof(value_type));
			delete to_destroy;
		}

		void destroy_tree(rbnode<value_type> *root_) {
			if (root_ == _tnull)
				return ;
			destroy_tree(root_->left);
			destroy_tree(root_->right);
			destroy_node(root_);
			root_ = _tnull;
		}

		void clear() {
			// destroy_tree(_tree_root);
			_size = 0;
		}


		/* ------------- RBTree display ------------- */

		/* Print the tree structure on the screen
		*/
		void print_helper(rbnode<value_type> *root_, std::string indent, bool last) {
			if (root_ != _tnull) {
				std::cout<<indent;
				if (last) {
					std::cout<<"R----";
					indent += "     ";
				} else {
					std::cout<<"L----";
					indent += "|    ";
				}
				std::string sColor = root_->color?"RED":"BLACK";
				std::cout<<root_->content->first<<"("<<sColor<<")"<<std::endl;
				print_helper(root_->left, indent, false);
				print_helper(root_->right, indent, true);
			}
		}

		void pretty_print() {
			if (_tree_root != _tnull) {
				print_helper(_tree_root, "", true);
			}
		}
	};
}

#endif