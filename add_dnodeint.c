#include "monty.h"

/**
* add_dnodeint - add new node at beginning of dlistint_t
* @stack: head with the list
* @n: integers
* Return: adress of new element or null if fails
*/
stack_t *add_dnodeint(stack_t **stack, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(global.buffer);
		fclose(global.mfile);
		exit(EXIT_FAILURE);
	}

	(*new_node).n = n;
	(*new_node).next = *stack;
	(*new_node).prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (new_node);
}
