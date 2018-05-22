/**
 * bst.hpp
 * 
 * \author Daniel Salib
 * \date Wed 16 May 17:01:10 2018
 *
 */

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

/*
	T should:
		- be comparable: <
		- be copyable
*/
template<typename T>
class Bst
{
	private:
		struct Node {
			Node* left;
			Node* right;
			T val;
		};

		Node* root;

		void _delete(Node* node) {
			if(node == nullptr) {
				return;
			}

			_delete(node->left);
			_delete(node->right);

			delete node;
		}

		void _print(Node* n, size_t level = 0) const {
			if (!n) return;
			std::cout << std::string(level * 1, ' ') << n->val << std::endl;
			_print(n->left, level+1);
			_print(n->right, level+1);
		}

		Node* _copy(Node* n) {
			if(n == nullptr) {
				return nullptr;
			}

			return new Node{_copy(n->left), _copy(n->right), n->val};
		}

	public:

		Bst()
			: root(nullptr) {
				std::cout << "1" << std::endl;
		}

		Bst(const Bst& bst)
			: root(_copy(bst.root)) {
				std::cout << "2" << std::endl;
		}

		// copy and swap idiom
		Bst& operator=(Bst bst) {
			std::swap(root, bst.root);
			std::cout << "3" << std::endl;
			return *this;
		}

		const T* find(const T& val) const {
			Node* cur_node = root;
			while(cur_node != nullptr) {
				if(cur_node->val == val){
					return &val;
				} else if (val <= cur_node->val) {
					cur_node = cur_node->left;
				} else {
					cur_node = cur_node->right;
				}
			}

			return nullptr;
		}

		void insert(const T& val) {
			Node* new_node = new Node{nullptr, nullptr, val};
			if(root == nullptr) {
				root = new_node;
			} else {

				Node* cur_node = root; 

				while(true) {
					if(val <= cur_node->val) {
						if(cur_node->left == nullptr) {
							cur_node->left = new_node;
							break;
						}

						cur_node = cur_node->left;
					} else {
						if(cur_node->right == nullptr) {
							cur_node->right = new_node;
							break;
						}

						cur_node = cur_node->right;
					}
				}
			}

		}

		~Bst() {
			std::cout << "4" << std::endl;
			_delete(root);
			// vector<Node*> stack;
			// stack.push_back(root);

			// while (stack.size() != 0) {
			// 	Node* n = stack.back();
			// 	if (n->left != nullptr) {
			// 		stack.push_back(n->left);
			// 	}
			// 	if (n->right != nullptr) {
			// 		stack.push_back(n->right);
			// 	}
			// 	delete n;
			// }
		};

		void print() const {
			_print(root);
		}
};


#endif /* BST_HPP */
