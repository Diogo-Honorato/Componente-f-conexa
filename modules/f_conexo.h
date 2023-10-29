#ifndef F_CONEXO_H
#define F_CONEXO_H
#include "libgraph.h"

//sub_f_conexo.c

int verifica(Queue *list,int vertice);

Queue *search_adjacent(Graph *grafo,int vertice);

Queue *TransitivoDireto(Graph *grafo,int vertice_inicial);

Queue *TransitivoInverso(Graph *grafo,int vertice_inicial);

Queue *Intercessao(Queue *queue_1,Queue *queue_2);

Queue *Vertice(Graph *grafo);

void SubGrafoF_Conexo(Graph *grafo);

#endif