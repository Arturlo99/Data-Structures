#pragma once
#include <string>
using namespace std;

	struct Node
	{
		int key;
		Node* leftChild;
		Node* rightChild;
		Node* parent;

	};
class BSTtree {


private:
	Node* root;
	void swap(Node* a, Node* b);
public:

	BSTtree();
	~BSTtree();
	void display();
	void insertKey(int element);
	void deleteKey(int element);
	void inOrder(Node* node);
	void insertRandomValues(int howMany);
	string searchValue(int value);
	Node* searchNode(Node* node, int element);
	void readFromFile(string fileName);
	Node* minBSTNode(Node* node);

}; 
