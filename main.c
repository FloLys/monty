#include "monty.h"

void push(struct stack_t **stack, unsigned int line_number)
{
	if (top == MAX - 1) // Checking Array is full or not
		printf("Overflow\n");
	else
	{
		top += 1; // top = top + 1
		stack[top] = line_number;
	}
	env = _getenv("PATH");
	if (env[0] == '\0')
		exit(EXIT_FAILURE);
	path = token_to_av(env, ":");
	if (path == NULL)
		exit(EXIT_FAILURE);
	buffer = (char *)_calloc(bufsize, sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	return;
}
