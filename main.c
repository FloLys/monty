#include "monty.h"

/**
* main - monty bytecode interpreter with opcode functions
* @argc: arg counter
* @argv: arguments
*/
int main(int argc, char **argv)
{
	char *buffer = NULL; /*buffer with getline*/
	size_t bufsize = 1024; /*buffer size capacity*/
	char **index = NULL; /*tokenized opcodes list*/
	stack_t *top = NULL; /*top of the stack*/
	FILE *mfile;
	unsigned int line_number = 1;

	if (argc != 2) /*no file or more than 1 argument in program call*/
	{
		fprintf(stderr, "USAGE: monty file");
        exit(EXIT_FAILURE);
	}

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) /*malloc failed*/
    {
		fprintf(stderr, "Error: malloc failed");
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
		index = token_to_av(buffer, " \n\t");
		if (index == NULL) /*list empty*/
			exit(EXIT_FAILURE);
		
		opcode_call(buffer)(&top, line_number);
		free(index);
	}
	free(buffer);
	buffer = NULL;
	fclose(mfile);
	return (EXIT_SUCCESS);
}
