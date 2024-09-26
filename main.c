#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *opcode = NULL, *arg = NULL;
	size_t len = 1024;

	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, len, file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");

		if (opcode && opcode[0] != '#')
			execute_opcode(&stack, opcode, line_number, arg);
	}

	free(line);
	fclose(file);
	return (0);
}
