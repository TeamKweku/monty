#include "monty.h"
/**
 * frees - frees any used memory
 * @argv: pointer to memory to free
 */

void frees(char **argv)
{
	int i = 0;

	if (argv == NULL)
		return;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

/**
 * free_stack - frees memory of stack created
 * @head: pointer to head node
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	if (head == NULL)
		return;
	while (head != NULL)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}
