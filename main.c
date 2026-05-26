#include "graph.h"
#include <stdio.h>



int main() {
	GraphTDA* g = load_image_to_graph("lenna_p2.pgm");
	printf("Vertices: %d\n", g->num_vertices);
	printf("Arestas: %d\n", g->num_edges);
for(int i = 0; i < g->num_edges; i++)
		printf("Aresta %d: %d-%d, color: %d\n", i, g->edges[i].u, g->edges[i].v, g->edges[i].color_diff);
	
	return 0;
}
