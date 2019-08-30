//
// Created by kedar on 18/8/19.
//


#include<bits/stdc++.h>
using namespace std;
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


void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)
            ;}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *root=NULL;
        while(n--){
            int a1,a2;
            char lr;
            cin>>a1>>a2>>lr;
            if(root==NULL){
                root=newNode(a1);
                switch(lr){
                    case 'L':root->left=newNode(a2);
                        break;
                    case 'R':root->right=newNode(a2);
                        break;
                }
            }
            else
                insert(root,a1,a2,lr);
        }
        //inorder(root);
        //cout<<endl;
        cout<<maxPathSum(root)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int maxSum = 0;
int postorder(struct Node *node){


    if(node-> left == NULL && node->right == NULL){
        return node->data;
    }

    int lsum = 0;
    if(node->left != NULL ){
        lsum = postorder(node->left);
    }
    int rsum = 0;
    if(node->right != NULL ){
        rsum = postorder(node->right);
    }
    int lrsum = lsum + node->data;
    int rrsum = rsum + node->data;
    int checkSum = lsum + node->data + rsum;
    cout << node->data <<" = " << lrsum << " = " <<
    rrsum << " = " << checkSum<< endl;
    if(maxSum < checkSum)
        maxSum = checkSum;

    if( lrsum > rrsum )
        return lrsum;
    return rrsum;


}
int maxPathSum(struct Node *root)
{

    return postorder(root);
}
