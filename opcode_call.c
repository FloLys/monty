#include "main.h"

/**
* opcode_call - searches a struct and calls a function with a function pointer
* @op_sel: opcode to compare
* Return: function used and counter
*/
void (*opcode_call(char *op_sel))(stack_t **stack, unsigned int line_number)
{
	instruction_t array[] = {
		{"push", push},
		{"pall", pall},
		{'\0', NULL}
	};

	int i;

	for (i = 0; array[i].opcode != NULL; i++)
	{
		if (op_sel == *array[i].opcode)
			return (array[i].f);
	}
	perror("L<line_number>: unknown instruction <opcode>\n");
	exit(EXIT_FAILURE);
	return;
}
