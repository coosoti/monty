#include "monty.h"


/**
 * free_stack - deallocates memory allocated to stack_t ds
 * @top: double pointer pointing to the stack's top
 */

void free_stack(stack_t **top)
{
	stack_t *current;

	while (*top)
	{
		current = *top;
		*top = (*top)->prev;
		free(current);
	}
}

/**
 * free_all - free memory
 * @top: double pointer pointing to the stack's top
 */

void free_all(stack_t **top)
{
	free_stack(top);
	free(glob.buffer);
	fclose(glob.instruction);
	exit(EXIT_FAILURE);
}
