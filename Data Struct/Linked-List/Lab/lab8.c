#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the file system tree
struct TreeNode {
    char name[100];
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new directory node
struct TreeNode* createDirectory(const char* name) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a subdirectory or file to a directory
void addSubDirectory(struct TreeNode* parent, const char* name) {
    if (parent == NULL) {
        printf("Parent directory does not exist\n");
        return;
    }
    if (parent->left == NULL) {
        parent->left = createDirectory(name);
    } else {
        struct TreeNode* current = parent->left;
        while (current->right != NULL) {
            current = current->right;
        }
        current->right = createDirectory(name);
    }
}

// Function to display the file system directory structure using preorder traversal
void displayPreOrder(struct TreeNode* root, int depth) {
    if (root != NULL) {
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%s\n", root->name);
        displayPreOrder(root->left, depth + 1);
        displayPreOrder(root->right, depth);
    }
}

// Function to display the file system directory structure using inorder traversal
void displayInOrder(struct TreeNode* root, int depth) {
    if (root != NULL) {
        displayInOrder(root->left, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%s\n", root->name);
        displayInOrder(root->right, depth + 1);
    }
}

// Function to display the file system directory structure using postorder traversal
void displayPostOrder(struct TreeNode* root, int depth) {
    if (root != NULL) {
        displayPostOrder(root->left, depth + 1);
        displayPostOrder(root->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%s\n", root->name);
    }
}

int main() {
    // Creating the root directory
    struct TreeNode* root = createDirectory("Root");

    // Adding subdirectories and files
    addSubDirectory(root, "Documents");
    addSubDirectory(root, "Downloads");
    addSubDirectory(root, "Pictures");

    struct TreeNode* documents = root->left;
    addSubDirectory(documents, "Work");
    addSubDirectory(documents, "Projects");

    struct TreeNode* work = documents->left;
    addSubDirectory(work, "Reports");
    addSubDirectory(work, "Presentations");

    struct TreeNode* downloads = root->left->right;
    addSubDirectory(downloads, "Software");
    addSubDirectory(downloads, "Images");

    // Displaying the file system directory structure
    printf("File System Directory Structure (PreOrder):\n");
    displayPreOrder(root, 0);

    printf("\nFile System Directory Structure (InOrder):\n");
    displayInOrder(root, 0);

    printf("\nFile System Directory Structure (PostOrder):\n");
    displayPostOrder(root, 0);

    return 0;
}
