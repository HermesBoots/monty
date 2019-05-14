#ifndef _OPCODE_H_
#define _OPCODE_H_


#define NULL ((void *)0)


/**
 * struct TrieNode - a node in a trie structure
 * @data: an instruction_t describing the operation used by this node
 * @children: array of children, arranged alphabetically
 * @prefix: this node's prefix (longest string needed is "queue")
 * @length: length of the prefix string
 * @trie: the array of TrieNodes used by the opcode searching function
 */
struct TrieNode
{
	instruction_t data;
	struct TrieNode *children[26];
	char prefix[6];
	unsigned char length;
} trie[22] = {
	{{NULL, NULL}, {
		&trie[1], NULL, NULL, &trie[2], NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, &trie[3], &trie[6], NULL, &trie[7], &trie[14], &trie[15],
		&trie[18], NULL
	}, "", 0},
	{{"add", op_add}, {NULL}, "add", 3},
	{{"div", op_div}, {NULL}, "div", 3},
	{{NULL, NULL}, {
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, &trie[4], NULL, NULL, NULL, NULL, NULL, &trie[5], NULL
	}, "m", 1},
	{{"mod", op_mod}, {NULL}, "od", 2},
	{{"mul", op_mul}, {NULL}, "ul", 2},
	{{"nop", op_nop}, {NULL}, "nop", 3},
	{{NULL, NULL}, {
		&trie[8], NULL, &trie[9], NULL, NULL, NULL, NULL, NULL, &trie[10],
		NULL, NULL, NULL, NULL, NULL, &trie[11], NULL, NULL, NULL, &trie[12],
		NULL, &trie[13], NULL
	}, "p", 1},
	{{"pall", op_pall}, {NULL}, "all", 3},
	{{"pchar", op_pchar}, {NULL}, "char", 4},
	{{"pint", op_pint}, {NULL}, "int", 3},
	{{"pop", op_pop}, {NULL}, "op", 2},
	{{"pstr", op_pstr}, {NULL}, "str", 3},
	{{"push", op_push}, {NULL}, "ush", 3},
	{{"queue", op_queue}, {NULL}, "queue", 5},
	{{NULL, NULL}, {
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		&trie[16], NULL, NULL, NULL, NULL, NULL, &trie[17], NULL
	}, "rot", 3},
	{{"rotl", op_rotl}, {NULL}, "l", 1},
	{{"rotr", op_rotr}, {NULL}, "r", 1},
	{{NULL, NULL}, {
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, &trie[19], &trie[20], NULL,
		&trie[21], NULL
	}, "s", 1},
	{{"stack", op_stack}, {NULL}, "tack", 4},
	{{"sub", op_sub}, {NULL}, "ub", 2},
	{{"swap", op_swap}, {NULL}, "wap", 3}
};

#endif
