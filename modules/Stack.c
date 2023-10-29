#include <stdio.h>
#include <stdlib.h>
#include "libgraph.h"

Stack *create_stack()
{
   Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->first = NULL;
    stack->last = NULL;

    return stack;
}

Cell_stack *create_cell_stack(int data)
{
    Cell_stack *new_cell = (Cell_stack *)malloc(sizeof(Cell_stack));

    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->data = data;

    return new_cell;
}

int pop(Stack *stack)
{
    Cell_stack *navpointer = stack->first;

    int data = stack->first->data;

    stack->first = stack->first->next;

    free(navpointer);

    return data;
}

void push(Stack *stack, int data)
{
    Cell_stack *new_cell = create_cell_stack(data);

    if (stack->first == NULL)
    {
        stack->last = new_cell;
    }
    else
    {
        new_cell->next = stack->first;
        stack->first->prev = new_cell;
    }

    stack->first = new_cell;
}

int empty_stack(Stack *stack)
{
    if(stack->first == NULL)
    {
        return 0;
    }
    
    return 1;
}

void print_stack(Stack *stack)
{
    Cell_stack *navpointer = stack->first;

    while (navpointer != NULL)
    {
        printf("%d\n", navpointer->data);
        navpointer = navpointer->next;
    }

    printf("\n");
}