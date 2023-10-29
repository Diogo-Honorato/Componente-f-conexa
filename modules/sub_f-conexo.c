#include <stdio.h>
#include <stdlib.h>
#include "libgraph.h"

int verifica(Queue *list, int vertice)
{
    Cell_queue *aux = list->first;

    while (aux != NULL)
    {
        if (aux->data == vertice)
        {
            return 0;
            break;
        }
        else
        {
            aux = aux->next;
        }
    }

    return 1;
}

Queue *search_adjacent(Graph *grafo,int vertice)
{
    Queue *Conjunto = create_queue();

    Vertex *aux_vertice = grafo->first;

    Cell *aux_adj;

    while(aux_vertice != NULL)
    {
        aux_adj = aux_vertice->adj;

        while(aux_adj != NULL)
        {
            if(aux_vertice->vertex != vertice && aux_adj->adjacent == vertice)
            {
                enqueue(Conjunto,aux_vertice->vertex);
            }
            aux_adj = aux_adj->next;
        }

        aux_vertice = aux_vertice->next;
    }

    return Conjunto;
}

Queue *TransitivoDireto(Graph *grafo, int vertice_inicial)
{

    Queue *Fecho_direto = create_queue();

    Queue *Fecho_direto_aux = create_queue();

    Vertex *aux_vertice;

    Cell *aux_adj;

    int vertice_atual;



    enqueue(Fecho_direto, vertice_inicial);

    enqueue(Fecho_direto_aux, vertice_inicial);



    while (empty_queue(Fecho_direto_aux))
    {

        vertice_atual = dequeue(Fecho_direto_aux);
        aux_vertice = search_vertex(grafo, vertice_atual);
        
        if(aux_vertice != NULL)
        {
            aux_adj = aux_vertice->adj;
        }
        else
        {
            aux_adj = NULL;
        }

        while (aux_adj != NULL)
        {
            if (verifica(Fecho_direto, aux_adj->adjacent))
            {
                enqueue(Fecho_direto, aux_adj->adjacent);

                enqueue(Fecho_direto_aux, aux_adj->adjacent);
            }

            aux_adj = aux_adj->next;
        }
    }
    return Fecho_direto;
}

Queue *TransitivoInverso(Graph *grafo,int vertice_inicial)
{
    Queue *Fecho_inverso = create_queue();

    Queue *Fecho_inverso_aux = create_queue();
    
    Queue *Conjunto_vertice;

    Cell_queue *aux_conjunto;
    
    int vertice_atual;


    enqueue(Fecho_inverso,vertice_inicial);
    enqueue(Fecho_inverso_aux,vertice_inicial);

    while(empty_queue(Fecho_inverso_aux))
    {
        vertice_atual = dequeue(Fecho_inverso_aux);
        Conjunto_vertice = search_adjacent(grafo,vertice_atual);
        aux_conjunto = Conjunto_vertice->first;

        while (aux_conjunto != NULL)
        {
            if (verifica(Fecho_inverso, aux_conjunto->data))
            {
                enqueue(Fecho_inverso, aux_conjunto->data);

                enqueue(Fecho_inverso_aux, aux_conjunto->data);
            }

            aux_conjunto = aux_conjunto->next;
        }

    }

    return Fecho_inverso;
}

Queue *Intercessao(Queue *queue_1,Queue *queue_2)
{
    Queue *Conjunto_inter = create_queue();
    Cell_queue *aux_q1 = queue_1->first;
    Cell_queue *aux_q2;

    while (aux_q1 != NULL)
    {
        aux_q2 = queue_2->first;

        while(aux_q2 != NULL)
        {
            if(aux_q1->data == aux_q2->data)
            {
                enqueue(Conjunto_inter,aux_q1->data);
                break;
            }
            aux_q2 = aux_q2->next;
        }

        aux_q1 = aux_q1->next;
    }
    
    return Conjunto_inter;
}

Queue *Vertice(Graph *grafo)
{
    Vertex *navpointer = grafo->first;
    Queue *Vertices = create_queue();

    while(navpointer != NULL)
    {
        enqueue(Vertices,navpointer->vertex);
        navpointer = navpointer->next;
    }

    return Vertices;
}

void SubGrafoF_Conexo(Graph *grafo)
{
    Queue *V = Vertice(grafo);
    Queue *Fecho_direto;
    Queue *Fecho_inverso;
    Queue *F_conexo;
    Graph *New_graph;
    int vertice;
    int remove;
    int contador = 1;

    while(empty_queue(V))
    {   
        vertice = dequeue(V);

        Fecho_direto = TransitivoDireto(grafo,vertice);
        Fecho_inverso = TransitivoInverso(grafo,vertice);

        F_conexo = Intercessao(Fecho_direto,Fecho_inverso);

        printf("\nComponente f-conexa %d:\n",contador);
        print_queue(F_conexo);
        contador++;

        while(empty_queue(F_conexo))
        {
            remove = dequeue(F_conexo);

           New_graph = RemoveVertex(grafo,remove);
        }

        V = Vertice(New_graph);
    }
}