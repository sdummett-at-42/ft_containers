#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "rbnode.hpp"

#define BLACK	0
#define RED		1

namespace ft {

	// Note: define private/public member functions
	template< typename T >
	class rbtree {

		public:

		ft::rbnode<T> *root;
		ft::rbnode<T> *tnull;

		rbtree() {
			tnull = init_new_node(0);
			tnull->color = BLACK;
			tnull->left = NULL;
			tnull->right = NULL;
			root = tnull;
		}

		// Note: implement destuctor to
		// release the memory (all the
		// allocated nodes).
		~rbtree() {
			destroy_tree(root);
			delete tnull;
		}

		/* ------------- RBTree utils ------------- */

		void rb_transplant(rbnode<T> *u, rbnode<T> *v) {
			if (u->parent == tnull)			// u is root
				root = v;
			else if (u == u->parent->left)	// u is left child
				u->parent->left = v;
			else							// u is right child
				u->parent->right = v;
			v->parent = u->parent;
		}

		rbnode<T> *minimum(rbnode<T> *x) {
			while (x->left != tnull)
				x = x->left;
			return x;
		}
		rbnode<T>	*init_new_node(T key) {
			rbnode<T> *new_node = new rbnode<T>;
			new_node->key = key;
			new_node->parent = tnull;
			new_node->left = tnull;
			new_node->right = tnull;
			new_node->color = RED;
			return new_node;
		}


	/* ------------- RBTree rotation ------------- */

		void	left_rotation(rbnode<T> *x) {
			rbnode<T>	*y = x->right;
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

		void	right_rotation(rbnode<T> *x) {
			rbnode<T>	*y = x->left;
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

		void	insert(T key, ft::rbtree<T> *rbtree) {
			rbnode<T> *new_node = init_new_node(key);

			if (rbtree->root == tnull) {
				rbtree->root = new_node;
				new_node->color = BLACK;
			}
			else {
				recursive_insertion(rbtree->root, new_node);
				rb_insert_fixup(new_node);
			}
		}

		/* Go deep down to tree until a leaf is found
		*/
		void recursive_insertion(rbnode<T> *root, rbnode<T> *new_node) {
			if (root != tnull && new_node->key < root->key) {
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

		void rb_insert_fixup(rbnode<T> *new_node) {
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

		void	rb_delete(rbnode<T> *z) {
			rbnode<T> *x;
			rbnode<T> *y = z;
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
			delete z;
		}

		// Note: Add comment that explain each case.
		void rb_delete_fixup(rbnode<T> *x) {
			rbnode<T> *w;
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

		void print_helper(rbnode<T> *root, std::string indent, bool last) {
			// print the tree structure on the screen
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
				std::cout<<root->key<<"("<<sColor<<")"<<std::endl;
				print_helper(root->left, indent, false);
				print_helper(root->right, indent, true);
			}
		}

		void pretty_print() {
			if (root != tnull) {
				print_helper(root, "", true);
			}
		}

		void destroy_tree(rbnode<T> *root) {
			if (root == tnull)
				return ;
			destroy_tree(root->left);
			destroy_tree(root->right);
			delete root;
		}

		void clear() {
			destroy_tree(root);
		}
	};
}

#endif