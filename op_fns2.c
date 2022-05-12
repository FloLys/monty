#include "monty.h"
/**
 * pint - prints the last integer of the stack
 * @stack: stack top
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *list;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	list = *stack;
	while (list->next != NULL)
		list = list->next;
	printf("%d\n", list->n);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack top
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *list = *stack;
	int data;

	if (*stack == NULL || list->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (list->next != NULL)
		list = list->next;

	data = list->n;
	list->n = list->prev->n;
	list->prev->n = data;
}
/**
 * nop - nothing
 * @stack: stack top
 * @line_number: line number
 */
void nop(__attribute__((unused)) stack_t **stack,
			__attribute__((unused)) unsigned int line_number)
{}
