/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
  table.resize(size);
   // TODO: add your code here
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
  for(auto i = table.begin(); i!=table.end(); i++){
    delete(*i);
    (*i) = nullptr;
  }
  table.clear();
  
   // TODO: add your code here
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    // TODO: add your code here
    return table[idx];
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
  table.insert(table.begin() + idx, pcb);
    // TODO: add your code here
}
