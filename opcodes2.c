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
		dprintf(STDERR_FILENO,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * pop - removes the top element off the stack
 * @stack: double pointer to the top of stack
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (var.qs_len == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.qs_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(current);
	var.qs_len--;
}
