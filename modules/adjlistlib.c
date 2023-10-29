#include <stdio.h>
#include <stdlib.h>
#include "libgraph.h"


Graph *create_graph()
{
    Graph *new_graph = (Graph*)malloc(sizeof(Graph));

    new_graph->first = NULL;
    new_graph->last = NULL;

    return new_graph;
}

Vertex *create_vertex(int vertex)
{
    Vertex *new_vertex = (Vertex*)malloc(sizeof(Vertex));

    new_vertex->next = NULL;
    new_vertex->prev = NULL;
    new_vertex->adj = NULL;
    new_vertex->vertex = vertex;

    return new_vertex;
}

Cell *create_cell(int adjacent)
{
    Cell *new_cell = (Cell*)malloc(sizeof(Cell));

    new_cell->adjacent = adjacent;
    new_cell->next = NULL;
    new_cell ->prev = NULL;

    return new_cell;
}

Vertex *search_vertex(Graph *graph,int vertex)
{
    Vertex *aux = graph->first;
    
    while(aux != NULL)
    {
        if(aux->vertex == vertex)
        {
            return aux;
            break;
        }
        aux = aux->next;
    }
    return aux;
}

Vertex *add_vertex(Graph *graph,int vertex)
{
    Vertex *new_vertex = create_vertex(vertex);

    if(graph->first == NULL)
    {
        graph->first = new_vertex;
    }
    else
    {
        graph->last->next = new_vertex;
        new_vertex->prev = graph->last;
    }

    graph->last = new_vertex;

    return new_vertex;
}

int empty_graph(Graph *graph)
{
    if(graph->first == NULL)
    {
        return 0;
    }

    return 1;
}

int AddEdge(Graph *graph,int vertex, int adjacent)
{
    Vertex *aux = search_vertex(graph,vertex);
    
    if(aux == NULL)
    {
      aux = add_vertex(graph,vertex);  
    }

    Cell *new_cell = create_cell(adjacent);

    if(aux->adj == NULL)
    {
        aux->adj = new_cell;
    }
    else
    {
        new_cell->next = aux->adj;
        aux->adj->prev = new_cell;
        aux->adj = new_cell;
    }

    return vertex;
}

void remove_edges(Graph *graph,int vertex)
{
    Vertex *aux = graph->first;
    Cell *rmedge;

    while(aux != NULL)
    {
        rmedge = aux->adj;

        while(rmedge != NULL && rmedge->adjacent != vertex)
        { 
            rmedge = rmedge->next;
        }

        if(rmedge == NULL)
        {
           aux = aux->next; 
        }
        else
        {
            if(aux->adj->adjacent == rmedge->adjacent)
            {
                aux->adj = aux->adj->next;
                free(rmedge);
            }
            else if(rmedge->next == NULL)
            {
                rmedge->prev->next = NULL;
                free(rmedge);
            }
            else
            {
                rmedge->prev->next = rmedge->next;
                rmedge->next->prev = rmedge->prev;
                free(rmedge);
            }
        }
    }
}

Graph *RemoveVertex(Graph *graph,int vertex)
{
    Vertex *navpointer = search_vertex(graph,vertex);
    Cell *rmpointer;
    Cell *auxpointer;
    
    if(graph->first->vertex == navpointer->vertex)
    {
        graph->first = graph->first->next;
    }
    else if(graph->last->vertex == navpointer->vertex)
    {
        graph->last = graph->last->prev;
        graph->last->next = NULL;
    }
    else
    {
        navpointer->prev->next = navpointer->next;
        navpointer->next->prev = navpointer->prev;
    }
    
    rmpointer = navpointer->adj;

    while(rmpointer)
    {
        auxpointer = rmpointer;
        rmpointer = rmpointer->next;
        free(auxpointer);
    }

    free(navpointer);

    remove_edges(graph,vertex);

    return graph;
}

void PrintGraph(Graph *graph)
{
    Vertex *aux = graph->first;
    Cell *current;

    while(aux)
    {
        printf("\nV[%d]: ",aux->vertex);
        current = aux->adj;

        while(current)
        {
            printf("(%d)->",current->adjacent);
            current = current->next;
        }
        aux = aux->next;
    }

    printf("\n\n");
}