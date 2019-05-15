#include <stdio.h>
#include <string.h>
#include "monty.h"


FILE *parse_open(char const *path)
{
	FILE *ret;

	ret = fopen(path, "r");
	if (ret == NULL)
		fail_special(OPEN, path, 0);
	return (ret);
}


int parse_line(FILE *file)
{
	static unsigned int line;
	char op[6];
	int val;
	void (*f)(stack_t **, unsigned int);

	line++;
	fscanf(file, "%*[ \t\v\n]");
	if (fscanf(file, "%1[#]", op) == 1)
	{
		fscanf(file, "%*[^\n]");
		return (main_list.size);
	}	
	if (fscanf(file, "%5[abcdefghijklmnopqrstuvwxyz]", op) != 1)
		return (-1);
	if (strcmp(op, "push") == 0)
	{
		if (fscanf(file, "%*[ \t\v]%d", &val) != 1)
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
