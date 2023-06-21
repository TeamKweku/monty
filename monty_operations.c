#include "monty.h"
/**
 * monty_operations - function pointer that handles all monty
 * operations
 * @argv: array of arguments
 * @stack: pointer to stack to be manipulated
 * @line_number: line number
 *
 * Return: success or failure
 */
int monty_operations(unsigned int line_number, char **argv, stack_t **stack)
{
	int i;
	instruction_t operation[] = {{"pall", pall}, {"pint", pint},
		{"pop", pop_stack_element}, {"swap", swap}, {"add", stack_add},
		{"sub", stack_sub}, {"div", stack_div}, {"mul", stack_multi},
		{"mod", stack_mod}, {"pchar", print_char}, {"pstr", print_str},
		{"rotl", rotate1}, {"rotr", rotate2}, {NULL, NULL}};

	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(operation[i].opcode, argv[0]) == 0)
		{
			operation[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(*stack);
	opcode_error(line_number, argv[0]);
	return (EXIT_SUCCESS);
}
