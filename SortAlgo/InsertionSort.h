//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_INSERTIONSORT_H
#define SORTALGO_INSERTIONSORT_H

#include "Sort.h"

template<typename Item>
class InsertionSort : public SortAlgorithms<Item> {
public:
    explicit InsertionSort(AlgoData<Item>* _data) : SortAlgorithms<Item>(_data) {};

    void sort() override {
        for(int i=1;i<this->N();i++){
            Item curData = this->data->getData(i);
            int j = i;
            for(;j>0 && this->data->getData(j)>curData;j--){
                this->data->setData(j, this->data->getData(j-1));
            }
            this->data->setData(j,curData);
        }
        printSort();
    }
    void printSort() override {
        cout<<"Insertion sort: ";
        this->data->printData();
    }
};

#endif //SORTALGO_INSERTIONSORT_H
