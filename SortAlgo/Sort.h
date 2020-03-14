//
// Created by yyi on 2020/3/14.
//

#ifndef SORTALGO_SORT_H
#define SORTALGO_SORT_H


#include "AlgoData.h"

template<typename Item>
class SortAlgo {
protected:
    AlgoData<Item>* data;
public:
    explicit SortAlgo(AlgoData<Item>* _data) : data(_data) {}
    int N() { return data->getSize(); }
    virtual void sort() = 0;
    virtual void printSort() = 0;
    ~SortAlgo() { delete data; cout<<"data deleted"<<endl;}

};


#endif //SORTALGO_SORT_H
