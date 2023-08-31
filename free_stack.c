#include "monty.h"

/**
 * free_stack - Frees a stack and its elements.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
        stack_t *temp;

        while (stack != NULL)
        {
                temp = stack;
                stack = stack->next;
                free(temp);
        }
}
