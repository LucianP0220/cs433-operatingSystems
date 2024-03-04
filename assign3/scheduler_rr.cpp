/**
* Assignment 3: CPU Scheduler
 * @file scheduler_rr.h
 * @author Amanuel Biru and Lucian Pate
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
//
#include <iostream>
#include <algorithm>
#include <vector>
#include "scheduler_rr.h"

//constructor for SchedulerRR
SchedulerRR::SchedulerRR(int time_quantum) {}

//destructor for SchedulerRR
SchedulerRR::~SchedulerRR() {}

//initializing vector<PCB> as process
void SchedulerRR::init(vector<PCB>& process_list) {
   
    this->process_list = process_list;
}

void SchedulerRR::print_results() {
    cout << "Name\tID\tPriority\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    //printing all members of process_list
    for (int i = 0; i < process_list.size(); i++) {
        cout << process_list[i].name << "\t"
             << process_list[i].id << "\t"
             << process_list[i].priority << "\t\t"
             << process_list[i].burst_time << "\t\t"
             << process_list[i].arrival_time << "\t\t"
             << process_list[i].waiting_time << "\t\t"
             << process_list[i].turnaround_time << endl;
        //calculating total wait time and turnaround time
        total_waiting_time += process_list[i].waiting_time;
        total_turnaround_time += process_list[i].turnaround_time;
    }
    //calculating average wait time and turnaround time and then printing
    double average_waiting_time = total_waiting_time / process_list.size();
    double average_turnaround_time = total_turnaround_time / process_list.size();
    cout << "Average waiting time: " << average_waiting_time << endl;
    cout << "Average turnaround time: " << average_turnaround_time << endl;
}



void SchedulerRR::simulate(){

// we use the vector to keep track of the remaining burst of each process
vector<int> remaining_burst_time(process_list.size());
// this is to iterate through each process
for (int i = 0; i < process_list.size(); i++) {
    remaining_burst_time[i] = process_list[i].burst_time; // the burst time of a process is assigned to each element
}

int time_quantum = 10;
int current_time = 0;
int numProcess = process_list.size();
int total_processes = 0;

while (total_processes < numProcess) { // we use this to check if the number of processes has been completed
    bool finished = true; // initially, assume that all processes have finished

    for (int i = 0; i < process_list.size(); i++) {
        int arrival_time = process_list[i].arrival_time;
        int burst_time = remaining_burst_time[i]; 
        double waiting_time = 0;
        double turnaround_time = 0;

        if (burst_time > time_quantum) { // if remaining burst time is greater than the time quantum
            current_time += time_quantum; 
            remaining_burst_time[i] -= time_quantum; 
        } else if (burst_time > 0) { // if remaining burst time is less than  time quantum
            current_time += burst_time; 
            remaining_burst_time[i] = 0; 
            waiting_time = current_time - arrival_time - burst_time; // we calculate waiting time
            turnaround_time = current_time - arrival_time; // we calculate turnaround time
            process_list[i].waiting_time = waiting_time;
            process_list[i].turnaround_time = turnaround_time;
            total_processes++; 
        }

        if (remaining_burst_time[i] > 0) {
            finished = false; // if any process still has remaining burst time.
        }
    }

    if (finished) {
        break; // if all processes have finished, exit the loop
    }
}

}