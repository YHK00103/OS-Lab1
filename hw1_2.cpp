#include <iostream>
#include <unistd.h>
#include<sys/wait.h>

using namespace std;

int main() {

	pid_t pid, ppid, main_pid; //ppid = parent pid
	main_pid = getpid();
	cout << "Main Process ID : " << main_pid << endl;

	pid = fork(); //fork1

	if (pid == 0) {
		pid = getpid();
		ppid = getppid();
		cout << "Fork 1. I'm the child " << pid << ", my parent is " << ppid << "." << endl;

		pid = fork(); //fork2
		
		if (pid > 0) {
			wait(NULL);
		}
		else if (pid == 0) {
			pid = getpid();
			ppid = getppid();
			cout << "Fork 2. I'm the child " << pid << ", my parent is " << ppid << "." << endl;

			pid = fork(); //fork3

			if (pid > 0)
				wait(NULL);
			else if (pid == 0) {
				pid = getpid();
				ppid = getppid();
				cout << "Fork 3. I'm the child " << pid << ", my parent is " << ppid << "." << endl;
			}
		}
	}
	else if (pid > 0) {
		wait(NULL);
		pid = fork(); //fork4

		if (pid > 0) {
			wait(NULL);
			pid = fork(); //fork6

			if (pid > 0)
				wait(NULL);
			else if (pid == 0) {
				pid = getpid();
				ppid = getppid();
				cout << "Fork 6. I'm the child " << pid << ", my parent is " << ppid << "." << endl;
			}
		}
		else if (pid == 0) {
			pid = getpid();
			ppid = getppid();
			cout << "Fork 4. I'm the child " << pid << ", my parent is " << ppid << "." << endl;

		}

		pid = fork(); //fork5

		if (pid > 0)
			wait(NULL);
		else if (pid == 0) {
			pid = getpid();
			ppid = getppid();
			cout << "Fork 5. I'm the child " << pid << ", my parent is " << ppid << "." << endl;
		}
		else {
			cout << "Error!" << endl;
		}
	}
	return 0;
}