#include <stdio.h>
#include "monty.h"


static FILE *file;


void parse_open(char const *path)
{
	file = fopen(path, "r");
	if (file == NULL)
		fail_special(OPEN, path, 0);
}


int parse_line(void)
{
	static unsigned int line;
	char op[6];
	int result, val;
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
