#include "monty.h"
/**
 * addition - function that adds two values on stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: nothing
 */
void stack_add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		total  = (*stack)->next->n + (*stack)->n;
		(*stack)->next->n = total;
		pop_stack_element(stack, line_number);
	}
}

/**
 * stack_div - function that divides top 2 elements in stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void stack_div(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		total  = (*stack)->next->n / (*stack)->n;
		(*stack)->next->n = total;
		pop_stack_element(stack, line_number);
	}
}

/**
 * mult - multiplies  top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void stack_multi(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		total  = (*stack)->next->n * (*stack)->n;
		(*stack)->next->n = total;
		pop_stack_element(stack, line_number);
	}
}

#include "monty.h"
/**
 * stack_mod- function that calculates remainder of
 * top 2 elements in stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: nothing
 */
void stack_mod(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		total = (*stack)->next->n % (*stack)->n;
		(*stack)->next->n = total;
		pop_stack_element(stack, line_number);
	}
}

/**
 * subtraction - subtracts top 2 elements in stack
 * @stack: pointer
 * @line_number: line number
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		total  = (*stack)->next->n - (*stack)->n;
		(*stack)->next->n = total;
		pop_stack_element(stack, line_number);
	}
}
