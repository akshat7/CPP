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

void swap_nodes(node* &root){
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void mirror_tree(node* &root){

	if(root == NULL){
		return;
	}
	mirror_tree(root->left);
	mirror_tree(root->right);
	swap_nodes(root);
}

void inorder_trav(node* root){
	if(root == NULL){
		return;
	}
	
	inorder_trav(root->left);
	cout << root->data << endl;
	inorder_trav(root->right);

}

int main(){

	node* root;

	createNode(root, 1);
	createNode(root->left, 2);
	createNode(root->right, 3);
	createNode(root->left->left, 4);
	createNode(root->left->right, 5);
	createNode(root->right->left, 6);
	createNode(root->right->right, 7);

	cout << "Original Tree:\n";
	inorder_trav(root);

	mirror_tree(root);

	cout << "Mirror:\n";
	inorder_trav(root);


}