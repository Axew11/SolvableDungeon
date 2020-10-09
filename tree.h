#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Bridges.h"
#include "BSTElement.h"

using namespace std;
using namespace bridges;
using namespace bridges::dataset;

template <typename T>
class Tree {
	struct BST {
		T data;
		BST *left = nullptr, *right = nullptr;
		BST(int new_data) : data(new_data) {}
	} *root = nullptr;
	int size = 0;
	public:
	Bridges *bridges = new Bridges(0, "Username", "APIKey");
    BSTElement<T, char> *insert(BSTElement<T, char> *rt, BSTElement<T, char> *new_element) {
		if (rt == nullptr) return new_element;
		else if (new_element->getKey() < rt->getKey()) rt->setLeft(insert(rt->getLeft(), new_element));
		else rt->setRight(insert(rt->getRight(), new_element));
		return rt;
    }
	void insert(T new_data) {
		size++;
		if (!root) { //If root is null
			root = new BST(new_data);
			return;
		}
		BST *temp = root;
		while (temp) { //Temp should never be null but never hurts to check
			if (new_data == temp->data) return; //Discard duplicates
			//Go to the left
			else if (new_data < temp->data) {
				//Option 1 - spot is available
				if (temp->left == nullptr) {
					temp->left = new BST(new_data);
					return;
				}
				else temp = temp->left; //Option 2 - spot is available
			}
			//Go to the right
			else {
				if (temp->right == nullptr) {
					temp->right = new BST(new_data);
					return;
				}
				else temp = temp->right; //Option 2 - spot is available
			}
		}
	}
	bool search(T data) {
		if (!root) return false;
		BST *temp = root;
		while (temp) {
			if (data == temp->data) {
                cout << "Found " << data << ". Retrace your steps to the entrance.\n"; 
                return true;
            }
            else if (data < temp->data) {
                cout << "Take the left door at the " << temp->data << ".\n";
                temp = temp->left;
            }
			else {
                cout << "Take the right door at the " << temp->data << ".\n";
                temp = temp->right;    
		    }
        }
		return false;
	}
	void display(string s) {
		srand(time(NULL));
		vector<string> colors = {"yellow", "blue", "orange", "green", "purple", "brown", "black", "grey"};
		BSTElement<T, char> *root = nullptr;
		for (int i = 0; i < size; i++) {
			BSTElement<T, char> *node = new BSTElement<T, char>(s[i], '.');
			node->setLabel("ASCII decimal value " + to_string(s[i]) + ".");
			node->setColor(colors.at(rand() % colors.size()));
			root = insert(root, node);
			root->setColor("red");
		}
		bridges->setTitle("Genin's BST Dungeon Delve");
		bridges->setDescription("I hate bridges.");
		bridges->setDataStructure(root);
		bridges->visualize();
	}
};

