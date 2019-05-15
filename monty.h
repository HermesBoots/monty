#ifndef _MONTY_H_
#define _MONTY_H_


#include <stdio.h>


#define LIST_DONE (0x800000000L)


/**
 * enum list_modes - the modes the main list might be in
 * @QUEUE: the list uses a first in, first out model
 * @STACK: the list uses a last in, first out model
 */
enum list_modes
{
	STACK, QUEUE
};

/**
 * enum failures - the kinds of failures that need special message processing
 * @MEMORY: can't allocate memory
 * @OPCODE: file includes unknown opcode
 * @OPEN: can't open bytecode file
 */
enum failures
{
	ARGS, MEMORY, OPCODE, OPEN
};


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct List - structure to store information about a linked list
 * @cache: last node retrieved
 * @first: pointer to latest node
 * @last: pointer to earliest node
 * @size: number of nodes in list
 * @mode: whether to act like a stack or a queue
 */
struct List
{
	stack_t *cache;
	stack_t *first;
	stack_t *last;
	size_t size;
	enum list_modes mode;
} main_list;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* error handling */
void fail_special(enum failures kind, char const *extra, unsigned int line);
void fail(char const *message, unsigned int line);
char const *fail_line(unsigned int line);
void fail_main(unsigned char count, ...);

/* file parsing */
FILE *parse_open(char const *path);
int parse_line(FILE *file);

/* stack / queue handling functions */
void list_add(int n);
void list_free(void);
long list_front();
long list_next();
long list_pop();
void list_push(int n);

/* operation search function */
void (*find_op_func(char const *search))(stack_t **, unsigned int);

/* Monty language operations */
void op_add(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);


#endif
