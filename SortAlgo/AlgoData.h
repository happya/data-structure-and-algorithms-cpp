//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_ALGODATA_H
#define SORTALGO_ALGODATA_H

#include <iostream>
#include <random>
#include <ctime>
#include <cassert>
#include <vector>
#include <algorithm>
#include "Heap.h"

using namespace std;

enum class Type {Default, NearlyOrdered, Identical};

template<typename Item>
class AlgoData {
private:
    typedef vector<Item> NUMS;
    NUMS numbers;
    int N;
//    friend class MaxHeap<Item>;
public:
    explicit AlgoData(int n) : N(n) { numbers = NUMS(N, 0); }
    explicit AlgoData(const NUMS& v) : numbers(v) { N = (int)(v.size()); }
    AlgoData(int n, int randomBound, Type dataType) : AlgoData(n) {
        Item lBound = (Item)1;
        Item rBound = (Item)randomBound;
        if(dataType == Type::Identical){
            Item avgNumber = (lBound + rBound) / 2;
            lBound = avgNumber;
            rBound = avgNumber;
        }
        static default_random_engine engine((unsigned int)(time(nullptr)));
        static uniform_real_distribution<double> num(lBound, rBound + 1);
        for(int i=0;i<N;i++)
            numbers[i] = (Item)num(engine);

        if(dataType == Type::NearlyOrdered){
            int swapTime = (int)(0.02*N);
            sort(numbers.begin(), numbers.end());
            static uniform_int_distribution<int> idx(0,N-1);
            for(int i=0;i<swapTime;i++) {
                int a = idx(engine);
                int b = idx(engine);
                swapData(a,b);
            }
        }
    }
    AlgoData(int n, int randomBound) : AlgoData(n,randomBound,Type::Default) {};
    AlgoData(const AlgoData<Item>& algodata) { N = algodata.N; numbers = algodata.numbers; }
    int getSize() { return N; }
    Item getData(int i) {
        assert(i>=0 && i<N);
        return numbers[i];
    }
    void setData(int i,Item d){
        assert(i>=0 && i<N);
        numbers[i] = d;
    }
    void swapData(int i, int j) {
        Item tmp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = tmp;
    }
    void printData() {
        for(int i=0;i<N;i++)
            cout<<getData(i)<<" ";
        cout<<endl;
    }
    NUMS copyData(int start, int length) {
        NUMS t;
        for(int i=start;i<start+length;i++)
            t.push_back(getData(i));
        return t;
    }
};


#endif //SORTALGO_ALGODATA_H
