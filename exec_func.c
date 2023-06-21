#include "monty.h"
/**
 * exec_monty_script - function executes monty scripts
 * @data: contains opcode to be executed
 *
 * Return: success or failure
 */
int exec_monty_script(FILE *data)
{
	stack_t *top = NULL;
	char **av, monty[MAX];
	int end, line = 0, change = 2;

	while (fgets(monty, MAX, data) != NULL)
	{
		line++;
		if ((_strlen(monty) == 1 && monty[0] == '\n') ||
				is_string_empty(monty, "\n\t\a\b ") == 1)
		{
			continue;
		}
		av = split_string(monty, " \n\a\t\b");
		if (_strcmp(av[0], "nop") == 0 || av[0][0] == '#')
		{
			frees(av);
			continue;
		}
		else if (_strcmp(av[0], "stack") == 0)
			change = 2;
		else if (_strcmp(av[0], "queue") == 0)
			change = 1;
		else if (_strcmp(av[0], "push") == 0 && change == 2)
			end = push_stack_item(av[1], &top, line);
		else if (_strcmp(av[0], "push") == 0 && change == 1)
			end = enqueue(av[1], &top, line);
		else
			end = monty_operations(line, av, &top);
		frees(av);
		if (end == EXIT_FAILURE)
			break;
	}
	free_stack(top);
	return (end);
}
