#include "monty.h"

struct global glob;

/**
 * main - entry level - interpreter for Monty ByteCodes files
 * @ac: number of arguments
 * @av: arguments(strings)
 * Return: 0 for success, EXIT_FAILURE for failure
 */

int main(int ac, char **av)
{
	stack_t *top = NULL;
	size_t size;
	char *line, *n;
	unsigned int i = 0;

	glob.selector = 0;
	glob.buffer  = NULL;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glob.instruction = fopen(av[1], "r");
	if (glob.instruction == NULL)
	{
		printf("Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&glob.buffer, &size, glob.instruction) != -1)
	{
		i++;
		line = strtok(glob.buffer, "\r \t\n");
		if (line[0] == '#')
			continue;
		if (!strcmp(line, "push"))
		{
			n = strtok(NULL, "\r \t\n");
			push(&top, str_to_int(&top, n, i));
			continue;
		}
		execute(line, i, &top);
	}

	free_stack(&top);
	free(glob.buffer);
	fclose(glob.instruction);
	return (0);
}

/**
 * execute - confirm and execute instruction
 * @line: instruction
 * @i: index of the arguments
 * @top: double pointer pointing to the stack's top
 * Return: 1 on success
 */

int execute(char *line, unsigned int i, stack_t **top)
{
	static instruction_t codes[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int j = 0;

	while (codes[j].opcode)
	{
		if (!strcmp(codes[j].opcode, line))
		{
			codes[j].f(top, i);
			return (1);
		}
		j++;
	}
	printf("L%u: unknown intruction %s\n", i, line);
	free_all(top);
	return (1);
}

/**
 * str_to_int - convert string to int
 * @top: double pointer pointing to the stack's top
 * @i: index of line argument
 * @n: data (string)
 * Return: int or free_all in called
 */

int str_to_int(stack_t **top, char *n, unsigned int i)
{
	int num = 1;
	int j = 0;

	if (n[0] == '-')
		j = 1;
	while (n[j])
	{
		if (!isdigit(n[j]))
		{
			printf("L%u: usage: push integer\n", i);
			free_all(top);
		}
		j++;
	}
	num *= atoi(n);
	return (num);
}
