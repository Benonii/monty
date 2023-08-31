#include "monty.h"

/**
 * pall - prints elements of a stack beginning at the top
 * @stack: The stack
 * @line_number: The line number
 *
 * Return: None
 */

void pstr(stack_t **stack, unsigned int line_number)
{
        stack_t *top = NULL;

        if (stack == NULL || *stack == NULL)
	{
		putchar(10);
                return;
	}
        top = *stack;
        while (top != NULL)
        {
		if (top->n == 0)
		{
			top = top->next;
			continue; }
                putchar(top->n);
                top = top->next;
        }
	putchar(10);
        (void) line_number;
        free(top);
}

