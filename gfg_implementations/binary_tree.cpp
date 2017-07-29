#include <iostream>
#include <stack>

using namespace std;

struct node{
	int data;
	node* right = NULL;
	node* left = NULL;
};

void createNode(node* &root, int data){
	root = new node();
	root -> data = data;
}

void inorderTrav(node* root){
	stack<node*> S;

	S.push(root);
	while(!S.empty()){

		while(root != NULL){
			root = root -> left;
			if(root != NULL){
				S.push(root);
			}
		}

		if(root == NULL && !S.empty()){
			cout << S.top()->data << endl;
			root = S.top()->right;
			S.pop();
			if(root != NULL){
				S.push(root);
			}
		}		
	}
}

// void preorder(node* root){
// 	stack<node*> S;
// 	S.push(root);
// 	while(!S.empty()){
		
// 	}
// }

int main(){

	node* root;

	createNode(root, 1);
	createNode(root->left, 2);
	createNode(root->right, 3);
	createNode(root->left->left, 4);
	createNode(root->left->right, 5);
	createNode(root->right->left, 6);
	createNode(root->right->right, 7);
	// cout << root->right->right->data << endl;

	inorderTrav(root);
}