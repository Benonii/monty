#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: The stack
 * @line_number: The line add was called on
 *
 * Return: None
 */

void div(stack_t **stack, unsigned int line_number)
{
        stack_t *top;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        top = *stack;
        top->next->n /= top->n;
        pop(stack, line_number);
}

