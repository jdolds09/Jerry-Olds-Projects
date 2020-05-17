// Author: Jerry Olds
// ID: 1001533643
// Class: CSE-3320-002
// Due Date: 9/26/2018

// The MIT License (MIT)
// 
// Copyright (c) 2016, 2017 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>

#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 10     // Mav shell only supports five arguments

// Signal handlers
    void sigint_handler(pid_t pid);
    void sigstp_handler(pid_t pid);

// Function to execute history command
    void display_history(char history[][256]);

// Global process
    pid_t child_pid;

int main()
{

  char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );

// Create 2D array of strings to hold command history
    char history[15][256];
    memset(history, '\0', sizeof(history));

// Create array to hold pids
    int pids[256];
    
    int i = 0;       // This will increment up to 14 holding user commands
    int p = 0;       // This will increment to hold pids
    int counter = 0;
    int history_num; // This will be what the user selects from list of command history
    
    char token1;     // This will hold the exclamation mark if 
                     // the user wishes to execute past command
    
    char token2[2];     // This will hold the number of the particular 
                     // past command that the user wishes to execute

  while( 1 )
  {
    // Print out the msh prompt
    printf ("msh> ");

    // Read the command from the commandline.  The
    // maximum command that will be read is MAX_COMMAND_SIZE
    // This while command will wait here until the user
    // inputs something since fgets returns NULL when there
    // is no input
    while( !fgets (cmd_str, MAX_COMMAND_SIZE, stdin) );

    /* Parse input */
    char *token[MAX_NUM_ARGUMENTS];

    int   token_count = 0;                                 
                                                           
    // Pointer to point to the token
    // parsed by strsep
    char *arg_ptr;                                         
                                                           
    char *working_str  = strdup( cmd_str );                

    // we are going to move the working_str pointer so
    // keep track of its original value so we can deallocate
    // the correct amount at the end
    char *working_root = working_str;

    // Tokenize the input stringswith whitespace used as the delimiter
    while ( ( (arg_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) && 
              (token_count<MAX_NUM_ARGUMENTS))
    {
      token[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
      if( strlen( token[token_count] ) == 0 )
      {
        token[token_count] = NULL;
      }
        token_count++;
    }
// **********************MY CODE STARTS HERE*********************** 

    if(token[0] != NULL)
    {
    // Create new process
        child_pid = fork();
        int status;
    
    // Boolean for if command was found
        int found = 0;

    // Store pid
        pids[p] = getpid();
        p++;

    // Store command in history
        if(*token[0] != '!')
        {
        // If user has entered 15+ commands, all commands will shift down
        // one slot and the most recent command will take slot 15
            if(i == 14)
            {
                for(i = 1; i < 15; i++)
                {
                    memset(history[i - 1], '\0', sizeof(history[i - 1]));
                    strcpy(history[i - 1], history[i]);
                }
                memset(history[14], '\0', sizeof(history[14]));
                strcpy(history[14], token[0]);
                i = 14;
            }
        
            else
            {
                strcpy(history[i], token[0]);
                i++;
            }
        }
    
    // Get current working directory
        char cwd[256];
        getcwd(cwd, sizeof(cwd));
        strcat(cwd, "/");
   
    // Paths
        char path2[] = "/usr/local/bin/";
        char path3[] = "/usr/bin/";
        char path4[] = "/bin/";

    // Hold first and second character of token if user wishes to execute past command
        token1 = *token[0];
        token2[0] = *(token[0] + 1);
        token2[1] = *(token[0] + 2); 

    // Execute command
        if (child_pid == 0)
        {
        // Execute "!n" command
            if(token1 == '!')
            {
                if(isdigit(token2[0]) && (isdigit(token2[1]) || token2[1] == '\0'))
                {
                    history_num = atoi(token2); // Convert char to int
                    memset(token[0], '\0', sizeof(token[0]));
                    strcpy(token[0], history[history_num - 1]);
                }
            }
        
        // Catch SIGINT and SIGSTP signals and suspend process
            signal(SIGINT, sigint_handler);
            signal(SIGSTOP, sigstp_handler);

        // Change Directories
            if(strcmp(token[0], "cd") == 0)
            {
                if(chdir(token[1]) != 0)
                    printf("%s\n", strerror(errno));
                found = 1;
            }
                  
        // List files in a directory
            if(strcmp(token[0], "ls") == 0)
                execv("/bin/ls", token);

        // Background a running process
            if(strcmp(token[0], "bg") == 0)
                execvp("bg", token);

        // Execute history command
            if(strcmp(token[0], "history") == 0)
            {
                display_history(history);
                found = 1;
            }

        // List pids
            if(strcmp(token[0], "listpids") == 0)
            {
                for(counter = 0; counter < p; counter++)
                    printf("%d: %d\n", counter, pids[counter]);\
                found = 1;
            } 

        // Exit out of bash and kill process
            if(strcmp(token[0], "quit") == 0 || 
               strcmp(token[0], "exit") == 0)
                kill(child_pid, SIGINT);          

        // Search for command in current working directory
            strcat(cwd, token[0]);
            execv(cwd, token);
        
        // Search for command in "/usr/local/bin"
            strcat(path2, token[0]);
            execv(path2, token);
      
        // Search for command in "/usr/bin"
            strcat(path3, token[0]);
            execv(path3, token);
  
        // Search for command in "/bin"
            strcat(path4, token[0]);
            execv(path4, token);      

        // Command not found 
           if(found == 0)
                printf("Command not found\n");
        }
    
    waitpid(child_pid, &status, 0);    

    }  

    free( working_root );

  }
  return 0;
}


// Catch SIGINT signal and send a SIGTSTP signal instead
void sigint_handler(int sig)
{
    kill(child_pid, SIGTSTP);
}

// Catch SIGSTOP signal and send a SIGSTOP signal
void sigstp_handler(int sig)
{
    kill(child_pid, SIGSTOP);
}


// Function that will display the history
void display_history(char history[][256])
{
// Iterator
    int i = 0;

// Display contents of history
    for(i = 0; i < 15; i++)
    {
        if(history[i][0] != '\0')
            printf("%d: %s\n", (i + 1), history[i]); 
    }

}

