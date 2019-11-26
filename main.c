#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *line;
	char *line1;
	int fd;
	int fd1;
	int i;

	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[2], O_RDONLY);
	while (i < 2)
	{
		get_next_line(fd, &line);
		get_next_line(fd1, &line1);
		printf("%s\n%s\n", line, line1);
		free(line);
		free(line1);
		i++;
	}
	return(0);
}
