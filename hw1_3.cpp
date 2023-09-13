#include<iostream>
#include<unistd.h>
#include<vector>
#include<string>
#include<cstring>
#include<fcntl.h>
#include<sys/wait.h>

#define MAX_LINE 80

using namespace std;

int main(void)
{
	int should_run = 1; 
	vector<string> arg;
	string tmp;
	vector<char*> argv_t;
	char **argv;
	char buf[80];
	int n;
	int argc;
	int mode;
	pid_t pid;
	bool has_and;

	while(should_run){
		cout<<"osh>";
		fflush(stdout);

		n = read(STDIN_FILENO, buf ,80);

		//arg = input command
		for(int i=0;i<n;i++){

			if(buf[i]==' '||i==n-1){ 

				if(tmp.size()>0) 
					arg.push_back(tmp);
				tmp = "";
			}
			else{
				tmp = tmp + buf[i];
			}
		}

		//argc = argument count
		argc = arg.size();
		//argv = argument value
		argv = new char*[argc+1]; 

		for(int i=0;i<argc;i++){
			argv[i]=new char[arg[i].size()];
			strcpy(argv[i], arg[i].c_str());
		}
		argv[argc] = new char;
		argv[argc] = NULL;

		for (int i = 0; i < argc; i++) {
			argv_t.push_back(strdup(argv[i]));
		}
		argv_t[argc] = new char;
		argv_t[argc] = NULL;

		char* argv_tt[argv_t.size()];
		for (int i = 0; i < argv_t.size()+1; i++) {
			argv_tt[i] = argv_t[i];
		}


		/*
		for (int i = 0; i < argv_t.size() + 1; i++) {
			cout << argv_tt[i];
		}cout << endl;
		*/
		/*
		* your code!
		* After reading user input, the step are:
		* (1) fork a child process using fork()
		* (2) the child process will invoke execvp()
		* (3) if command included &, parent will not invoke wait()
		* 
		cout << "argc: " << argc << endl;
		cout << "argv: " << *argv << endl;
		cout << "arg: ";
		for (int i = 0; i < arg.size(); i++) {
			cout << arg[i];
		}
		cout << endl;
		cout << "argv_t: ";
		for (int i = 0; i < argv_t.size(); i++) {
			cout << argv_t[i];
		}cout << endl;
		*/	
		
		string str = argv_t[0];
		if (str == "exit")
			should_run = 0;
	
		pid = fork();
		
		if (pid == 0) { //child process
			execvp(argv_t[0], argv_tt);
		}
		else if (pid > 0) { //parent process
			wait(NULL);
		}
		else {
			cout << "ERROR!" << endl;
		}

		arg.clear();
		argv_t.clear();

		for(int i=0;i<argc;i++){
			delete [] argv[i];
		}		
		delete argv;
	}
	return 0;
}
