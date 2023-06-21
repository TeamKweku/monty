#include "monty.h"
/**
 * pall - function that prints elments in stack
 * @stack: pointer ot stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;

	current_node = *stack;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pop_stack_element - fuction that deletes top element in stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pop_stack_element(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current_node = *stack;
	*stack = (*stack)->next;
	free(current_node);
}

/**
 * push_stack_item - function that add item at top of stack
 * @stack: contains address of top most item in stack
 * @token: int
 * @line_number: line number
 * Return: success or failure
 */
int push_stack_item(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *new_item;

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
	if (stack == NULL)
		exit(EXIT_FAILURE);
	new_item= malloc(sizeof(stack_t));
	if (new_item == NULL)
		mem_alloc_error();
	new_item->n = atoi(token);
	new_item->next = NULL;
	new_item->prev = NULL;
	if (*stack == NULL)
		*stack = new_item;
	else
	{
		new_item->next = *stack;
		(*stack)->prev = new_item;
		(*stack) = new_item;
	}
	return (EXIT_SUCCESS);
}

/**
 * pint - function that prints top elment in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * swap - function that swaps top two elements
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current = (*stack)->next;
		(*stack)->next = current->next;
		current->next = *stack;
		*stack = current;
	}
}
