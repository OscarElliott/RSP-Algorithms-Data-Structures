#include "BST.h"
#include <iostream>

/* Implementation for Binary Search Tree*/

using namespace std;

template <typename T>
BST<T>::BST()
{
    this->data = T();
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
BST<T>::BST(T x)
{
    this->data = x;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}


template <typename T>
BST<T>* BST<T>::Search(BST<T> *tree, T x)
{
    if (tree == nullptr) 
        return nullptr;
    
    if (tree->data == x)
        return tree;
    
    if (tree->data > x)
        return (Search(tree->left, x));
    else
        return (Search(tree->right, x));
}

template <typename T>
BST<T>* BST<T>::Find_min(BST<T> *tree)
{
    if (tree == nullptr)
        return nullptr;

    BST<T>* min = tree;
    while (min->left != nullptr)
        min = tree->left;
    return min;
}

template <typename T>
void BST<T>::insert(T x, BST *tree)
{
    BST<T>* new_node = new BST(x);
    tree = insertNode(new_node, tree);
    return;
}

template <typename T>
BST<T>* BST<T>::insertNode(BST *node, BST *tree)
{
    if (tree == NULL)
    {
        return node;
    }

    if (tree->data == node->data)
    {
        delete node; // already in binary search tree therefore deallocate memory
        return tree;
    }

    if (tree->data > node->data)
        tree->left = insertNode(node, tree->left);
    else
        tree->right = insertNode(node, tree->right);

    return tree;
}


template <typename T>
BST<T>* BST<T>::deleteNode(T x, BST<T> *tree)
{
    if (tree == NULL)
        return tree;

    else if (x < tree->data)
    {
        tree->left = deleteNode(x, tree->left);
    }
    else if (x > tree->data)
    {
        tree->right = deleteNode(x, tree->right);
    }

     // if not NULL, >, <, then it is correct value therefore delete
    else
    {
        // case 1 & 2 (0 or 1 child)
        if (tree->left == NULL)
        {
            BST<T>* temp = tree->right;
            tree = NULL;
            return temp;
        }
        if (tree->right == NULL)
        {
            BST<T>* temp = tree->left;
            tree = NULL;
            return temp;
        }
        // case 3 (2 children)
        else
        {
            BST<T>* temp = Find_min(tree->right); // minNode in right Subtree
            tree->data = temp->data;
            tree->right = deleteNode(temp->data, tree->right);
        }
    }
    return tree;
}

template <typename T>
void BST<T>::inOrder(BST<T> *tree)
{
    if (tree == NULL)
    {
        return;
    }
    inOrder(tree->left);
    cout << tree->data << " ";
    inOrder(tree->right);
}

template class BST<int>;