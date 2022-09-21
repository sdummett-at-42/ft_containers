#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <functional>			// Required for std::less<Key>
#include <memory>				// Required for std::allocator<T>
#include "pair.hpp"				// Required for ft::pair<const key_type,mapped_type>
#include "make_pair.hpp"
#include "rbnode.hpp"

#define BLACK	0
#define RED		1

namespace ft {

	// Note: define private/public member functions
	template<
			typename Key,
			typename T,
			typename Compare = std::less<Key>,
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




		rbtree( const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type()) :
			_comp(comp),
			_alloc(alloc),
			_p(0),
			_size(0) {
			tnull = init_tnull();
			tnull->color = BLACK;
			tnull->left = NULL;
			tnull->right = NULL;
			root = tnull;
		}

		~rbtree() {
			destroy_tree(root);
			delete tnull;
		}

		/* ------------- RBTree utils ------------- */

		void rb_transplant(rbnode<value_type> *u, rbnode<value_type> *v) {
			if (u->parent == tnull)			// u is root
				root = v;
			else if (u == u->parent->left)	// u is left child
				u->parent->left = v;
			else							// u is right child
				u->parent->right = v;
			v->parent = u->parent;
		}

		rbnode<value_type> *minimum(rbnode<value_type> *x) {
			while (x->left != tnull)
				x = x->left;
			return x;
		}

		rbnode<value_type>	*init_tnull() {
			rbnode<value_type> *tnull = new rbnode<value_type>;
			tnull->parent = tnull;
			tnull->left = tnull;
			tnull->right = tnull;
			tnull->color = RED;
			return tnull;
		}

		rbnode<value_type>	*init_new_node(value_type val) {
			rbnode<value_type> *new_node = new rbnode<value_type>;
			new_node->content = _alloc.allocate(sizeof(value_type));
			_alloc.construct(new_node->content, val);
			new_node->parent = tnull;
			new_node->left = tnull;
			new_node->right = tnull;
			new_node->color = RED;
			return new_node;
		}

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
			if (y->left != tnull)
				y->left->parent = x;

			y->parent = x->parent;
			if (x->parent == tnull	)
				root = y;
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
			if (y->right != tnull)
				y->right->parent = x;

			y->parent = x->parent;
			if (x->parent == tnull)
				root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;

			y->right = x;
			x->parent = y;
		}


		/* ------------- RBTree insertion ------------- */

		void	insert(value_type val) {
			rbnode<value_type> *new_node = init_new_node(val);

			if (root == tnull) {
				root = new_node;
				new_node->color = BLACK;
			}
			else {
				recursive_insertion(root, new_node);
				rb_insert_fixup(new_node);
			}
			++_size;
		}

		// Note: Fix duplicate keys in rbtree

		/* Go deep down to tree until a leaf is found
		*/
		void recursive_insertion(rbnode<value_type> *root, rbnode<value_type> *new_node) {
			if (root != tnull && _comp(new_node->content->first,
				root->content->first)) {
				if (root->left != tnull) {
					recursive_insertion(root->left, new_node);
					return ;
				}
				else
					root->left = new_node;
			}
			else if (root != tnull) {
				if (root->right != tnull) {
					recursive_insertion(root->right, new_node);
					return ;
				}
				else
					root->right = new_node;
			}
			new_node->parent = root;
		}

		void rb_insert_fixup(rbnode<value_type> *new_node) {
			if (new_node->parent == tnull)
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

			if (z->left == tnull) {			// no children or only right
				x = z->right;
				rb_transplant(z, z->right);
			}
			else if (z->right == tnull) {	// only left chilldren
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
			while (x != root && x->color == BLACK) {
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
						x = root;
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
						x = root;
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

		void destroy_tree(rbnode<value_type> *root) {
			if (root == tnull)
				return ;
			destroy_tree(root->left);
			destroy_tree(root->right);
			destroy_node(root);
		}

		void clear() {
			destroy_tree(root);
			_size = 0;
		}


		/* ------------- RBTree display ------------- */

		/* Print the tree structure on the screen
		*/
		void print_helper(rbnode<value_type> *root, std::string indent, bool last) {
			if (root != tnull) {
				std::cout<<indent;
				if (last) {
					std::cout<<"R----";
					indent += "     ";
				} else {
					std::cout<<"L----";
					indent += "|    ";
				}
				std::string sColor = root->color?"RED":"BLACK";
				std::cout<<root->content->first<<"("<<sColor<<")"<<std::endl;
				print_helper(root->left, indent, false);
				print_helper(root->right, indent, true);
			}
		}

		void pretty_print() {
			if (root != tnull) {
				print_helper(root, "", true);
			}
		}

		protected:
		key_compare				_comp;
		allocator_type			_alloc;
		pointer					_p;
		size_type				_size;
		ft::rbnode<value_type>	*root;
		ft::rbnode<value_type>	*tnull;
	};
}

#endif