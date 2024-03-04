/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lru_replacement.h"
#include <climits>
#include <iostream>
#include<deque>
using namespace std;

// TODO: Add your implementation here
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Complete this constructor
}

// TODO: Add your implementations for desctructor, touch_page, load_page, replace_page here
LRUReplacement::~LRUReplacement()
{
    // TODO: Add necessary code here
}

// Accesss a page alreay in physical memory
void LRUReplacement::touch_page(int page_num)
{
    /*
    if(!mydeque.empty())
    {
        mydeque.erase(least_used[page_num]);
        mydeque.push_front(page_num);
        least_used[page_num] = mydeque.begin();
    }
    */
}


// Access an invalid page, but free frames are available
void LRUReplacement::load_page(int page_num) {
   /* 
   page_table[page_num].valid = true;

    mydeque.push_front(page_num);
    least_used[page_num] = mydeque.begin();
    frame_count++;
    page_faults++;
    */

}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) {
/*
    int replace = mydeque.back();
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = page_table[replace].frame_num;
    mydeque.push_front(page_num); //add new page number
    least_used[page_num] = mydeque.begin(); // add page number iterator to hash map
    page_faults++;
    page_replaces++;
*/


    return 0;
}