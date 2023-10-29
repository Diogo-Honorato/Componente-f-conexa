#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libgraph.h"

int line_counter(const char *file_name)
{
    FILE *file;
    int line_counter = 0;
    int num1,num2;

    file = fopen(file_name,"r");

    if(file == NULL)
    {
        printf("\nERROR FILE OPEN: EDGE\n\n");
        exit(0);
    }

    while(fscanf(file, "%d %d",&num1,&num2) == 2)
    {
        line_counter++;
    }

    fclose(file);

    return line_counter;   
}

int **edge_file(const char *file_name)
{
    FILE *file_txt;
    int i = 0;


    int number_connection_pairs = line_counter(file_name);
    
    int **edges = (int**)malloc(number_connection_pairs * sizeof(int*));


    for(int j = 0 ; j < number_connection_pairs ; j++)
    {
        edges[j] = (int *)malloc(2 * sizeof(int));
    }

    file_txt = fopen(file_name,"r");

    if(file_txt == NULL)
    {
        printf("\nERROR FILE OPEN: EDGE\n\n");
        exit(0);
    }

    while(fscanf(file_txt,"%d %d",&edges[i][0],&edges[i][1]) == 2)
    {
        i++;
    }

    fclose(file_txt);
    
    return edges;
}