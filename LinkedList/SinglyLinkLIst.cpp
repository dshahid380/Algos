#include<bits/stdc++.h>
using namespace std;
/*This is the example of singly linkedlist, where operations are
as follows-
     1. insertFirst  : Insert the data from front-side.
     2. insertLast   : Insert the data from back-side.
     3. insertAfter  : Insert the data after some specific element.
     4. insertBefore : Insert some data before some specific element.
     5. deleteFirst  : Delete first node
     6. deleteLast   : Delete last node
     7. deletedata   : Delete the node which have specific value
     8. display      : It displays the linkedlist
     
One can also use this linkedlist as stack. Push operation can be performed
by insertLast and pop operation can be performed by deleteLast.
*/

class Node {
	/* This is basic node of Singly linkedlist. It has just two blocks,
	one block contains the data of node and other one contains the
	address of next node or NULL.
	*/
	public:
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
	}
};

// Start or head node of the linkedlist, it will be used to travese
// the linkedlist.
Node* start = NULL;

void insertLast(int new_data) {
	/* insertLast function takes one argument as integer value and creates
	one node according to that and insert the value. It is just like stack
	push operation.
	*/
	Node* temp;
	Node* new_node = new Node(new_data);
	new_node->next = NULL;
	
	if(start==NULL){
		start = new_node;
	}
	else {
		temp = start;
		while(temp->next!=NULL)
		   temp = temp->next;
		temp->next = new_node;
	}	
}

void insertFirst(int new_data) {
	/* It takes takes two argument as interger data and create node, then
	insert the following new_data in the front part of linkedlist.
	*/
	Node* temp;
	Node* new_node = new Node(new_data);
	if(start == NULL) {
		start = new_node;
		new_node->next = NULL;
	}
	else {
		temp = start;
		start = new_node;
		new_node->next = temp;
	}
}

void insertAfter(int data, int new_data) {
	/* It inserts the new node having data=new_data after the node
	 which have data=data. 
	*/
	Node* temp = start;
	Node* new_node = new Node(new_data);
	
	if(start==NULL) {
		cout<<"Linkedlist is empty";
	}
	else {
		while(temp->data!=data)
		    temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;	
	} 	
}

void insertBefore(int data, int new_data) {
	Node* temp = start;
	Node* new_node = new Node(new_data);
	
	if(start==NULL)
	    cout<<"Linkedlist is empty";
	    
	else if(temp->data==data) {
		new_node->next = start;
		start = new_node;
	}
	
	else {
		while(temp->next->data!=data)
		    temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

void deleteLast() {
	/* It will delete the last node of the linkedlist which is
	pointing to NULL. 
	*/
	Node* temp = start;
	if(start == NULL)
	    cout<<"Linkedlist is empty";
	else {
		while(temp->next->next!=NULL)
	    	temp = temp->next;
		free(temp->next);
		temp->next=NULL;
	}
}

void deleteFirst() {
	/* It will delete first node of the linkedlist which is pointed by
	the start node.
	*/
	if(start == NULL) {
		cout<<"Linkedlist is empty";
	}
	else {
		Node* temp = start;
		start = temp->next;
		free(temp);
    }
}

void deleteData(int data) {
	/* It deletes the first occurence of the specific data in the
	given linkedlist. 
	*/
	Node* temp = start, *t;
	if(start==NULL) {
		cout<<"Linkedlist is empty";
	}
	else {
		if(temp->data==data && temp!=NULL){
			start = temp->next;
			free(temp);
		}
		else {
			while(temp!=NULL && temp->data!=data) {
				t = temp;
				temp = temp->next;
			}
			if(temp==NULL)
				cout<<"Data does not found";
			else {
				t->next = temp->next;
				free(temp);
			}
		}		
	}	
}

void display() {
	/* To shows all values of linkedlist. 
	*/
	Node* temp;
	temp = start;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main() {
	insertLast(1);
	insertLast(2);
	insertLast(3);
	insertLast(4);
	insertFirst(0);
	
	// Linkedlist : 0 1 2 3 4 
	display();
	insertBefore(0,5);
	
	// Linkedlist : 5 0 1 2 3 4
	display();
	insertAfter(2, 2);
	
	// Linkedlist : 5 0 1 2 2 3 4
	display();
	deleteLast();
	
	// Linkedlist : 5 0 1 2 2 3 
	display();
	deleteFirst();
	
	//Linkedlist : 0 1 2 2 3
	display();
	deleteData(2);
	
	//Linkedlist : 0 1 2 3
	display();
	
	return 0;
}
