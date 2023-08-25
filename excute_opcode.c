#include "monty.h"
/**
 * execute_opcode - Executes the opcode based on the instruction.
 * @stack: Double pointer to the top of the stack.
 * @opcode: The opcode to be executed.
 */
void execute_opcode(stack_t **stack, char *opcode)
{
	int value;
	unsigned int line_number = 0;

	if (strcmp(opcode, "push") == 0)
	{
		opcode = strtok(NULL, " \t\n");
		if (opcode == NULL || !isdigit(*opcode))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(opcode);
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
