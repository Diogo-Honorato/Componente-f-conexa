#include<stdio.h>
#include<stdlib.h>
#include"libgraph.h"

void EdgeFileReader(Graph *graph,const char *file_name)
{
    int **matrix = edge_file(file_name);
    int Tam_matrix = line_counter(file_name);
    int i = 0;

    for(i = 0; i < Tam_matrix; i++)
    {
        AddEdge(graph,matrix[i][0],matrix[i][1]); 
    }
}
