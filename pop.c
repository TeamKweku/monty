#include "monty.h"
/**
 * pop_stack_element - fuction that deletes top element in stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pop_stack_element(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}
