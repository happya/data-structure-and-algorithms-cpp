//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_HEAPSORT_H
#define SORTALGO_HEAPSORT_H

#include "Sort.h"
#include "Heap.h"
template<typename Item>
class HeapSort:public SortAlgo<Item>{
private:
    MaxHeap<Item>* heap;
    typedef vector<Item> NUMS;
public:
    HeapSort(AlgoData<Item>* _data) : SortAlgo<Item>(_data) {
        NUMS numbers = this->data->copyData(0,this->N());
        heap = new MaxHeap<Item>(numbers, this->N());
    }
    void sort() override {
        while(heap->getSize()>0){
//            cout<<heap->getSize()-1<<" "<<heap->getMax()<<endl;
            this->data->setData(heap->getSize()-1, heap->getMax());
            heap->popMax();
        }
        printSort();
    }
    void printSort() override {
        cout<<"Heap Sort: ";
        this->data->printData();
    }
    ~HeapSort(){ delete heap; }
};

#endif //SORTALGO_HEAPSORT_H
