//
// Created by yyi on 2020/2/17.
//

#ifndef DP_SHORTESTSUB_H
#define DP_SHORTESTSUB_H

#include <vector>
#include <map>
#include <set>
using namespace std;
class ShortestSub {
private:
    vector<int> res;
    vector<int> nums;
    map<int, vector<int>> records;
public:
    ShortestSub(vector<int>& _nums) : nums(_nums){

//        strictlyAscending();
        unStrictAscending();
//        helper();
    }
    void strictlyAscending(){
        for(int i = 0; i < nums.size(); i++){
            records[nums[i]].push_back(i);
            if(records[nums[i]].size() > 2){
                res = vector<int>{-1};
                return;
            }
        }
        auto iter = records.begin();
        for(; iter != records.end(); iter++){
            if(iter->second.size() > 1)
                break;
        }
        if(iter == records.end())
            return;
        vector<int> prev = iter->second;
        int preIdx = iter->second[0];
        res.push_back(iter->second[0]);
        iter++;

        for(; iter != records.end(); iter++){
            if(iter->second.size() > 1){
                auto item = iter->second.begin();
                for(; item != iter->second.end(); item++){
                    if((*item) > preIdx){
                        res.push_back(*item);
                        preIdx = *item;
                        break;
                    }
                }
                if(item == iter->second.end()){
                    res = vector<int>{-1};
                    return;
                }
                prev = iter->second;
            }
        }
    }

    void unStrictAscending(){
        for(int i = 0; i < nums.size(); i++){
            records[nums[i]].push_back(i);
        }
        auto iter = records.begin();
        while(iter->second.size() == 1)
            iter++;
        if(iter == records.end())
            return;

        iter->second.pop_back();
        vector<int> prev = iter->second;
        int lastIdx = prev.back();
        addIdx(prev);
        iter++;
        for(;iter != records.end(); iter++){
            if(iter->second.size() > 1){
                vector<int> cur;
                for(int i = 0; i < iter->second.size(); i++){
                    if(iter->second[i] > lastIdx)
                        cur.push_back(iter->second[i]);
                }
                if(iter->second.size() - cur.size() > 1){
                    res = vector<int>{-1};
                    return;
                }
                if(cur.size() == iter->second.size()) cur.pop_back();
                addIdx(cur);
                lastIdx = cur.back();
            }
        }
    }

    void addIdx(vector<int>& indices){
        for(int i = 0; i < indices.size(); i++)
            res.push_back(indices[i]);
    }


    void getRes(){
        cout<<"original array: ";
        printVector(nums);
        int n = res.size();
        if(n == 0)
            cout<<"no need to delete"<<endl;
        else if(n == 1 && res[0] == -1)
            cout<<"impossible"<<endl;
        else{
            cout<<"delete subsquence: ";
            for(auto& i : res)
                cout<<nums[i]<<" ";
            cout<<endl;
        }

    }
    void printVector(vector<int>& v){
        for(auto& i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    void printRecords(){
        for(auto iter = records.begin(); iter != records.end(); iter++){
            cout<<iter->first<<": "<<iter->second.size()<<" ";
            for(auto index = iter->second.begin(); index != iter->second.end(); index++)
                cout<<*index<<" ";
            cout<<endl;
        }
    }

};
#endif //DP_SHORTESTSUB_H
