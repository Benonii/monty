#include "monty.h"
#include <string.h>

/**
 * main - entry point
 * @ac: number of arguments
 * @av: list of arguments
 *
 * Return: 0 if success, 1 if fail;
 */

int main(int ac, char **av)
{
	char line[100] = "", *token = NULL, *delim = " \n\t\r";
	int i, fd = 0;
	unsigned int l = 2;
	stack_t **stack = malloc(sizeof(stack_t));

	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
       		{"pint", pint},
		{"pop", pop},
       		{"swap", swap},
		{"add", add},
		{"nop", nop},
       		{"sub", sub}, };

	if (!stack)
	{
		fprintf(stderr, "Error: malloc failelure\n");
		return (EXIT_FAILURE);
	}
	*stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(stack);
		exit(EXIT_FAILURE); }
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(EXIT_FAILURE); }
		while (readline(fd, line, sizeof(line)) > 0)
		{
			token = strtok(line, delim);
			op[0] = token;
			token = strtok(NULL, delim);
			op[1] = token;
			i = 0;
			while (i < 8)
			{
				if (strcmp(funcs[i].opcode, op[0]) == 0)
				{
					funcs[i].f(stack, l);
					break;
				}
				i++;
			}
			if (i == 8)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", l, op[0]);
				free_stack(*stack);
				free(stack);
				l++;
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(*stack);
	free(stack);
	return (EXIT_SUCCESS); }
