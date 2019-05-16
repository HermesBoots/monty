#include <stdio.h>
#include "monty.h"


/**
 * op_pchar - print the character at the top of the stack
 * @stack: unused
 * @line: current line number in the script file
 */
void op_pchar(stack_t **stack __attribute__((unused)), unsigned int line)
{
	int c;

	if (main_list.size < 1)
		fail("can't pchar, stack empty", line);
	c = list_front();
	if (c > 127 || c < 0)
		fail("can't pchar, value out of range", line);
	printf("%c\n", c);
}


/**
 * op_pstr - print the string at the top of the stack
 * @stack: unused
 * @line: unused
 */
void op_pstr(stack_t **stack, unsigned int line)
{
	long c;

	(void)stack, (void)line;
	if (main_list.size < 1)
	{
		putchar('\n');
		return;
	}
	c = list_front();
	while (c > 0 && c < 128)
	{
		putchar(c);
		c = list_next();
	}
	putchar('\n');
}
