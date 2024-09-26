#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack
 * @line_number: the current line number in the bytecode file (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
