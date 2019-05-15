#include "monty.h"


/**
 * op_rotl - move item at the top of the stack to the bottom
 * @stack: unused
 * @line: unused
 */
void op_rotl(stack_t **stack, unsigned int line)
{
	enum list_modes mode;

	(void)stack, (void)line;
	if (main_list.size > 1)
	{
		mode = main_list.mode;
		main_list.mode = QUEUE;
		list_push(list_pop());
		main_list.mode = mode;
	}
}


/**
 * op_rotr - move item at the bottom of the stack to the top
 * @stack: unused
 * @line: unused
 */
void op_rotr(stack_t **stack, unsigned int line)
{
	(void)stack, (void)line;
	if (main_list.size > 1)
	{
		main_list.last->prev->next = NULL;
		main_list.first->prev = main_list.last;
		main_list.last->next = main_list.first;
		main_list.first = main_list.last;
		main_list.last = main_list.last->prev;
		main_list.first->prev = NULL;
	}
}
