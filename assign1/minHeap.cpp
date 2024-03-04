#include "minHeap.h"

Heap::Heap(int size){
    this->capacity = size;
    this->count = 0;
    //heaparray = new T[capacity];
    heaparray.resize(capacity);
}
Heap::Heap(){
    heaparray.resize(0);
    count = 0;
}

Heap::~Heap(){
    count = 0;
    //delete[] heaparray;
    heaparray.clear();
}



void Heap::insert(T val){
    //if(capacity == count){ std::cout<<"OVERFLOW"<<std::endl;  return; }  // overflow

    count++;
    int temp = count-1;
    //heaparray[temp] = val;
    heaparray.push_back(val);

    while(temp != 0 && heaparray[parent(temp)]->priority < heaparray[temp]->priority){
        swap(temp, parent(temp));
        temp = parent(temp);
    }
}

void Heap::decreaseKey(int index, T new_val){
    heaparray[index] = new_val;

    while(index != 0 && heaparray[parent(index)]->priority < heaparray[index]->priority){
    swap(index, parent(index));
    index = parent(index);
  }
}

T Heap::removeMin(){
    if(count == 0) return nullptr;

    if(count == 1){
        count--;
        return heaparray[0];
    }

    T root = heaparray[0];
    heaparray[0] = heaparray[count-1];
    count--;
    heaparray.erase(heaparray.begin() + count);
    

    heapify(0);
    return root;
}

void Heap::heapify(int index){
    int l = left(index);
    int r = right(index);
    int smallest = index;

    if(l < count && heaparray[l]->priority > heaparray[index]->priority){
    smallest = l;
    }
    if(r < count && heaparray[r]->priority > heaparray[smallest]->priority){
    smallest = r;
    }
    if(smallest != index){
    swap(index, smallest);
    heapify(smallest);
    }
}

void Heap::deleteKey(int index){
    decreaseKey(index, nullptr);
    removeMin();
}










int Heap::parent(int index){
    return (index-1)/2;
}

int Heap::right(int index){
    return (index*2) +2;
}

int Heap::left(int index){
    return (index*2) +1;
}

void Heap::swap(int index1, int index2){
    T temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

void Heap::displayAll(){

    std::cout<<"Display Process in ReadyQueue: "<<endl;
    for(int i = 0; i<count; i++){
        heaparray[i]->display();
    }
}

int Heap::size(){
    return count;
}
