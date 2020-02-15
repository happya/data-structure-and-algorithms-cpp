#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;
int main() {
    vector<int> a({6,4,7,2,8,5,9});
    auto bst = new BST<int>();
    // insert keys to the tree
    for(auto n : a) {
        bst->insertKey(n);
    }
    bst->insertKey(1);
    bst->insertKey(3);
    bst->preOrder();
    bst->inOrder();
    auto node = bst->searchIter(7);
    cout<<node->key<<endl;
    // cout<<bst->preNode(node)->key<<endl;
    bst->removeKey(6);
    bst->inOrder();
    cout<<"The max node value is: "<<bst->maxNode()->key<<endl;
    cout<<"The min node value is: "<<bst->minNode()->key<<endl;
    return 0;
}