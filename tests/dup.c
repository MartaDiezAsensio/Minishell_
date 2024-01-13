
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int	fd = open("dup.txt", O_WRONLY);

	if (fd < 0)
		printf("Error opening the file\n"); 

	int	copy_fd = dup2(fd, 1);

	write(copy_fd, "This will be output to the file named dup.txt\n", 46);
	write( fd, "This will also be output to the file named dup.txt\n", 51);
	printf("hello\n");
}