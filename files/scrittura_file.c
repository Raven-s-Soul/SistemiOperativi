#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	char msg[] = "Ciao!";

	int fd = open("pippo.txt", O_CREAT | O_TRUNC | O_WRONLY , S_IRWXU );

	write(fd, msg , strlen(msg));

	close(fd);
	return 0;
}
