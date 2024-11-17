#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("berk.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	
}
