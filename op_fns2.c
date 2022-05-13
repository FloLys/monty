#include "monty.h"
/**
 * pint - prints the last integer of the stack
 * @stack: stack top
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(global.buffer), fclose(global.mfile), free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	while (head->next != NULL)
		head = head->next;
	printf("%d\n", head->n);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack top
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int data;

	if (*stack == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(global.buffer), fclose(global.mfile), free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	while (head->next != NULL)
		head = head->next;

	data = head->n;
	head->n = head->prev->n;
	head->prev->n = data;
}
/**
 * nop - nothing
 * @stack: stack top
 * @line_number: line number
 */
void nop(__attribute__((unused)) stack_t **stack,
			__attribute__((unused)) unsigned int line_number)
{}
