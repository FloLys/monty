#include "monty.h"

/**
* opcode_call - searches a struct and calls a function with a function pointer
* @op_sel: opcode selector to compare
* @stack: stack
* @line_number: line number
* Return: function used and counter
*/
void (*opcode_call(char *op_sel))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_fn[] = {
		{"push", push},
/*		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},*/
		{'\0', NULL}
	};

	int i;

	for (i = 0; op_fn[i].opcode != NULL; i++)
	{
		if (*op_sel == *op_fn[i].opcode)
			return (op_fn[i].f);
	}
/*	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_sel);*/
	exit(EXIT_FAILURE);
}
