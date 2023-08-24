#include "monty.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @av: list of arguments
 *
 * Return: 0 if success, 1 if fail;
 */

int main(int ac, char **av)
{
	char line[100] = "", *token = NULL, *op[2] = {NULL}, *delim = " ";
	int i = 0, fd = 0, j = 0;
	unsigned int l = 0;
	stack_t **stack = NULL;

	instruction_t funcs[] = {
		{"push", push}, };
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
			l++;
			token = strtok(line, delim);
			op[0] = token;
			token = strtok(NULL, delim);
			op[1] = token;

			while (j < (int) sizeof(funcs) / (int) sizeof(funcs[0]))
			{
				if (strcmp(funcs[j].opcode, op[0]) == 0)
				{
					funcs[j].f(stack, l);
					break; }
				i++; }
			fprintf(stderr, "L%d: unknown instruction %s\n", l, op[0]);
			exit(EXIT_FAILURE); }}
	return (EXIT_SUCCESS); }
