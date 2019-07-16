#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
	}
};

Node *start = NULL;

void insertLast(int new_data) {
	Node *temp = start;
	Node *new_node = new Node(new_data);
	new_node->next = NULL;
	if(start==NULL)
        start = new_node;
    else {
    	while(temp->next!=NULL){
    		temp = temp->next;
		}
		temp->next = new_node;
	}
}

int findNode(int n) {
	
	// Assuming linkedlist indexed from 1.
	Node *temp=start;
	int cnt=1;
	if(start==NULL) {
		return -1;	
	}
	else {
		while(cnt!=n && temp->next!=NULL) {
			temp = temp->next;
			cnt++;
		}
		if(cnt==n)
			return(temp->data);
		else
		    return -1;
	}
}

void display() {
	Node *temp=start;
	if(start==NULL)
	    cout<<"List is emmpty";
	else {
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}	
}

int main() {
	insertLast(1);
	insertLast(2);
	insertLast(3);
	insertLast(4);
	insertLast(5);
	display();
	
	if(findNode(3)<0)
	    cout<<"Node not found";
	else
	   cout<<"Node data is : "<<findNode(3)<<endl;
	return 0;	
}
