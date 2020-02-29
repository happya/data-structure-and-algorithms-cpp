//
// Created by yyi on 2020/2/28.
//

#ifndef SEGMENTTREE_BINARYINDEXTREE_H
#define SEGMENTTREE_BINARYINDEXTREE_H

#include <vector>
#include <iostream>
using namespace std;
template <typename NUM>
class BinaryIndexTree {
private:
    int sz;
    vector<NUM> nums;
    vector<NUM> sumtree;
public:
    BinaryIndexTree() {
        sz = 0;
    }
    BinaryIndexTree(vector<NUM>& _nums){
        sz = _nums.size();
        nums = vector<NUM>(sz, 0);
        sumtree = vector<NUM>(sz, 0);
        nums[0] = _nums[0];
        sumtree[0] = nums[0];
        for(int i = 1; i < sz; i++){
            update(i, _nums[i]);
        }
    }
    void update(int i, NUM val){
        NUM diff = val - nums[i];
        nums[i] = val;
        cout<<"update "<<i<<"th number to: "<<val<<endl;
        for(; i < sz; i += (i & (-i))){
            sumtree[i] += diff;
        }

    }
    NUM get_sum(int i){
        NUM sum = 0;
        for(; i > 0; i -= (i & (-i))){
            sum += sumtree[i];
        }
        return sum;
    }
    NUM query(int start, int end){
        NUM sum = get_sum(end) - (start > 0 ? get_sum(start - 1) : 0);
        cout<<"sum from "<<start<<" to "<<end<<" is: "<<sum<<endl;
        return sum;
    }
};


#endif //SEGMENTTREE_BINARYINDEXTREE_H
