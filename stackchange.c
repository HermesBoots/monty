#include <stdio.h>
#include "monty.h"


/**
 * op_push - push a value onto the stack
 * @stack: pointer to value to push
 * @line: unused
 */
void op_push(stack_t **stack, unsigned int line __attribute__((unused)))
{
	list_push(*(int *)stack);
}


/**
 * op_pop - remove and print the top value of the stack
 * @stack: unused
 * @line: current line number in script file
 */
void op_pop(stack_t **stack __attribute__((unused)), unsigned int line)
{
	if (main_list.size < 1)
		fail("can't pop on an empty stack", line);
	list_pop();
}


/**
 * op_swap - swap the top two values in the stack
 * @stack: unused
 * @line: current line number in script file
 */
void op_swap(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int a, b;

	if (main_list.size < 2)
		fail("can't swap, stack too short", line);
	a = list_pop();
	b = list_pop();
	list_push(a);
	list_push(b);
}
