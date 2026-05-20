#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 100

int	main(void)
{
	int			fd;
	int			i;
	static char	buffer[BUFFER_SIZE];

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("FIle couldn't be opened \n");
	}
	else
	{
		printf("File is opened \n");
	}
	read(fd, buffer, sizeof(buffer) - 1);
	printf("1st call: %s \n", buffer);
	read(fd, buffer, sizeof(buffer) - 1);
	printf("2nd call: %s \n", buffer);
	read(fd, buffer, sizeof(buffer) - 1);
	printf("3rd call: %s \n", buffer);
	read(fd, buffer, sizeof(buffer) - 1);
	printf("3rd call: %s \n", buffer);
	return (0);
}
