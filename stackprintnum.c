#include <stdio.h>
#include "monty.h"


/**
 * op_pall - print all numbers in the stack
 * @stack: unused
 * @line: current line number in script file
 */
void op_pall(stack_t **stack __attribute__((unused)), unsigned int line)
{
	long result;

	if (main_list.size > 0)
	{
		result = list_front();
		while (result != LIST_DONE)
		{
			printf("%ld\n", result);
			result = list_next();
		}
	}
}


/**
 * op_pint - print the number on top of the stack
 * @stack: unused
 * @line: current line number in script file
 */
void op_pint(stack_t **stack __attribute__((unused)), unsigned int line)
{
	if (main_list.size < 1)
		fail("can't pint, stack empty", line);
	printf("%ld\n", list_front());
}
