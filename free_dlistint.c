#include "monty.h"

/**
* free_dlistint - frees a dlistint_t list
* @head: head with the list
*/
void free_dlistint(stack_t *head)
{
	stack_t *aux;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
