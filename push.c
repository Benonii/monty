#include "monty.h"


/**
 * push - pushes an item to the top of the stack
 * @stack: the stack
 * @line_number: The line number the push command was on
 *
 * Return: None
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (op[1] == NULL)
	{
		fprintf(stderr, "L%d: usage push integer\n", line_number);
		return;
	}

	temp->n = atoi(op[1]);
	temp->prev = NULL;
	temp->next = NULL;

	if (*stack == NULL)
		*stack = temp;
	else
	{
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}
