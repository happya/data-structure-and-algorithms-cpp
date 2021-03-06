//
// Created by yyi on 2019/10/11.

/*
 * The implementation of Binary Search Tree
 * External interfaces:
 * 1. traverse: preOrder(), inOrder(), postOrder()
 * 2. insertion: insertKey(T key);
 * 3. remove nodes: removeKey(T key);
 * 4. delete the whole tree: deleteTree()
 * 5. find min/max value nodes: minNode(), maxNode()
 */
//

#ifndef MAGICTREE_BST_H
#define MAGICTREE_BST_H


//
// Created by yyi on 2019/10/11.
//
#include <iostream>
using namespace std;

template <typename T>
class BSTNode {
private:
    typedef BSTNode<T> TreeNode;
public:
    T key;
    TreeNode* left;
    TreeNode* right;
    BSTNode(T val) : key(val), left(NULL), right(NULL) {};
};

template <typename T>
class BST {
private:
    typedef BSTNode<T> TreeNode;
    TreeNode* root;


    // private interfaces for public functions to call

    // Traverse interfaces
    void preOrder(TreeNode* &node) const;
    void inOrder(TreeNode* &node) const;
    void postOrder(TreeNode* &node) const;

    // find max and min treeNode in a tree with root to be treeRoot
    BSTNode<T>* minNode(TreeNode* &treeRoot) const;
    BSTNode<T>* maxNode(TreeNode* &treeRoot) const;

    BSTNode<T>* preNode(TreeNode* &node) const;
    BSTNode<T>* postNode(TreeNode* &node) const;


    // search, internal interface
    // search with recursive way
    BSTNode<T>* searchNode(TreeNode* &treeRoot, T key) const;
    // search with iterative way
    BSTNode<T>* searchNodeIter(TreeNode* treeRoot, T key) const;

    /*
     * insertion
     */
    BSTNode<T>* insertNode(TreeNode* &treeRoot, TreeNode* node);

    /*
     * remove nodes from BST, internal use
     */
    BSTNode<T>* removeKey(TreeNode* &node, T val);

    /*
     * delete the entire tree
     */
    void deleteTree(TreeNode* &treeRoot);

public:
    BST() : root(NULL) {}
    ~BST() { deleteTree(); }
    // Traverse, external intefaces
    void preOrder();
    void inOrder();
    void postOrder();

    // find max and min treeNode in a tree with root to be treeRoot
    BSTNode<T>* minNode();
    BSTNode<T>* maxNode();


    // insertion
    BSTNode<T>* insertKey(T val);

    // search
    // recursive
    TreeNode* search(T key);
    // iterative
    TreeNode* searchIter(T key);

    // remove a node with value of key
    BSTNode<T>* removeKey(T val);

    // delete tree
    void deleteTree();

};

template <typename T>
BSTNode<T>* BST<T> :: minNode(TreeNode* &treeRoot) const {
    if (treeRoot == NULL)
        return NULL;
    auto node = treeRoot;
    while (node->left)
        node = node->left;
    return node;
};
template <typename T>
BSTNode<T>* BST<T> ::minNode() {
    return minNode(root);
}

template <typename T>
BSTNode<T>* BST<T> :: maxNode(TreeNode* &treeRoot) const {
    if (treeRoot == NULL)
        return NULL;
    auto node = treeRoot;
    while (node->right)
        node = node->right;
    return node;
};
template <typename T>
BSTNode<T>* BST<T> :: maxNode() {
    return maxNode(root);
}
template <typename T>
BSTNode<T>* BST<T> :: preNode(TreeNode *&node) const {
    auto leftChild = node->left;
    if (leftChild == NULL)
        return NULL;
    return maxNode(leftChild);
}

/*
 * find the next Node in value
 */
template <typename T>
BSTNode<T>* BST<T> :: postNode(TreeNode* &node) const {
    auto rightChild = node->right;
    if (rightChild == NULL)
        return NULL;
    return minNode(rightChild);
}

template <typename T>
BSTNode<T>* BST<T> :: insertNode(TreeNode* &treeRoot, TreeNode* node) {
    if (treeRoot == NULL) {
        treeRoot = node;
        return treeRoot;
    }
    if (node->key > treeRoot->key) {
        treeRoot->right = insertNode(treeRoot->right, node);
    }
    if (node->key < treeRoot->key) {
        treeRoot->left = insertNode(treeRoot->left, node);
    }
    return treeRoot;
}

template <typename T>
BSTNode<T>* BST<T> :: insertKey(T val) {
    auto node = new BSTNode<T>(val);
    return insertNode(root, node);
}

template <typename T>
void BST<T> :: preOrder(TreeNode* &node) const {
    if (node!=NULL) {
        cout<<node->key<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
template <typename T>
void BST<T> :: preOrder() {
    preOrder(root);
    cout<<endl;
}

template <typename T>
void BST<T> :: inOrder(TreeNode* &node) const {
    if (node!=NULL) {
        inOrder(node->left);
        cout<<node->key<< " ";
        inOrder(node->right);
    }
}
template <typename T>
void BST<T> :: inOrder() {
    inOrder(root);
    cout<<endl;
}

template <typename T>
void BST<T> :: postOrder(TreeNode* &node) const {
    if (node!=NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->key<<" ";
    }
}

/*
 * PostOrder traverse for external use
 */
template <typename T>
void BST<T> ::postOrder() {
    postOrder(root);
    cout<<endl;
}

/*
 * Search a node
 */
template <typename T>
BSTNode<T>* BST<T> :: searchNode(TreeNode* &treeRoot, T key) const {
    if (treeRoot) {
        if (treeRoot->key == key)
            return treeRoot;
        if (treeRoot->key > key)
            return searchNode(treeRoot->left, key);
        else
            return searchNode(treeRoot->right, key);
    }
    return NULL;
}
template <typename T>
BSTNode<T>* BST<T> :: searchNodeIter(TreeNode *treeRoot, T key) const {
    while(treeRoot != NULL) {
        if (key > treeRoot->key)
            treeRoot = treeRoot->right;
        if (key < treeRoot->key)
            treeRoot = treeRoot->left;
        else
            return treeRoot;
    }
    return NULL;

}
template <typename T>
BSTNode<T>* BST<T> :: search(T key) {
    return searchNode(root, key);
}
template <typename T>
BSTNode<T>* BST<T> ::searchIter(T key) {
    return searchNodeIter(root, key);
}

template<typename T>
BSTNode<T>* BST<T> :: removeKey(BSTNode<T>* &node, T val) {
    if (node == NULL)
        return node;
    else if (val > node->key) {
        node->right = removeKey(node->right, val);
    }
    else if (val < node->key) {
        node->left = removeKey(node->left, val);
    }
    // delete node
    else {
        BSTNode<T>* tmp;
        if (node->left && node->right) {
            tmp = minNode(node->right);
            node->key = tmp->key;
            node->right = removeKey(node->right, tmp->key);
        }
        else {
            tmp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                delete tmp;
                // node = NULL;
            }
        }
    }
    return node;
}


template <typename T>
BSTNode<T>* BST<T> :: removeKey(T val) {
    root = removeKey(root, val);
    return root;
}
template <typename  T>
void BST<T> :: deleteTree(TreeNode* &treeRoot) {
    if (treeRoot->left)
        deleteTree(treeRoot->left);
    if (treeRoot->right)
        deleteTree(treeRoot->right);
    delete(treeRoot);
    treeRoot = NULL;
}

/*
 * destroy the whole Binary search tree,
 * for external use
 */
template <typename T>
void BST<T> ::deleteTree() {
    deleteTree(root);
}
#endif //MAGICTREE_BST_H
