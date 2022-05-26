#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
	int pipefds[2];
	pipe(pipefds);
	
	pid_t pid = fork();
	
	if(pid > 0) {
		int len;
		char buff[1024];				
		
		close(pipefds[1]);
	
		while((len = read(pipefds[0], buff, 1024)));
		
		close(pipefds[0]);
		
		strncat(buff, " Hi!\n", 5);
		
		FILE* fptr = fopen("output_text.txt", "w");
		
		fprintf(fptr, buff, 1024);
		
		fclose(fptr);
	}
	else {
		const char *str = "Hi daddy, I`m your child!";
		
		close(pipefds[0]);
		
		write(pipefds[1], str, strlen(str) + 1);
			
		close(pipefds[1]);
	}
}

