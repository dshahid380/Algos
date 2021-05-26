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

	Node* findMin(Node* rootptr) {
		Node* rootptr = root;
		if(rootptr == NULL)
			return -1;

		while(rootptr->left != NULL){
			rootptr = rootptr->left; 
		}
		return rootptr;
    }

    Node* removeNode(Node* rootptr, int data) {
    	if(rootptr == NULL)
    		return rootptr;

    	else if(data < rootptr->data)
    		rootptr->left = removeNode(rootptr->left, data);

    	else if(data > rootptr->data)
    		rootptr->right = removeNode(rootptr->right, data);

    	else{
    		if(rootptr->left == NULL && rootptr->right == NULL){
    			delete rootptr;
    			rootptr = NULL;
    		}

    		else if(rootptr->left == NULL){
    			Node* currentNode = rootptr;
    			rootptr = rootptr->right;
    			delete currentNode;
    		}

    		else if(rootptr->right == NULL){
    			Node* currentNode = rootptr;
    			rootptr = rootptr->left;
    			delete currentNode;
    		}

    		else{
    			Node* currentNode = findMin(rootptr->right);
    			rootptr->data = currentNode->data;
    			rootptr->right = removeNode(rootptr->right, currentNode->data);
    		}
    	}

    	return rootptr;
    }

public:
	void insert(int data){
		root = insertNode(data, root);
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

    void deleteNode(int data) {
    	root = removeNode(root, data);
    }
};
