#include<stdio.h>
#include<stdlib.h>
#include"libgraph.h" 

Queue *create_queue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->first = NULL;
    queue->last = NULL;

    return queue;
}

Cell_queue *create_cell_queue(int data)
{
    Cell_queue *new_cell = (Cell_queue*)malloc(sizeof(Cell_queue));
    
    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->data = data;
    
    return new_cell;
}

int enqueue(Queue *queue,int data)
{
    Cell_queue *new_cell = create_cell_queue(data);

    if(queue->first == NULL)
    {
        queue->first = new_cell;
    }
    else
    {
        queue->last->next = new_cell;
        new_cell->prev = queue->last;
    }

    queue->last = new_cell;

    return data;
}

int dequeue(Queue *queue)
{
    Cell_queue *dequeue = queue->first;

    queue->first = queue->first->next;

    int data = dequeue->data;

    free(dequeue);

    return data;
}

int empty_queue(Queue *queue)
{
    if(queue->first == NULL)
    {
        return 0;
    }

    return 1;
}

void print_queue(Queue *queue)
{
    Cell_queue *navpointer = queue->first;

    while(navpointer)
    {
        printf("%d ",navpointer->data);
        navpointer = navpointer->next;
    }
    printf("\n");
}