#ifndef BST_H
#define BST_H

template <typename T>
class BST
{
    public:
        // variables
        T data;
        BST* parent;
        BST* left;
        BST* right;
        // operations
        BST();
        BST(T x);
        BST* Search(BST *tree, T x);
        BST* Find_min(BST *tree);
        void insert(T x, BST *tree);
        BST* insertNode(BST* node, BST *tree); //helper function
        BST* deleteNode(T x, BST *tree);
        void inOrder(BST *tree);
};
#endif