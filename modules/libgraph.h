#ifndef LIBGRAPH_H
#define LIBGRAPH_H

typedef struct Cell
{
    int adjacent;
    struct Cell *next;
    struct Cell *prev;

}Cell;

typedef struct Vertex
{
    int vertex;
    struct Vertex *next;
    struct Vertex *prev;
    Cell *adj;

}Vertex;

typedef struct Graph
{
    Vertex *first;
    Vertex *last;

}Graph;

//Queue

typedef struct Cell_queue
{
    int data;
    struct Cell_queue *next;
    struct Cell_queue *prev;
    
}Cell_queue;

typedef struct Queue
{
    Cell_queue *first;
    Cell_queue *last;

}Queue;

//stack

typedef struct Cell_stack
{
    int data;
    struct Cell_stack *next;
    struct Cell_stack *prev;

}Cell_stack;

typedef struct Stack
{
    Cell_stack *first;
    Cell_stack *last;

}Stack;
  




//adjlistlib.c

Graph *create_graph();

Vertex *create_vertex(int vertex);

Cell *create_cell(int adjacent);

Vertex *search_vertex(Graph *graph,int vertex);

Vertex *add_vertex(Graph *graph,int vertex);

int empty_graph(Graph *graph);

int AddEdge(Graph *graph,int vertex, int adjacent);

void remove_edges(Graph *graph,int vertex);

Graph *RemoveVertex(Graph *graph,int vertex);

void PrintGraph(Graph *graph);


//ReadFile.c
int line_counter(const char *file);

int **edge_file(const char *file_name);

//EdgeFileReader.c

void EdgeFileReader(Graph *graph,const char *file_name);

//GraphPng.c

void command_prompt();

void make_png_file(FILE *file_in,FILE *file_out);

void GraphPng(const char *file_name);

//Queue.c

Queue *create_queue();

Cell_queue *create_cell_queue(int data);

int enqueue(Queue *queue,int data);

int dequeue(Queue *queue);

int empty_queue(Queue *queue);

void print_queue(Queue *queue);

//stack.c

Stack *create_stack();

Cell_stack *create_cell_stack(int data);

int pop(Stack *stack);

void push(Stack *stack, int data);

int empty_stack(Stack *stack);

void print_stack(Stack *stack);


#endif