#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define  MAX 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* stack operations */
int push_stack_item(char *token, stack_t **stack, unsigned int line_number);
void pop_stack_element(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_multi(stack_t **stack, unsigned int line_number);
void stack_mod(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);

/* error handling functions */
void handle_args_error(void);
void open_error_msg(char *fp);
void mem_alloc_error(void);
void opcode_error(int line, char *opcode);

/* string functions */
int _strcmp(char *str1, const char *str2);
int _strlen(const char *s);
int _is_digit(char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);

/* tokenizer functions */
size_t node_length(stack_t *head);
int is_string_empty(char *str, char *delim);
char **split_string(char *input_string, char *delimiter);
char *tokenizer(char **str_ptr, const char *delim);


#endif
