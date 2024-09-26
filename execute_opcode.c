#include "monty.h"
#include <string.h>

/**
 * execute_opcode - Decodes and executes the opcode
 * @stack: Double pointer to the stack
 * @opcode: The opcode to execute
 * @line_number: The current line number in the bytecode file
 * @arg: The argument for the opcode
 */
void execute_opcode(stack_t **stack, char *opcode,
		unsigned int line_number, char *arg)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL || !isdigit(*arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
