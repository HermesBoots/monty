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
	list_add(a + b);
}


/**
 * op_div - divide the top numbers on the stack and store the result
 * @stack: unused
 * @line: current line number in script file
 */
void op_div(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int a, b;

	if (main_list.size < 2)
		fail("can't div, stack too short", line);
	a = list_pop();
	if (a == 0)
		fail("division by zero", line);
	b = list_pop();
	list_add(b / a);
}


/**
 * op_mod - get the modulo of the items on top of the stack and store result
 * @stack: unused
 * @line: current line number in script file
 */
void op_mod(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int a, b;

	if (main_list.size < 2)
		fail("can't mod, stack too short", line);
	a = list_pop();
	if (a == 0)
		fail("division by zero", line);
	b = list_pop();
	list_add(b % a);
}


/**
 * op_mul - get the product of items on top of the stack and store the result
 * @stack: unused
 * @line: current line number in script file
 */
void op_mul(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int a, b;

	if (main_list.size < 2)
		fail("can't mul, stack too short", line);
	a = list_pop();
	b = list_pop();
	list_add(a * b);
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
	list_add(b - a);
}
