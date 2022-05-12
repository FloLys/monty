#include "monty.h"

/**
* opcode_call - searches a struct and calls a function with a function pointer
* @op_sel: opcode selector to compare
* Return: function used and counter
*/
void (*opcode_call(char *op_sel))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_fn[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{'\0', NULL}
	};

	int i = 0;

	for (i = 0; op_fn[i].opcode != NULL; i++)
	{
		if (op_sel != NULL && strcmp(op_sel, op_fn[i].opcode) == 0)
			return (op_fn[i].f);
	}
	return (op_fn[i].f);
}
