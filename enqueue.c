#include "monty.h"
/**
 * enqueue - function that add item at the rear end of
 * stack
 * @stack: contains address of top most item in stack
 * @token: int
 * @line_number: line number
 *
 * Return: success or failure
 */
int enqueue(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *current;

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (_is_digit(token) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		mem_alloc_error();
	new_node->n = atoi(token);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL || stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	return (EXIT_SUCCESS);
}
