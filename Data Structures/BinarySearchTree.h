#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this->data = data;
	}
};


class BinarySearchTree {
public:
	Node* root = NULL;

	Node* createNode(int data){
		Node* newNode = new Node(data);
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}

	Node* insertNode(int data, Node* rootptr) {
		if(rootptr == NULL)
			rootptr = createNode(data);
		else if(data <= rootptr->data){
			rootptr->left = insertNode(data, rootptr->left);
		}
		else{
			rootptr->right = insertNode(data, rootptr->right);
		}

		return rootptr;
	}

	void insert(int data){
		root = insertNode(data, root);
	}

	bool findNode(int data, Node* rootptr) {
		if(rootptr == NULL)
			return false;
		else if(rootptr-> data == data)
			return true;
		else if(data <= rootptr->data)
			return findNode(data, rootptr->left);
		else
			return findNode(data, rootptr->right);
	}

	bool search(int data) {
		return findNode(data, this->root);
	}

	int getMin(){
		Node* rootptr = root;
		if(rootptr == NULL)
			return -1;

		while(rootptr->left != NULL){
			rootptr = rootptr->left; 
		}
		return rootptr->data;
	}

	int getMax() {
		Node* rootptr = root;

		if(rootptr == NULL)
			return -1;

		while(rootptr->right != NULL){
			rootptr = rootptr->right;
		}

		return rootptr->data;
	}
};
