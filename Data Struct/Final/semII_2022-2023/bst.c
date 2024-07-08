# include <stdio.h>
# include <stdlib.h>


struct bst {
    int data;
    struct bst *left, *right;
};

struct bst *newNodeCreate(int value){
    struct bst *newnode;
    newnode = malloc(sizeof(struct bst));

    newnode->data = value;
    newnode-> right = NULL;
    newnode -> left = NULL;
    return newnode;
}

struct bst *insertNode(struct bst *root, int value){
    // check root, if NULL buat jadi root
    if(root == NULL){
        return newNodeCreate(value);
    } 
    // check if new data lebih kecil dgn existing root 
    if(value < root->data){
        // kiri
        // masukkan bawah node 
        root->left = insertNode(root->left, value);
    } else {
        // kanan
        root->right = insertNode(root->right, value);
    }
}

void preOrder(struct bst *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct bst *root = NULL;

    root = insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);

    preOrder(root);

}