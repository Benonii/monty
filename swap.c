#include "monty.h"

/**
 * swap - swaps the top two elements
 * @stack: the stack
 * @line_number: The line swap was called on
 *
 * Return: None
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;

	exit (EXIT_SUCCESS);
}
