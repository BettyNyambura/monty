#include "monty.h"
var_global_t var_global;

/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (read_file(av[1], &stack) != 0)
	{
		fprintf(stderr, "Error: Unable to read the file %s\n", av[1]);
		free_dlistint(stack);
		return (EXIT_FAILURE);
	}

	free_dlistint(stack);
	return (EXIT_SUCCESS);
}
