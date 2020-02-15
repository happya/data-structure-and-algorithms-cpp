//
// Created by yyi on 2019/10/14.
//

#ifndef MAGICTREE_RBTREE_H
#define MAGICTREE_RBTREE_H

#include <cassert>
#include "BST.h"
using namespace std;
enum class RBColor {Red, Black};

template <typename T>
class RBNode : public BSTNode<T> {
public:
    RBColor color; // color of the node
    RBNode* parent;
    RBNode* left;
    RBNode* right;
    T key;
    RBNode(T _key, RBColor c, RBNode* l, RBNode* r) : key(_key), color(c), left(l), right(r) {}
    void flipColor(){
        if (color == RBColor::Black)
            color = RBColor :: Red;
        else
            color = RBColor :: Black;
    }
};

template <typename T>
class RBTree {
private:
    RBNode<T>* root;
    typedef RBNode<T>* nodeLink;
private:
    void preOrder(nodeLink &node) const;
    void inOrder(nodeLink &node) const;
    void postOrder(nodeLink &node) const;
    void printColor(nodeLink &node) const;

    // rotate
    void rotateLeft(nodeLink &node);
    void rotateRight(nodeLink &node);
    void flipNodeLinks(nodeLink &node);
    void insertFixTwoLeftReds(nodeLink &node);
    void insertFixTwoRedKids(nodeLink &node);

    //insertion
    void insert(nodeLink& node, nodeLink inode);

public:
    RBTree() : root(NULL) {};
    ~RBTree();

    // traverse
    void preOrder();
    void inOrder();
    void postOrder();

};
template <typename T>
void RBTree<T> ::printColor(nodeLink &node) const {
    if (node->color == RBColor::Red)
        cout<<"(Red) ";
    else
        cout<<"(Black) ";
}
template <typename T>
void RBTree<T> ::preOrder(nodeLink &node) const {
    if (node) {
        cout<<node->key;
        printColor(node);
        preOrder(node->left);
        preOrder(node->right);
    }
    cout<<endl;
}
template <typename T>
void RBTree<T> ::inOrder(nodeLink &node) const {
    if (node) {
        inOrder(node->left);
        cout<<node->key<<" ";
        inOrder(node->right);
    }
    cout<<endl;
}

template <typename T>
void RBTree<T> ::postOrder(nodeLink &node) const {
    if (node) {
        cout<<node->key<<" ";
        postOrder(node->left);
        postOrder(node->right);
    }
    cout<<endl;
}

template <class T>
void RBTree<T> ::preOrder() {
    preOrder(root);
}
template <class T>
void RBTree<T> ::inOrder() {
    inOrder(root);
}
template <class T>
void RBTree<T> ::postOrder() {
    postOrder(root);
}


/*
 * Rotate to keep balance
 */
/*
 * rotate left at node n:
 *              x
 *      xl          y
 *  xll     xlr   yl    yr
 *              y
 *        x           yr
 *    xl     yl
 * xll   xlr
 */
template <typename T>
void RBTree<T> ::rotateLeft(nodeLink &node) {
    // preserve information
    auto p = node->parent;
    auto newRoot = node->right;
    assert(newRoot != NULL);
    auto newRoot_l = newRoot->left;

    // define the new bind of new root
    newRoot->parent = p;
    newRoot->left = node;


    // define the new bind of old root
    node->parent = newRoot;
    node->right = newRoot_l;

}
template <typename T>
void RBTree<T> ::rotateRight(nodeLink &node) {
    // preserve
    auto p = node->parent;
    auto newRoot = node->left;
    assert(newRoot != NULL);
    auto newRoot_r = newRoot->right;

    // change new root
    newRoot->parent = p;
    newRoot->right = node;

    // change old root
    node->left = newRoot->right;
    node->parent = newRoot;

}
template <typename T>
void RBTree<T> :: flipNodeLinks(nodeLink &node) {
    if (node != NULL) {
        if (node->parent)
            node->parent->flipColor();
        if (node->left)
            node->left->flipColor();
        if (node->right)
            node->right->flipColor();
    }
}
template <typename T>
void RBTree<T> :: insert(nodeLink& node, nodeLink inode) {
    auto tmp = node;
    nodeLink parent = NULL;
    while(node != NULL) {
        parent = node;
        if (inode->key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    inode->parent = parent;
    if (parent == NULL) {
        node = inode;
        node->flipColor();
    }
    else if (inode->key < parent->key) {
        parent->left = inode;

    }
    else {
        assert(inode->key > parent->key && parent->left != NULL);
    }

    //
    assert(inode->color == RBColor::Red);
}
template <typename T>
void RBTree<T> ::insertFixTwoLeftReds(nodeLink &node) {
    //
    if (node->parent && node->parent->color == RBColor :: Red && node->parent->parent) {
        rotateRight(node->parent->parent);
    }
}
template <typename T>
void RBTree<T> :: insertFixTwoRedKids(nodeLink &node) {
    if (node->left && node->left->color == RBColor :: Red &&
        node->right && node->right->color == RBColor :: Red)
        flipNodeLinks(node);
}
#endif //MAGICTREE_RBTREE_H
