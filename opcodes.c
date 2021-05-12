#include "monty.h"

/**
 * push - adds an element to the stack
 * @top: double pointer to the top of the stack
 * @n: element(data) to add to the stack
 * Return: void
 */
void push(stack_t **top, int n)
{
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		free_all(top);
	}
	if (!glob.selector)
	{
		if (!*top)
			new->prev = NULL;
		else
		{
			new->prev = *top;
			new->prev->next = new;
		}
		new->next = NULL;
		new->n = n;
		*top = new;
	}
	else
	{
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
		if (!top)
			*top = new;
		else
		{
			current = *top;
			while (current->prev)
				current = current->prev;
			new->next = current;
			current->prev = new;
		}
	}
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @head: double pointer pointing to the top of the stack
 * @line_number: index of argument/instructions
 * Return: void
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void) line_number;

	while (current)
	{
		printf("%d\n", current->n);
                current = current->prev;
        }
}
