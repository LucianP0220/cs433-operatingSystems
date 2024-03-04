
/**
 * Assignment 2: Simple UNIX Shell
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <string.h>
using namespace std;

#define MAX_LINE 80 // The maximum length command
#define MAX_ARGUMENTS 100

/**
 * @brief parse out the command and arguments from the input command separated by spaces
 *
 * @param command
 * @param args
 * @return int
 */
int parse_command(char command[],char *args[])
{
          // Split command into arguments
          int argument_count = 0;
            args[argument_count] = strtok(command, " ");
            while (args[argument_count] != NULL) 
            {
                argument_count++;
                args[argument_count] = strtok(NULL, " ");
            }
        args[argument_count] = NULL;
         // set last argument to NULL, indicating end of arguments
    return argument_count; // return number of arguments
}
//function checks if user command was entered 
bool check_user_command(char *args[])
{
    
    string command(args[0]);
    if(command == "exit" || command == "!!")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Previous(char Copy_cmd[])
{
    cout<<Copy_cmd<<endl;
    return;
}
// TODO: Add additional functions if you need

/**
 * @brief The main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @param argc The number of arguments
 * @param argv The array of arguments
 * @return The exit status of the program
 */
int main(int argc, char *argv[])
{
    char command[MAX_LINE];       // the command that was entered
    char Copy_cmd[MAX_LINE];
    char *args[MAX_LINE / 2 + 1]; // parsed out command line arguments
    int should_run = 1;           /* flag to determine when to exit program */
    char *input_file = NULL;
    char *output_file = NULL;
    int input_fd, output_fd;
    pid_t pid;
    int status;
    int command_history_count = 0;
    //bool check_user_command = false;
   //char command_history[20][MAX_LINE];
    //char Copy_command[MAX_LINE];
    while (should_run)
    {
        printf("osh>");
        fflush(stdout);
        // Read the input command
        fgets(command, MAX_LINE, stdin);

        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;
       
        // Parse the input command
        int argument_count = parse_command(command, args);       

        if(check_user_command(args)==false)
        {
            command_history_count++;
            strcpy(Copy_cmd, command);
        }                     

        // Check for input and output redirection
        for (int i = 0; i < argument_count; i++) {
            if (strcmp(args[i], "<") == 0 && i < argument_count - 1) {
                input_file = args[i+1];
                args[i] = NULL;
            }
            else if (strcmp(args[i], ">") == 0 && i < argument_count - 1) {
                output_file = args[i+1];
                args[i] = NULL;
            }
        }
        
        // Open input file if necessary
        if (input_file != NULL) {
            input_fd = open(input_file, O_RDONLY);
            if (input_fd == -1) {
                perror("open");
                continue;
            }
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        
        // Open output file if necessary
        if (output_file != NULL) {
            output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (output_fd == -1) {
                perror("open");
                continue;
            }
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        //checks if user command was entered 
        if(check_user_command(args))
        {
            //flag to exit loop upon user exit
            if(strcmp(command, "exit")==0)
            {
                should_run = 0; 
            }
            //checks if the command !! was entered 
            else if(strcmp(command, "!!")==0)
            {
                if(command_history_count > 0) 
                {
                    
                    break;
                    
                }
                
                else
                {
                    printf("No commands in history.\n");
                    continue;

                }
                

               
            }   

        }
      //if not a user command then runs the shell 
      
      else{  
        // Fork a child process to execute the command
            pid = fork();
            Previous(Copy_cmd);
            if (pid == -1) 
            {
                perror("fork");
                continue;
            }
            else if (pid == 0) 
            {
             // Child process
                execvp(args[0], args);
                cout<<"command not found"<<endl;
                exit(1);
            }
            else if (pid>0) 
            {
            // Parent process
	            // if(ampersand == false)
                waitpid(pid, &status, 0);
            }
            else
            {
                exit(1);
            }
        }
        // Reset input and output redirection
        input_file = NULL;
        output_file = NULL;

        // TODO: Add your code for the implementation
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) parent will invoke wait() unless command included &
         */
        
    
    }
    return 0;
}
