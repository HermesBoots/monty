#include <stdio.h>
#include <string.h>
#include "monty.h"


/**
 * parse_open - open the file to parse and check errors
 * @path: path to file
 *
 * Return: stream of newly-opened file
 */
FILE *parse_open(char const *path)
{
	FILE *ret;

	ret = fopen(path, "r");
	if (ret == NULL)
		fail_special(OPEN, path, 0);
	return (ret);
}


/**
 * parse_line - parse the next line from the Monty file
 * @file: stream of file to check
 *
 * Return: size of stack or -1 at end of file
 */
int parse_line(FILE *file)
{
	static unsigned int line = 1;
	char op[65];
	int val;
	void (*f)(stack_t **, unsigned int);

	skip_space(file, &line);
	if (fscanf(file, "%1[#]", op) == 1)
	{
		fscanf(file, "%*[^\n]");
		return (main_list.size);
	}
	if (fscanf(file, "%64[abcdefghijklmnopqrstuvwxyz]", op) != 1)
	{
		if (fscanf(file, "%64s", op) != 1)
			return (-1);
		fail_special(OPCODE, op, line);
	}
	if (strcmp(op, "push") == 0)
	{
		if (fscanf(file, "%*[ \t\v]%d", &val) != 1)
			fail("usage: push integer", line);
		if (fscanf(file, "%1[^ \t\v\n]", op) != 0)
			fail("usage: push integer", line);
		op_push((stack_t **)&val, line);
		fscanf(file, "%*[^\n]");
		return (main_list.size);
	}
	f = find_op_func(op);
	if (f == NULL)
		fail_special(OPCODE, op, line);
	f(NULL, line);
	fscanf(file, "%*[^\n]");
	return (main_list.size);
}


/**
 * skip_space - skip the leading white space before an input line
 * @file: file to read from
 * @line: pointer to line number that gets incremented with each \n
 */
void skip_space(FILE *file, unsigned int *line)
{
	char c[2];

	while (fscanf(file, "%1[\n]", c) == 1)
	{
		++*line;
		fscanf(file, "%*[ \t\v]");
	}
}
