#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *left = NULL, *right = NULL;
};

void insert_bst(node *root, long num){
    
    if(root->left == NULL && num <= root->data){
        root->left = new node();
        root->left->data = num;
        return;
    }
    else if(root->right == NULL && num > root->data){
        root->right = new node();
        root->right->data  = num;
        return;
    }
    else if(root->left != NULL && num <= root->data){
        insert_bst(root->left, num);
    }
    else{
        insert_bst(root->right, num);
    }
}

void preorder_bst_max(node* root, long end_node, long &max){
    if(root == NULL || root->data == end_node){
        return;
    }
    // else if(root->data == end_node){
    //     return max;
    // }
    else{
        if(max<root->data){
            max = root->data;
        }
        preorder_bst_max(root->left, end_node, max);
        preorder_bst_max(root->right, end_node, max);
    }
}


void find_root(node* root, long x, long y, pair<node*, long> &p){
    
    // pair<node*, long> p1;

    if(root == NULL){
        return;// make_pair(root, 0);
    }
    
    if(root->data == x){
        p = make_pair(root, x);
        return;
    }
    else if(root->data == y){
        p = make_pair(root, x);
        return;
    }
    else{
        find_root(root->left, x, y, p);
        find_root(root->right, x, y, p);
    }
}

int main()
{
    long n, num, x, y, swap, max;
    struct node *head, temp;
    pair<node*, long> p;
    
    cin >> n;
    cin >> num;
    
    head = new node();
    head->data = num;
    n--;
    
    while(n--){
        cin >> num;
        insert_bst(head, num);
    }
    
    cin >> x >> y;
    
    cout << "1z\n";
    
    if(x>y){
        swap = x;
        x = y;
        y = swap;
        cout << "2z\n";
    }
    
    if(x == y){
        cout << x << endl;
        cout << "3z\n";
        // return 0;
    }
    
    else if(x < head->data && y > head->data){
        max = y;
        cout << "4z\n";
        preorder_bst_max(head, y, max);
        cout << "5z\n";
    }
    // else if(x >= head->data && y > head-data){
    else{

        max = y;
        cout << "6z\n";
        find_root(head, x, y, p);
        cout << "7z\n";
        if(p.second == x){
            cout << "8z\n";
            preorder_bst_max(p.first, y, max);
            cout << "9z\n";
        }
        else{
            preorder_bst_max(p.first, x, max);
            cout << "10z\n";
        }
    }
    cout << "11z\n";
    cout << max << endl;
    // else{
    //     find_root(head, )
    // }
    
    
    return 0;
}
