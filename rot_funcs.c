#include "monty.h"
/**
 * rotl - function that rotates top element to last
 * and second to first
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	current = *stack;
	new = (*stack)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	current->next->next = NULL;
	current->next->prev = current;
	new->prev = NULL;
	*stack = new;
}

/**
 * rotr - function that rotates last item to top
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}
