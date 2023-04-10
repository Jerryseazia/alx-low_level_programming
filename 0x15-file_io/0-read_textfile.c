#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the in the function
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t openn, readd, writee;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	openn = open(filename, O_RDONLY);
	readd = read(openn, buf, letters);
	writee = write(STDOUT_FILENO, buffer, r);

	if (openn == -1 || readd == -1 || writee == -1 || writee != r)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(openn);

	return (writee);
}
