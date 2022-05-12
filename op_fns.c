#include "monty.h"

/**
* push - adds new element at the top of the stack
* @stack: stack top
* @line_number: line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *token2;
	int i = 0, n = 0;

	token2 = strtok(NULL, " "); /*next token*/
	if (token2 == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (token2[0] == '-' && token2[1])
		i = 1;

	for (; token2[i] != '\n' && token2[i] != '\0'; i++)
	{
		if (token2[i] < '0' || token2[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = atoi(token2);
		add_dnodeint(stack, n);
	}
/*
*	struct StackNode* stackNode = newNode(data);
*    stackNode->next = *root;
*    *root = stackNode;
*    printf("%d pushed to stack\n", data);
*/
}
/**
* pall - prints all values of the stack starting from top
* @stack: stack top
* @line_number: line number
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *aux = *stack;

	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
