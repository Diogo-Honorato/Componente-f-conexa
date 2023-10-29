#include <stdio.h>
#include <stdlib.h>
#include "modules/libgraph.h"
#include "modules/f_conexo.h"

int main()
{
   Graph *G = create_graph();

   EdgeFileReader(G,"testes/grafo.txt");

   SubGrafoF_Conexo(G);

}