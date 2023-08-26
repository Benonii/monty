#include "monty.h"

/**
 * readline - custom readline, reads from the command line
 * @fd: file descriptor
 * @buffer: stores the input
 * @max_len: Max length
 *
 * Return: number of bytes read
 */

int readline(int fd, char *buffer, int max_len)
{
	int read_bytes = 0;
	char ch;

	while (read_bytes < max_len && read(fd, &ch, 1) == 1)
	{
		buffer[read_bytes++] = ch;
		if (ch == '\n')
			break; }
	return (read_bytes);
}
