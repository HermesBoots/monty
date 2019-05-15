#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * op_nop - do nothing
 * @stack: unused
 * @line: unused
 */
void op_nop(stack_t **stack, unsigned int line)
{ (void)stack, (void)line; }


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
