#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = nullptr;  // Initializing ROOT to null
	}

	void insert(string element) { // Insert a Node in a Binary Search Tree
		Node* newNode = new Node(element, nullptr, nullptr); // Allocate memmory for the new node
		newNode->info = element;  // Assign to the data field of the new node
		newNode->leftchild = nullptr;  //Make the left child of the new node point to null
		newNode->rightchild = nullptr; // Make the right child of the new node point to null

		Node* parent = nullptr;
		Node* currentNode = nullptr;

		search(element, parent, currentNode);   // Locate the node which will be the parent of the new node

		if (parent == nullptr) {  // If the parent is NULL (Tree is empty)
			ROOT = newNode;  // mark the new node as the root
			return;  // exit
		}

		if (element < parent->info) {  // If the value in the data field of the new node is less than the value in the data field of the parent node
			parent->leftchild = newNode;  // Make the left child of the parent point to the new node
		}

		else if (element > parent->info) {  // If the value in the data field of the new node is greater than the value in the data field of the parent node
			parent->rightchild = newNode;  // Make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) {  // Locate the node which will be the parent of the new node
		// This function searches the current Node of the specified Node as well as the currentNode of its parent
		currentNode = ROOT;
		parent = NULL;

		while ((currentNode != NULL) && (currentNode->info != element)) {  
			parent = currentNode;  
			if (element < currentNode->info) { 
				currentNode = currentNode->leftchild;
			}
			else {
				currentNode = currentNode->rightchild;  
			}
		}
	
		void inorder(Node * ptr) // function to perform inorder traversal
		{
			if (ROOT == NULL) {
				cout << "Tree is empty" << endl;
				return;
			}
			if (ptr != NULL) {
				inorder(ptr->leftchild); // left
				cout << ptr->info << " "; // root
				inorder(ptr->rightchild); // right
			}
		}

		void preorder(Node* ptr) // function to perform inorder traversal
		{
			if (ROOT == NULL) {
				cout << "Tree is empty" << endl;
				return;
			}
			if (ptr != NULL) {
				cout << ptr->info << " "; // root
				preorder(ptr->leftchild); // left
				preorder(ptr->rightchild); // right
			}
		}

		void postorder(Node* ptr) // function to perform inorder traversal
		{
			if (ROOT == NULL) {
				cout << "Tree is empty" << endl;
				return;
			}
			if (ptr != NULL) {
				postorder(ptr->leftchild); // left
				postorder(ptr->rightchild); // right
				cout << ptr->info << " "; // root
			}
		}
	};


