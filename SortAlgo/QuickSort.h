//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_QUICKSORT_H
#define SORTALGO_QUICKSORT_H

#include "Sort.h"
template<typename Item>
class QuickSort : public SortAlgorithms<Item> {
public:
    explicit QuickSort(AlgoData<Item>* _data) : SortAlgorithms<Item>(_data) {}
    int partitionSimple(int l, int r) {
        int p = rand()%(r-l+1)+l;
        this->data->swapData(l, p);
        // l为当前pivot的索引
        Item pivot = this->data->getData(l);
        // j指向当前小于pivot值区间的最后一个值
        int j = l;
        for(int i=l+1;i<=r;i++){
            if(this->data->getData(i)<pivot){
                j++;
                this->data->swapData(j,i);
            }
        }
        // 循环结束后，[l,j]<pivot, [j+1,r]>v
        // 将j和pivot交换
        this->data->swapData(j, l);
        // 此时pivot索引为j, 即pivot应在的正确位置
        return j;
    }
    void quickSortSimple(int l, int r){
        if(l>=r)
            return;

        int p = partitionSimple(l,r);
        quickSortSimple(l, p-1);
        quickSortSimple(p+1, r);
    }
    void quickSort2Ways(int l, int r){
        if(l>=r)
            return;
        int p = partition2Ways(l,r);
        quickSort2Ways(l,p-1);
        quickSort2Ways(p+1,r);
    }
    int partition2Ways(int l, int r){
        int p = rand()%(r-l+1)+l;
        this->data->swapData(l, p);
        int i=l+1, j=r;
        Item pivot = this->data->getData(l);
        while(true){
            while(this->data->getData(i)<pivot)
                i ++;
            while(this->data->getData(j)>pivot)
                j --;
            if(i>j)
                break;
            this->data->swapData(i, j);
            i ++;
            j --;
        }
        this->data->swapData(l, j);
        return j;
    }

    void quickSort(int l, int r){
        if(l>=r)
            return;
        int p = rand()%(r-l+1)+l;
        this->data->swapData(l, p);
        // l为当前pivot的索引
        Item pivot = this->data->getData(l);
        int lt = l; // [l + 1,lt] < pivot
        int gt = r+1; // [gt,r] > pivot
        int i = l+1; // [lt,i)==v
        while(i < gt) {
            // 当前值比pivot小
            if (this->data->getData(i) < pivot) {
                lt ++;
                this->data->swapData(i, lt);
                i ++;
            }
                // 当前值比pivot大
            else if (this->data->getData(i) > pivot) {
                this->data->swapData(i, gt - 1);
                gt --;
            }
            else { i ++; }
        }
        // 扫描结束后,
        // [l + 1,lt]<pivot, [lt+1, gt-1] == v, [gt,r]>v
        // 交换l与lt,使得[l,lt-1]<pivot, [lt, gt-1] == v, [gt,r]>v
        this->data->swapData(l,lt);
        quickSort(l, lt - 1);
        quickSort(gt, r);
    }
    void sort() override {
        quickSort(0, this->N()-1);
        printSort();
    }
    void printSort() override {
        cout<<"Quick Sort: ";
        this->data->printData();
    }
};


#endif //SORTALGO_QUICKSORT_H
