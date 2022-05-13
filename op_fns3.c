#include "monty.h"

/**
* add - adds the top two elements of the stack
* @stack: stack top
* @line_number: line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int result = 0;

	if (*stack == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.buffer), fclose(global.mfile), free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	while (head->next->next != NULL)
		head = head->next;

	result = head->n + head->next->n;
	head->n = result;
	pop(stack, line_number);
}
/**
* pop - deletes the node at index of a linked list
* @stack: stack top
* @line_number: line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack, *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(global.buffer), fclose(global.mfile), free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	if (aux->next == NULL)
	{
		free(aux);
		*stack = NULL;
		global.pop = 1;
	}
	else
	{
		while (aux->next->next)
			aux = aux->next;
		tmp = aux->next;
		aux->next = NULL;
		free(tmp);
	}
}
