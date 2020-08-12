#include <stdio.h>
#include "monty.h"


/**
 * op_queue - convert the stack to a queue
 * @stack: unused
 * @line: unused
 */
void op_queue(stack_t **stack, unsigned int line)
{
	(void)stack, (void)line;
	main_list.mode = QUEUE;
}


/**
 * op_push - push a value onto the stack
 * @file: script file to read argument from
 * @line: current line number in script file
 */
void op_push(FILE *file, unsigned int line)
{
	char buf[2] = {'\0'};
	int val;

	if (fscanf(file, "%*[ \t\v]%d", &val) != 1)
		fail("usage: push integer", line);
	if (fscanf(file, "%1[^ \t\v\n]", op) != 0)
		fail("usage: push integer", line);
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
		fail("can't pop an empty stack", line);
	list_pop();
}


/**
 * op_stack - convert the queue to a stack
 * @stack: unused
 * @line: unused
 */
void op_stack(stack_t **stack, unsigned int line)
{
	(void)stack, (void)line;
	main_list.mode = STACK;
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
	list_add(a);
	list_add(b);
}
