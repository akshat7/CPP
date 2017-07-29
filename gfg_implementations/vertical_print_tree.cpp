#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > m;

struct node{
	int data;
	node* right = NULL;
	node* left = NULL;
};

void createNode(node* &root, int data){
	root = new node();
	root -> data = data;
}

void horizontal_distance(node* root, int count){
	if(root == NULL){
		// cout << "Reached\n";
		return;
	}
	// cout << count << "Here\n";
	m[count].push_back(root->data);
	horizontal_distance(root->left, count-1);
	horizontal_distance(root->right, count+1);
}

int main(){

	node* root;
	int s;

	createNode(root, 1);
	createNode(root->left, 2);
	createNode(root->right, 3);
	createNode(root->left->left, 4);
	createNode(root->left->right, 5);
	createNode(root->right->left, 6);
	createNode(root->right->right, 7);

	horizontal_distance(root, 0);
	// cout << "1" << endl;


	for(auto it = m.begin(); it != m.end(); it++){
		cout << it->first << " -> ";
		s = it->second.size();
		for(int i=0; i<s; i++){
			cout << it->second[i] << ' ';
		}
		
		cout << endl;
	}
	return 0;
}