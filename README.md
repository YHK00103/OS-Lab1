# OS-Lab1

## HW1-1
Please draw the tree format according the code on the report
![image](https://github.com/YHK00103/OS-Lab1/assets/117156581/12e4610d-a83f-4f4b-92fc-b106fea2f390)

## HW1-2
Write a program which uses fork() to produce the tree format in next slide.
Please note that the format and the order of fork() of your output should be the same as the following.
![image](https://github.com/YHK00103/OS-Lab1/assets/117156581/3748a1df-0e0b-4f8c-8de4-8d71bcd813bd)

## HW1-3
Finish “hw1_3.c” or “hw1_3.cpp” in order to design a C/C++ program to serve as a shell 
interface that accepts user commands then execute each command in a separate process.

Some important System Call :  
• read ( STDIN_FILENO, inputBuffer, MAX_LINE ) : read command line  
• fork() : Create child process  
• execvp ( char *command, char *params[] ) : Execute system calls  
• waitpid ( pid )  
• wait ()
![image](https://github.com/YHK00103/OS-Lab1/assets/117156581/6a1d50f0-c924-40bc-9f66-2107ca509d67)
