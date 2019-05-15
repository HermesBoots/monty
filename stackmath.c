#include "monty.h"


/**
 * op_add - add the two numbers on top of the stack and store the result there
 * @stack: unused
 * @line: current line number in script file
 */
void op_add(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int a, b;

	if (main_list.size < 2)
		fail("can't add, stack too short", line);
	a = list_pop();
	b = list_pop();
	list_push(a + b);
}


/**
 * op_sub - subtract the two top numbers on the stack and store the result
 * @stack: unused
 * @line: current line number in script file
 */
void op_sub(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int a, b;

	if (main_list.size < 2)
		fail("can't sub, stack too short", line);
	a = list_pop();
	b = list_pop();
	list_push(b - a);
}
