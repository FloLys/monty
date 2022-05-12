#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

extern struct stack_t stack;

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global_s - global variables
* @mfile: file
* @buffer: buffer
* @pop: pop
*/
typedef struct global_s
{
FILE *mfile;
char *buffer;
int pop;
} global_t;
global_t global;

int main(int argc, char **argv);
void (*opcode_call(char *op_sel))(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **stack, const int n);
void free_dlistint(stack_t *head);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(__attribute__((unused)) stack_t **stack,\
__attribute__((unused)) unsigned int line_number);

#endif
