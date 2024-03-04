/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author (Amanuel Biru/Lucian Pate)
 * @brief Implementation file for the buffer class
 * @version 0.1
 */

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include<deque>
#include<iostream>
#include "buffer.h"

using namespace std;
// we initilize the size and set the count to zero than resizes the container so that it can contain all elements 
Buffer::Buffer(int size) : size(size), count(0) {}

Buffer::~Buffer() {}
// if the buffer is full than the boolean would be true cant insert anymore otherwise false more item needed to be inserted
bool Buffer::insert_item(buffer_item item) {
    if (is_full()) {
        cout << "Buffer is full. Item cannot be inserted." << endl;
        return false;
    } else {
        buffer[count] = item;
        count++;
        return true;
    }
}
// if the buffer is empty no items were removed otherwise return true if item was removed than decrement it for each removed item
bool Buffer::remove_item(buffer_item *item) {
    if (!is_empty()) {
        *item = buffer.front();
        buffer.pop_front();
        count--;
        return true;
        } 
    else {
         cout << "Buffer is empty. No item to remove." << endl;
        return false;

    }
}
// we are returning the size which is intitilized to 5 within the vector
int Buffer::get_size() {
    return size;
}
// we returning the count that starts to increment the buffer count starting at 0
int Buffer::get_count() {
    return count;
}
// we return the empty and set count to zero 
bool Buffer::is_empty() {
    return(count == 0);
}
// we return the  is full function to set the interation
bool Buffer::is_full() {
    return(count == size);
    
}
//we will start with a empty buffer and than loop all through the array index starting at 0 and print each value
void Buffer::print_buffer() {
    if (is_empty()) {
        cout << "the Buffer is empty." << endl;
    } 
    else {
        cout << "Buffer: [";
        for (int i = 0; i < count; i++) {
            cout << buffer[i];
        }
          cout<<"]" << endl;
    }
}
