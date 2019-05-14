#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * fail_special - print error messages that don't fit the usual pattern
 * @kind: which unusual error to print
 * @extra: extra string used by this error type
 */
void fail_special(enum failures kind, char const *extra)
{
	switch (kind)
	{
	case MEMORY:
		fail_main(1, "Error: malloc failed");
		break;
	case OPCODE:
		fail_main(3, fail_line(), "unknown instruction ", extra);
		break;
	case OPEN:
		fail_main(2, "Error: Can't open file ", extra);
	}
}


/**
 * fail - print an error message in the usual style
 * @message: the message to print after the line number
 */
void fail(char const *message)
{
	fail_main(2, fail_line(), message);
}


/**
 * fail_line - return the current line number for use in error messages
 *
 * Return: string consisting of "L" followed by line number then ": "
 */
char const *fail_line(void)
{
	static char buffer[14] = {'L', '\0'};
	int count;

	count = snprintf(&buffer[1], 10, "%d", main_list.ops);
	buffer[count + 1] = ':';
	buffer[count + 2] = ' ';
	buffer[count + 3] = '\0';
	return (buffer);
}


/**
 * fail_main - print a complete error message
 * @count: number of strings that comprise the whole message
 */
void fail_main(unsigned char count, ...)
{
	va_list args;

	va_start(args, count);
	while (count > 0)
		fprintf(stderr, "%s", va_arg(args, char *));
	exit(EXIT_FAILURE);
}
