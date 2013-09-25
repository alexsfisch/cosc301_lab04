#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
        
	char *cmd[] = { "/bin/ls", "-ltr", ".", NULL };
        pid_t pid = fork();
	int status;
	if (pid<0) { 
		printf("%s\n","fork failed");
		return -1;
	}
	else if (pid==0) { //child
		printf("%s\n","child");
		if (execv(cmd[0], cmd) < 0) {
			fprintf(stderr, "execv failed: %s\n", strerror(errno));
	    	}
	}
	else { //parent
		waitpid(pid, &status, 0);
		printf("%s\n","child process has finished");
	}
    	return 0;
}

