#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "tda.h"
int compare(const void* a, const void* b){
	const Edge* A = (const Edge*) a;
	const Edge* B = (const Edge*) b;

	return A->color_diff - B->color_diff;
}

int main() {
	GraphTDA* g = load_image_to_graph("teste_dois_objetos.pgm");
	UnionFind* uf = create_uf(g->num_vertices);
	qsort(g->edges, g->num_edges, sizeof(Edge),compare);
//	printf("Vertices: %d\n", g->num_vertices);
//	printf("Arestas: %d\n", g->num_edges);
//	for(int i = 0; i < g->num_edges; i++)
//		printf("Aresta %d: %d-%d, color: %d\n", i, g->edges[i].u, g->edges[i].v, g->edges[i].color_diff);
	
	int num_componentes = g->num_vertices;

	for(int i = 0; i < g->num_edges; i++) {
    	if(find_set(uf, g->edges[i].u) != find_set(uf,g->edges[i].v)) {
        	union_set(uf, g->edges[i].u, g->edges[i].v);
        	num_componentes--;

		printf("Fusão no peso %d: Ilhas restantes: %d\n", g->edges[i].color_diff, num_componentes);
    }
}
	return 0;
}
