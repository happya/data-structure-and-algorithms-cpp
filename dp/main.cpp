#include <iostream>
#include <vector>
#include "ShortestSub.h"
using namespace std;

void testShortestSub(vector<int>& nums){
    ShortestSub* ss = new ShortestSub(nums);
    ss->getRes();
    delete ss;
}
int main() {
    vector<int> nums = {1,1, 2, 2,2, 3, 3, 3};
    testShortestSub(nums);
    nums = vector<int>{1, 2, 3,4,5};
    testShortestSub(nums);
    nums = vector<int>{1,2,2, 1,2,2,1, 3,  3, 3};
    testShortestSub(nums);
    nums = vector<int>{1,2,2,1,3,3};
    testShortestSub(nums);
    nums = vector<int>{2, 1, 1, 3, 3,2};
    testShortestSub(nums);
    nums = vector<int>{1,2,1,1, 3,2,2,3,4,5};
    testShortestSub(nums);

    return 0;
}
