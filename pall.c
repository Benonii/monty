#include "monty.h"

/**
 * pall - prints elements of a stack beginning at the top
 * @stack: The stack
 * @line_number: The line number
 *
 * Return: None
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
	(void) line_number;
}
