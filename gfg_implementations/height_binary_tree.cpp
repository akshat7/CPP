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

int height(node* root){

	if(root == NULL){
		return 0;
	}
	return 1+max(height(root->left), height(root->right));
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

	cout << height(root) << endl;


}