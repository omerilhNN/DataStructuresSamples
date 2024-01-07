#include <stdio.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

void printLevel(struct node* root, int number, int level) {
    if (root == NULL) {
        return; // Base case: reached the end of the tree
    }

    if (root->value == number) {
        printf("%d\n", level); // Print the level if the node is found
        return;
    }

    // Recursively search in the left and right subtrees
    printLevel(root->left, number, level + 1);
    printLevel(root->right, number, level + 1);
}

int main() {
    // Example usage
    struct node* root = /* Construct your binary tree here */;

    // Assume the binary tree is constructed and the root is initialized

    // Test cases
    printLevel(root, 8, 0); // It prints “2”
    printLevel(root, 4, 0); // It prints “5”
    printLevel(root, 9, 0); // It prints “4”
    printLevel(root, 12, 0); // It prints nothing

    return 0;
}
