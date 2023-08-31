#include "monty.h"

/**
 * pint - prints the integer at the top of the stack
 * @stack: The stack
 * @line_number: The line pint was called on
 *
 * Return: None
 */

void pchar(stack_t **stack, unsigned int line_number)
{
        stack_t *top = NULL;

        if (stack == NULL || *stack == NULL)
        {
                fprintf(stderr, "L%d: can't pint, stack empty", line_number);
                exit (EXIT_FAILURE);
        }

        top = *stack;
        putchar(top->n);
	putchar(10);
}
