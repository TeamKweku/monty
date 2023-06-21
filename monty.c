#include "monty.h"
/**
 * main - entry point of the program
 * @argc: number of command line arguments
 * @argv: array storing command line arguments
 *
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
		handle_args_error();
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error_msg(argv[1]);
	exec_monty_script(fp);
	if (fp != NULL)
		fclose(fp);
	return (0);
}
