#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

class MaxHeap {
private:
    vector<int> v;
public:
    int size;
    MaxHeap() {size = 0;v=vector<int> {INT_MAX};}
    MaxHeap(vector<int>& vec){
        v = vector<int> {INT_MAX};
        size = 0;
        Heapify(vec);
    };
    ~MaxHeap(){};
    int TopHeap() {assert(v.size()>1); return v[1];}
    void Insert(int item);
    void Heapify(vector<int>& vec);
    void PopMax();
    bool isEmpty() { return size < 1 ? true : false; }
    void PrintHeap();
};

void MaxHeap::Heapify(vector<int>& vec) {
    for(int item : vec) {
        this->Insert(item);
    }
}
void MaxHeap::Insert(int item) {
    v.push_back(item);
    ++size;

    int i = size;
    for(;v[i/2]<item;i/=2)
        v[i] = v[i/2];
    v[i] = item;
    cout<<"Insert "<<item<<" successfully"<<endl;
}
void MaxHeap::PopMax() {
    if(!this->isEmpty()) {
        int tmp = v[size--];
        int parent, child;
        for(parent = 1; parent*2 <= size;parent=child) {
            child = parent * 2; // left child
            //有right child且right-child更大，child指向更大的child
            if(child!=size && v[child] < v[child+1])
                child++;
            if(tmp>=v[child]) break;
            else
                v[parent] = v[child];
        }
        v[parent] = tmp;
        return;
    }
}
void MaxHeap::PrintHeap() {
    if (this->isEmpty())
        cout<<"the heap is empty"<<endl;
    else {
        for(int i=1;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}
int main() {
    //MaxHeap H;
    vector<int> v = {1,10,7,9};
    MaxHeap H(v);
    H.PrintHeap();
    while(!H.isEmpty()) {
        cout<<H.TopHeap()<<endl;
        H.PopMax();
    }
}