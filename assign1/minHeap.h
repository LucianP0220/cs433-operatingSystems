#pragma once
#include <iostream>
#include <vector>
#include "pcb.h"

using namespace std;

typedef PCB* T;

class Heap{
    private:
    //T *heaparray;
    vector<T> heaparray;
    int count;
    int capacity;

    public:
    Heap();
    Heap(int size);
    ~Heap();
    Heap(const Heap &other){
        if(this == &other) return;
    
    this->capacity = other.capacity;
    this->count = other.count;
    //heaparray = new T[capacity];
    heaparray.resize(capacity);
    for(int i = 0; i<count; i++){
        this->heaparray[i] = other.heaparray[i];
        }
    }

    Heap &operator=(const Heap &other){
        if(this == &other) return *this;

        this->capacity = other.capacity;
        this->count = other.count;
        //heaparray = new T[capacity];
        heaparray.resize(capacity);

        for(int i = 0; i<count; i++){
            heaparray[i] = other.heaparray[i];
        }
    return *this;
    }

    void insert(T val);
    T removeMin();
    int parent(int index);
    int right(int index);
    int left(int index);
    void swap(int index1, int index2);
    void decreaseKey(int index, T new_val);
    void heapify(int index);
    void deleteKey(int index);
    void displayAll();
    int size();

};
