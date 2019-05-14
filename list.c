#include <stdlib.h>
#include "monty.h"


/**
 * list_front - get the top of the stack / front of the queue
 *
 * Return: value in front node
 */
long list_front(unsigned int line)
{
	if (main_list.size < 1)
		fail("can't pint, stack empty", line);
	if (main_list.mode == STACK)
	{
		main_list.cache = main_list.last;
		return (main_list.last->n);
	}
	main_list.cache = main_list.first;
	return (main_list.first->n);
}


/**
 * list_next - get the next node in the list after the last retrieval
 *
 * Return: value in next node
 */
long list_next(unsigned int line)
{
	if (main_list.cache == NULL)
		return (LIST_DONE);
	if (main_list.mode == STACK)
		main_list.cache = main_list.cache->prev;
	else
		main_list.cache = main_list.cache->next;
	if (main_list.cache == NULL)
		return (LIST_DONE);
	return (main_list.cache->n);
}


/**
 * list_pop - get the front node in the list and remove it from the list
 *
 * Return: value in the removed node
 */
long list_pop(unsigned int line)
{
	long ret;
	stack_t *node;

	if (main_list.size < 1)
		fail("can't pop an empty stack", line);
	if (main_list.mode == STACK)
	{
		ret = main_list.last->n;
		node = main_list.last->prev;
		node->next = NULL;
		free(main_list.last);
		main_list.last = node;
	}
	else
	{
		ret = main_list.first->n;
		node = main_list.first->next;
		node->prev = NULL;
		free(main_list.first);
		main_list.first = node;
	}
	if (main_list.size == 1)
	{
		main_list.first = NULL;
		main_list.last = NULL;
	}
	main_list.size--;
	return (ret);
}


/**
 * list_push - add a new node to the list with the given value
 * @n: value to add to the list
 */
void list_push(int n, unsigned int line)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fail_special(MEMORY, NULL, line);
	node->next = NULL;
	node->prev = main_list.last;
	node->n = n;
	if (main_list.last != NULL)
		main_list.last->next = node;
	if (main_list.first == NULL)
		main_list.first = node;
	main_list.last = node;
	main_list.size++;
}
