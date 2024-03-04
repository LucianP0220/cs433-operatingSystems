/**
* Assignment 3: CPU Scheduler
 * @file scheduler_priority.cpp
 * @author Amanuel Biru and Lucian Pate
 * @brief This Scheduler class implements the Priority scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include<iostream>
#include<algorithm>
#include<vector>
#include "scheduler_priority.h"
using namespace std;

//constructor for SchedulerPriority
SchedulerPriority::SchedulerPriority() {}
//destructor for SchedulerPriority
SchedulerPriority::~SchedulerPriority() {}

//initializing vector<PCB> as process
void SchedulerPriority::init(vector<PCB>& process_list) {
   
    this->process_list = process_list;
}

void SchedulerPriority::print_results() {
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

/*
simulating Priority scheduler by sorting the process list by Priority
then for all processes put into the list calculate the waiting time,
turnaround time and update the current time 
*/
void SchedulerPriority::simulate() {
    // sort the process list by priority
    sort(process_list.begin(), process_list.end(), [](const PCB& a, const PCB& b) { return a.priority > b.priority; });

    int current_time = 0;

    for (int i = 0; i < process_list.size(); i++) {
        int arrival_time = process_list[i].arrival_time;
        int burst_time = process_list[i].burst_time;
        double waiting_time = 0;
        double turnaround_time = 0;

        if (current_time < arrival_time) {
            current_time = arrival_time;
        }
        waiting_time = current_time - arrival_time;
        turnaround_time = waiting_time + burst_time;
        current_time += burst_time;

        process_list[i].waiting_time = waiting_time;
        process_list[i].turnaround_time = turnaround_time;
    }
}
