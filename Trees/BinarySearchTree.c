#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* root;

struct BstNode* createNewNode(int data){
    struct BstNode* newNode = (struct BstNode*) malloc(sizeof (struct BstNode));
    newNode->data  = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//Insertion for Binary Search tree.
struct BstNode* insert(struct BstNode* root,int data){
    if(root == NULL){
        root = createNewNode(data);
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
void delete(int key, struct BstNode **leaf)
{
    if( *leaf == 0 )
        return;
    else if( key == (*leaf)->data )
        delete(key,&(*leaf));
    else if( key < (*leaf)->data )
        delete(key, &(*leaf)->left);
    else if( key > (*leaf)->data )
        delete(key, &(*leaf)->right);
}
struct BstNode* deleteRecursive(struct BstNode* root, int key) {
    if (root == NULL)
        return root;

    //for traversing until reaching the exact node that has the key value.
    if (key < root->data)
        root->left = deleteRecursive(root->left, key);
    else if (key > root->data)
        root->right = deleteRecursive(root->right, key);
    //Deletion process
    else {
        // 1 child or NO child
        if (root->left == NULL) {
            struct BstNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BstNode* temp = root->left;
            free(root);
            return temp;
        }

        // İki çocuklu durum: Sağ alt ağacın en küçük düğümünü bul
        struct BstNode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;

        root->right = deleteRecursive(root->right, temp->data);
    }

    return root;
}

int processLeftMost(struct BstNode **leaf) {
    if((*leaf)->left == NULL){
        int key = (*leaf)->data;
        struct BstNode* deleted = *leaf;
        *leaf = (*leaf)->right;
        deleted->right = NULL;
        free(deleted);
        return key;
    }
    else {
        return processLeftMost((*leaf)->left);
    }
}

void deleteNode(struct BstNode **leaf){
    struct BstNode* deleted;

    //Only 1 node on the tree.
    if((*leaf)->left == NULL && (*leaf)->right == NULL){
        free(*leaf);
        *leaf = NULL;
    }
    //NO left child
    else if((*leaf)->left == NULL){
        deleted = *leaf;
        *leaf = (*leaf)->right;
        deleted->right = NULL;
        free(deleted);
    }
    //NO Right child.
    else if((*leaf)->right == NULL){
        deleted = *leaf;
        *leaf = (*leaf)->left;
        deleted->left = NULL;
        free(deleted);
    }
    //TWO children
    else{
        (*leaf)->data = processLeftMost((*leaf)->right);
    }
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
