#include <stdlib.h>
#include "monty.h"


/**
 * list_add - add a new node to the top of the stack, even in queue mode
 * @n: value to add to the list
 */
void list_add(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fail_special(MEMORY, NULL, 0);
	node->n = n;
	node->next = main_list.first;
	node->prev = NULL;
	if (main_list.first != NULL)
		main_list.first->prev = node;
	if (main_list.last == NULL)
		main_list.last = node;
	main_list.first = node;
	main_list.size++;
}


/**
 * list_front - get the top of the stack / front of the queue
 *
 * Return: value in front node
 */
long list_front(void)
{
	main_list.cache = main_list.first;
	return (main_list.first->n);
}


/**
 * list_next - get the next node in the list after the last retrieval
 *
 * Return: value in next node
 */
long list_next(void)
{
	if (main_list.cache == NULL)
		return (LIST_DONE);
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
long list_pop(void)
{
	long ret;
	stack_t *node;

	ret = main_list.first->n;
	node = main_list.first->next;
	if (node != NULL)
		node->prev = NULL;
	free(main_list.first);
	main_list.first = node;
	if (main_list.size == 1)
	{
		main_list.first = NULL;
		main_list.last = NULL;
	}
	main_list.size--;
	return (ret);
}


/**
 * list_push - push a new node regarding the list mode
 * @n: value to add to the list
 */
void list_push(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fail_special(MEMORY, NULL, 0);
	node->n = n;
	if (main_list.mode == STACK)
	{
		node->next = main_list.first;
		node->prev = NULL;
		if (main_list.first != NULL)
			main_list.first->prev = node;
		main_list.first = node;
	}
	else
	{
		node->next = NULL;
		node->prev = main_list.last;
		if (main_list.last != NULL)
			main_list.last->next = node;
		main_list.last = node;
	}
	if (main_list.size == 0)
	{
		main_list.first = node;
		main_list.last = node;
	}
	main_list.size++;
}
