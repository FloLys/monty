#include "monty.h"

/**
* main - monty bytecode interpreter with opcode functions
* @argc: arg counter
* @argv: arguments
* Return: 0
*/
int main(int argc, char **argv)
{
	size_t bufsize; /*buffer size capacity*/
	stack_t *top = NULL; /*top of the stack*/
	char *token1 = NULL;
	unsigned int line_number = 0;
	void (*fn)(struct stack_s **, unsigned int);

	if (argc != 2) /*no file or more than 1 argument in program call*/
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	global.mfile = fopen(argv[1], "r+");
	if (global.mfile == NULL) /*file could not open*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(global.buffer);
		fclose(global.mfile);
		exit(EXIT_FAILURE);
	}

	while (getline(&global.buffer, &bufsize, global.mfile) != -1)
	{
		line_number++;
		token1 = strtok(global.buffer, " \t\n");
		if (token1 == NULL || token1[0] == '#')
			continue;
		fn = opcode_call(token1);
		if (fn == NULL) /*function not found, null return*/
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token1);
			free(global.buffer);
			fclose(global.mfile);
			exit(EXIT_FAILURE);
		}
		else /*execute*/
			fn(&top, line_number);
	}
	free(global.buffer);
	fclose(global.mfile);
	free_dlistint(top);
	return (EXIT_SUCCESS);
}
