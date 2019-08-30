//
// Created by kedar on 23/8/19.
//

// Count BST subtrees that lie in given range
// https://www.geeksforgeeks.org/count-bst-subtrees-that-lie-in-given-range/

#include<bits/stdc++.h>
using namespace std;

#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

struct Node{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
    if(root==NULL)
        return ;
    if(root->data==a1){
        switch(lr){
            case 'L':root->left=newNode(a2);
                break;
            case 'R':root->right=newNode(a2);
                break;
        }
    }
    insert(root->left,a1,a2,lr);
    insert(root->right,a1,a2,lr);
}


int main(){


    return 0;
}