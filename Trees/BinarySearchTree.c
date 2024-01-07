#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* root;

struct BstNode* getNewNode(int data){
    struct BstNode* newNode = (struct BstNode*) malloc(sizeof (struct BstNode));
    newNode->data  = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//Insertion for Binary Search tree.
struct BstNode* insert(struct BstNode* root,int data){
    if(root == NULL){
        root = getNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}
bool Search(struct BstNode* root,int data){
    if(root==NULL) return false;
    else if(root->data == data) return true; // if it is the number that you search
    else if(data <= root->data) return Search(root->left,data); // if data is lesser than the root's data variable then search the left part.
    else return Search(root->right,data);

}
int findMinRecursive(struct BstNode* root){
    if(root == NULL){
        printf("Empty tree");
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return findMinRecursive(root->left);
}
int findMin(struct BstNode* root){
    if(root == NULL){
        printf("Tree is empty\n");
    }
    struct BstNode* current = root;
    while(current->left != NULL ){
        current = current->left;
    }
    return current->data;

}

int main(){
    struct BstNode* root = NULL;
    root = insert(root,15);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,14);
    root = insert(root,16);
    root = insert(root,31);

    int number;
    printf("Enter the number that you want to search in BST: ");
    scanf("%d",&number);

    if(Search(root,number)) printf("%d is found in BST \n",number);
    else printf("%d is not found in BST",number);
}
