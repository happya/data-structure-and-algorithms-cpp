//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_MERGESORT_H
#define SORTALGO_MERGESORT_H

#include "Sort.h"
template<typename Item>
class MergeSort : public SortAlgorithms<Item> {
private:
    typedef vector<Item> NUMS;
public:
    explicit MergeSort(AlgoData<Item>* _data) : SortAlgorithms<Item>(_data) {};
//    NUMS copyData(int start, int end) {
//        auto p = NUMS();
//        for(int i=start;i<=end;i++)
//            p.push_back(this->data->getData(i));
//        return p;
//    }
    void merge(NUMS& aux, int l, int mid, int r){
        int i = l, j = mid + 1;
        for(int k=l;k<=r;k++){
            if(i>mid)                   { this->data->setData(k, aux[j++]); }
            else if(j>r)                { this->data->setData(k, aux[i++]); }
            else if(aux[i]<aux[j])      { this->data->setData(k, aux[i++]); }
            else                        { this->data->setData(k, aux[j++]); }
        }
    }
    void recursiveSort(NUMS& aux, int l, int r){
        if(l>=r)
            return;
        int mid = (l + r) / 2;
        recursiveSort(aux, l, mid);
        recursiveSort(aux,mid+1, r);
        if(this->data->getData(mid)>this->data->getData(mid + 1))
            merge(aux, l, mid, r);
    }
    void sort() override {
        NUMS aux = this->data->copyData(0,this->N());
        // recursiveSort(aux, 0, N() - 1);
        // 自底向上
        // 每次merge的子序列大小为size,merge完成后子序列均有序
        // size *= 2
        for(int size=1;size<this->N();size<<=1){
            // 在整个数组范围内，
            // 对[i,i+size-1]和[i+size,i+size*2-1]的一对子序列执行merge操作
            for(int i=0;i<this->N();i+=(size<<1))
                merge(aux, 0, i+size-1, min(this->N()-1,i+(size<<1)-1));
        }
        printSort();
    }
    void printSort() override {
        cout<<"Merge sort: ";
        this->data->printData();
    }
};


#endif //SORTALGO_MERGESORT_H
