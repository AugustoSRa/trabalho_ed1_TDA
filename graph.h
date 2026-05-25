#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u;          
    int v;             
    int color_diff;     
} Edge;

typedef struct {
    int num_vertices;  
    int num_edges;     
    Edge* edges;     
} GraphTDA;

GraphTDA* load_image_to_graph(const char* file_path);

void free_graph(GraphTDA* g);

#endif
