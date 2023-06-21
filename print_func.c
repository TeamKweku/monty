#include "monty.h"
/**
 * print_char - function that checks for chars and
 * prints them out
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n < 128)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 *print_str - function that prints a string of chars
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		return;
	}
	while (current != NULL && (current->n > 0 && current->n < 128))
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
