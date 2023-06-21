#include "monty.h"
/**
 * handle_args_error - function that handles number of arguments
 * error
 */
void handle_args_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	 exit(EXIT_FAILURE);
}

/**
 * open_error_msg - function that handles opening of file
 * error
 * @fp: filename
 */
void open_error_msg(char *fp)
{
	fprintf(stderr, "Error: Can't open file %s\n", fp);
	exit(EXIT_FAILURE);
}


/**
 * mem_alloc_error - function that handles error in instance
 * of memory allocation
 */
void mem_alloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - function that prints error message with instance
 * of incompatible opcode
 * @line: line number
 * @opcode: string provided to function
 */
void opcode_error(int line, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	 exit(EXIT_FAILURE);
}
