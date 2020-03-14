//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_SELECTIONSORT_H
#define SORTALGO_SELECTIONSORT_H

#include "Sort.h"
template<typename Item>
class SelectionSort : public SortAlgo<Item> {
public:
    explicit SelectionSort(AlgoData<Item>* _data): SortAlgo<Item>(_data) {};
    void sort() override {
        for(int i=0;i<this->N();i++){
            int minIndex = i;
            for(int j=i;j<this->N();j++) {
                if(this->data->getData(j)<this->data->getData(minIndex))
                    minIndex = j;
            }
            this->data->swapData(i,minIndex);
        }
        printSort();
    }
    void printSort() override {
        cout<<"Selection Sort: ";
        this->data->printData();
    }
};


#endif //SORTALGO_SELECTIONSORT_H
