#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * main - entry point, execute Monty code
 * @argc: number of command-line arguments
 * @argv: vector of command-line arguments
 *
 * Return: EXIT_SUCCESS normally, EXIT_FAILURE if error occurs
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
		fail_special(ARGS, NULL, 0);
	file = parse_open(argv[1]);
	while (parse_line(file) != -1)
		;
	fclose(file);
	return (EXIT_SUCCESS);
}
