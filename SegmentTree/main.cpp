#include <iostream>
#include "BinaryIndexTree.h"
#include <iostream>

void testBinaryIndexTree(vector<int>& nums){
    auto bitree = new BinaryIndexTree<int>(nums);
    bitree->query(1, 4);
    bitree->update(5, 10);
    bitree->query(1, 9);
    delete bitree;
}
int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    testBinaryIndexTree(nums);
    return 0;
}
