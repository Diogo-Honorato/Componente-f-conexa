#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libgraph.h"

void command_prompt()
{
    int result = system("neato -Tpng Graph.dot -o Graph.png");
    
    if (result == 0) 
    {
        printf("\nGraph.png file created successfully\n\n");
    } 
    else 
    {
        printf("\nError creating .png file\n\n");
    }
}

void make_png_file(FILE *file_in,FILE *file_out)
{
    char make_graph[50];
    char *verification;
    int position,tam;

    fprintf(file_out,"digraph G{\n");
    fprintf(file_out,"rankdir=LR;\nsize=6;\nratio=expand;\n");
    while(fgets(make_graph,50,file_in) != NULL)
    {
        verification = strchr(make_graph,' ');

        position = verification - make_graph;

        tam = strlen(make_graph);

        if(make_graph[position] == ' ')
        {
            for(int i = 0; i < position; i++)
            {
                fprintf(file_out,"%c",make_graph[i]);
            }

            fprintf(file_out,"->");
            
            for(int i = position + 1; i < tam ; i++)
            {
                fprintf(file_out,"%c",make_graph[i]);
            }
        }
    }

    fprintf(file_out,"}");
}

void GraphPng(const char *file_name)
{
    FILE *file_in;
    FILE *file_out;


    file_in = fopen(file_name,"r");
    file_out = fopen("Graph.dot","w");

    if(file_in == NULL)
    {
        printf("\nERROR FILE OPEN: file_in\n\n");
        exit(0);
    }
    else if(file_out == NULL)
    {
        printf("\nERROR FILE OPEN: file_out\n\n");
        exit(0);
    }

    make_png_file(file_in,file_out);


    fclose(file_in);
    fclose(file_out);

    command_prompt();

    return;
}