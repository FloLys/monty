#include "monty.h"

/**
* main - monty bytecode interpreter with opcode functions
* @argc: arg counter
* @argv: arguments
* Return: 0
*/
int main(int argc, char **argv)
{
	char *buffer = NULL; /*buffer with getline*/
	size_t bufsize; /*buffer size capacity*/
	stack_t *top = NULL; /*top of the stack*/
	FILE *mfile;
	char *token1 = NULL;
	unsigned int line_number = 1;
	void (*fn)(struct stack_s **, unsigned int);

	if (argc != 2) /*no file or more than 1 argument in program call*/
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	mfile = fopen(argv[1], "r+");
	if (mfile == NULL) /*file could not open*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &bufsize, mfile) != -1)
	{
		line_number++;
		token1 = strtok(buffer, " \n\t");
		fn = opcode_call(token1);
		if (fn == NULL) /*function not found, null return*/
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token1);
			exit(EXIT_FAILURE);
		}
		else /*execute*/
		{
			fn(&top, line_number);
		}
	}
	free(buffer);
/*	buffer = NULL;*/
	fclose(mfile);
	return (EXIT_SUCCESS);
}
