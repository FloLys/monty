#include "monty.h"
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
