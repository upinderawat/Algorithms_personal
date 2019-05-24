#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct  Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
}Node;

class Tree{
public:
	Node* addNode(Node*,int);
	void Preorder(Node*);
	void Postorder(Node*);
	void Inorder(Node*);
	void searchTree(Node*,int);
};
void Tree::Preorder(Node *head){
	if(head == NULL){
		return;
		}
	else{
		cout<<head->data<<" ";
		Preorder(head->left);
		Preorder(head->right);
	}
}
void Tree::Postorder(Node *head){
	if(head == NULL){
		return;	}
	else{
		Postorder(head->left);
		Postorder(head->right);
		cout<<head->data<<" ";
		}
}
void Tree::Inorder(Node *head){
	if(head == NULL){
		return;
	}
	else{
		Inorder(head->left);
		cout<<head->data<<" ";
		Inorder(head->right);
	}
}
Node* Tree::addNode(Node *head,int value){
		Node *temp;
		if(head == NULL){
			temp = new Node;	
			temp->data = value;
			temp->left = NULL;
			temp->right = NULL;
		
		return temp;
		}
		else{
			if(head->data < value ){
				head->right =addNode(head->right,value);
			}
			else{
				head->left = addNode(head->left,value);
			}

		}
}
void Tree:: searchTree(Node *head,int key){
	if(head == NULL){
		cout<<"Not Found\n";
	}
	else{
		if(head->data == key){
			cout<<"Key: "<<key<<" found\n";
		}
		else if(head->data < key){
			searchTree(head->right,key);
		}
		else{
			searchTree(head->left,key);
		}
	}
}

int main(){
	int choice;
	Node *head=NULL;
	int value;
	Tree t1;
	do{
		cout<<"1. Add a node\n";
		cout<<"2. Search a node\n";
		cout<<"3. Delete a node\n";
		cout<<"4. Inorder Traversal\n";
		cout<<"5. Preorder Traversal\n";
		cout<<"6. Postorder Traversal\n";
		cout<<"7. Exit";
		cin>>choice;
		switch(choice){
			case 1:
				cin>>value;
				head = t1.addNode(head,value);
				break;
			case 2:
				cout<<"Input value to be Searched:";
				cin>>value;
				t1.searchTree(head,value);
				break;
			case 3:

				break;
			case 4:
				t1.Inorder(head);
				cout<<"\n";
				break;
			case 5:
				t1.Preorder(head);
				cout<<"\n";				
				break;
			case 6:
				t1.Postorder(head);
				cout<<"\n";
				break;
			case 7:
				exit(1);
				break;
		}

	}while(1);



	return 0;
}