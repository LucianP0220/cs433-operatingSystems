/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include<queue>
#include "fifo_replacement.h"
using namespace std;

// TODO: Add your implementation here
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
FIFOReplacement::~FIFOReplacement() {
    // TODO: Add necessary code here
}

void FIFOReplacement::load_page(int page_num) {
    // TODO: Add necessary code here
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = frame_count;
    replacement_queue.push(page_num);
    frame_count++;
    page_faults++;
}

// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num) {
    // TODO: Add necessary code here
    int victim_page = replacement_queue.front();
    page_table[victim_page].valid = false;
    replacement_queue.pop();
    replacement_queue.push(page_num);
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = page_table[victim_page].frame_num;
    page_replaces++;
    page_faults++;
    return 0;

}