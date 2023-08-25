#include "monty.h"


/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on failure.
 */
#include "monty.h"
#include <ctype.h>  

int main(int argc, char *argv[])
{  
    FILE *file;
    char line[MAX_LINE_SIZE];
    stack_t *stack = NULL;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return (1);
    }

  

    if ((file = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return (1);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *opcode = strtok(line, " \t\n");
        execute_opcode(&stack, opcode);
    }

    fclose(file);
    return (0);
}
