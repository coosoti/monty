#include "monty.h"

/**
 * pint - print value on top of the stack then newline
 * @stack: double pointer to the top of the stack
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.qs_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
