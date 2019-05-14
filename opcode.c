#include <stdio.h>
#include <string.h>
#include "monty.h"
#include "opcode.h"


/**
 * find_op_func - find the function that implements a named operation
 * @search: name of the operation to look for
 *
 * Return: pointer to operation function or NULL if operation unimplemented
 */
void (*find_op_func(char const *search))(stack_t **, unsigned int)
{
	size_t length, matched = 0;
	struct TrieNode *node;

	length = strlen(search);
	node = &trie[0];
	while (matched < length)
	{
		node = node->children[search[matched] - 'a'];
		if (node == NULL)
			return (NULL);
		if (strncmp(node->prefix, &search[matched], node->length) != 0)
			return (NULL);
		matched += node->length;
	}
	return (node->data.f);
}
