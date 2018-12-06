#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Tree node
struct Node{
int data;
struct Node *left, *right;
};

//Create a new node
Node* newNode(int data){
Node* temp = new Node;
temp-> data=data;
temp-> left = temp-> right =NULL;
}

//returns true if subtree under root is Singly
bool countSingleRec(Node* root, int &count){
    if (root==NULL)
    return false;

    //recursively count left and right subtrees
    bool left = countSingleRec(root->left, count);
    bool right= countSingleRec(root-> right, count);

    //if any of this isn't singly, then this cannot be singly
    if ( left == false || right == false){
        return false;
    } 

    //if left subtree is singly and non-empty but data doesn't match
    if (root->left && root->data!=root->left->data){
        return false;
    }

    //if right subtree is singly and non-empty but data doesn't match
    if(root-> right && root->data!=root->right->data){
        return false;
    }

    //if none of the conditions above are true, then tree under root is single-valued, increment count and continue
    count++;
    return true;   
}

int countSingle(Node* root){
    int count=0;
    countSingleRec(root, count);
    return count;
}

int main(){
    Node *root=newNode(5);
    root->left=newNode(4);
    root->left->left=newNode(4);
    root->left->right=newNode(4);
    root->right=newNode(5);
    root->right->right=newNode(5);
    cout<<"Count of single valued subtrees is "<<countSingle(root);
    return 0;
}

