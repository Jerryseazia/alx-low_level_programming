#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates bytes for a buffer.
 * @file: The name of the buffer file.
 *
 * Return: the result.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes the file.
 * @fd: descriptor to be closed.
 */
void close_file(int fd)
{
	int j;

	j = close(fd);

	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies of content.
 * @argc: The number of arguments .
 * @argv: Pointer to arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is wrong -- 98.
 *              If file not exit - exit code 98.
 *              If file_to cannot be created - - 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, fo, ro, w;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	ro = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || ro == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		w = write(fo, buf, ro);
		if (fo == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		ro = read(from, buf, 1024);
		fo = open(argv[2], O_WRONLY | O_APPEND);

	} while (ro > 0);

	free(buf);
	close_file(from);
	close_file(fo);

	return (0);
}
