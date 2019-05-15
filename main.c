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
	list_free();
	return (EXIT_SUCCESS);
}


/**
 * list_free - free all nodes in the list
 */
void list_free(void)
{
	if (main_list.size < 1)
		return;
	main_list.last = main_list.first->next;
	free(main_list.first);
	while (main_list.last != NULL)
	{
		main_list.first = main_list.last;
		main_list.last = main_list.first->next;
		free(main_list.first);
	}
	main_list.first = NULL;
	main_list.last = NULL;
	main_list.size = 0;
}
