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

bool checkIdentical(node* root1, node* root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}
	else if((root1->data == root2->data) 
				&& checkIdentical(root1->left, root2->left)
				&& checkIdentical(root1->right, root2->right)){
		return true;
	}
	else{
		return false;
	}
}

int main(){

	node *root1, *root2;

	createNode(root1, 1);
	createNode(root1->left, 2);
	createNode(root1->right, 3);
	createNode(root1->left->left, 4);
	createNode(root1->left->right, 5);
	createNode(root1->right->left, 6);
	createNode(root1->right->right, 7);

	createNode(root2, 1);
	createNode(root2->left, 2);
	createNode(root2->right, 3);
	createNode(root2->left->left, 4);
	createNode(root2->left->right, 5);
	createNode(root2->right->left, 6);
	createNode(root2->right->right, 7);

	if(checkIdentical(root1, root2)){
		cout << "Trees are identical\n";
	}
	else{
		cout << "Trees are not identical\n";
	}

	return 0;
}