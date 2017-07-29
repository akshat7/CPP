// #include <iostream>
// #include <queue>
// using namespace std;

// int count = 0;

// struct node{
//     int data;
//     struct node* left = NULL, *right = NULL;
// };

// void swap(node* &node1, node* &node2){
//     node* temp = new node();
//     // cout << "2.\n";
//     temp->data = node1->data;
//     // temp->left = node1->left;
//     // temp->right = node1->right;
    
//     node1->data = node2->data;
//     // node1->left = node2->left;
//     // node1->right = node2->right;
    
//     node2->data = temp->data;
//     count++;
//     // node2->left = temp->left;
//     // node2->right = temp->right;
// }

// void make_bst(node* &temp){
//     // cout << "1.\n";
//     if(temp == NULL){
//         return;
//     }
//     if(temp->left != NULL){
        
//         if(temp->data < temp->left->data){
//             // cout << "1.1.\n";
//             swap(temp, temp->left);
//             make_bst(temp->left);
//         }
        
//     }
    
//     if(temp->right != NULL){
//         // cout << "3.\n";
//         if(temp->data > temp->right->data){
//             swap(temp, temp->right);
//             make_bst(temp->right);
//         }
//     }
//     if(temp->left != NULL && temp->right != NULL){
        
//         if(temp->left->data > temp->right->data){
//             // cout << "1.1.\n";
//             swap(temp->left, temp->right);
//             make_bst(temp->left);
//             make_bst(temp->right);
//         }
        
//     }
//     // cout << "4.\n";
    
//     // cout << "5.\n";
    
    
// }

// void preorder(node* root){
//     if(root == NULL){
//         return;
//     }
//     cout << root->data << endl;
//     preorder(root->left);
//     preorder(root->right);
// }

// void create_tree(node* &root, int n){
//     node* temp;
//     queue<node*> q;
//     q.push(root);
//     // cout << "1.\n";
//     int num = n/2;
//     // cout << n << endl;
//     while(num--){
//         // cout << "2.\n";
//         temp = q.front();
        
//         temp->left = new node();
//         cin >> temp->left->data;
//         q.push(temp->left);
        
//         temp->right = new node();
//         cin >> temp->right->data;
//         q.push(temp->left);
        
//         q.pop();
//     }
//     if(n%2 == 1){
//         temp = q.front();
//         // cout << "3.\n";
//         temp->left = new node();
//         cin >> temp->left->data;
//     }
    
// }

// int main()
// {
//     int n;
//     cin >> n;
//     node* root = new node(), *head;
//     head = root;
//     cin >> root->data;
//     create_tree(root, n-1);
//     // preorder(root);
//     make_bst(root);
//     preorder(root);
//     // cout << count << endl;
// }

// Two nodes in the BST's swapped, correct the BST.
#include <cstdio>
#include <cstdlib>
#include <iostream> 
#include <queue>

using namespace std;
 
int count = 0;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to swap two integers
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// This function does inorder traversal to find out the two swapped nodes.
// It sets three pointers, first, middle and last.  If the swapped nodes are
// adjacent to each other, then first and middle contain the resultant nodes
// Else, first and last contain the resultant nodes
void correctBSTUtil( struct node* root, struct node** first,
                     struct node** middle, struct node** last,
                     struct node** prev )
{
    if( root )
    {
        // Recur for the left subtree
        correctBSTUtil( root->left, first, middle, last, prev );
 
        // If this node is smaller than the previous node, it's violating
        // the BST rule.
        if (*prev && root->data < (*prev)->data)
        {
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( !*first )
            {
                *first = *prev;
                *middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                *last = root;
        }
 
        // Mark this node as previous
        *prev = root;
 
        // Recur for the right subtree
        correctBSTUtil( root->right, first, middle, last, prev );
    }
}
 
// A function to fix a given BST where two nodes are swapped.  This
// function uses correctBSTUtil() to find out two nodes and swaps the
// nodes to fix the BST
void correctBST( struct node* root )
{
    // Initialize pointers needed for correctBSTUtil()
    struct node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
 
    // Set the poiters to find out two nodes
    correctBSTUtil( root, &first, &middle, &last, &prev );
 
    // Fix (or correct) the tree
    if( first && last )
    {
        swap( &(first->data), &(last->data) );
        count++;
    }
    else if( first && middle ){
        swap( &(first->data), &(middle->data) );
        count++;
	}
 
    // else nodes have not been swapped, passed tree is really BST.
}
 
/* A utility function to print Inoder traversal */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
/* Driver program to test above functions*/

void create_tree(node* &root, int n){
	node* temp;
	queue<node*> q;
	q.push(root);
	// cout << "1.\n";
	int num = n/2;
	// cout << n << endl;
	while(num--){
	    // cout << "2.\n";
	    temp = q.front();
	    
	    temp->left = new node();
	    cin >> temp->left->data;
	    q.push(temp->left);
	    
	    temp->right = new node();
	    cin >> temp->right->data;
	    q.push(temp->left);
	    
	    q.pop();
	}
	if(n%2 == 1){
	    temp = q.front();
	    // cout << "3.\n";
	    temp->left = new node();
	    cin >> temp->left->data;
	}

}

int main()
{
    int n;
    cin >> n;
    node* root = new node(), *head;
    head = root;
    cin >> root->data;
    create_tree(root, n-1);
 
    // printf("Inorder Traversal of the original tree \n");
    // printInorder(root);
    preorder(root);
    correctBST(root);
    preorder(root);
 
    // printf("\nInorder Traversal of the fixed tree \n");
    // printInorder(root);
    // // cout << count << endl;
 
    return 0;
}
