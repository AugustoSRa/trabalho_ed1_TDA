#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"


GraphTDA* load_image_to_graph(char* file_path){
  FILE* file = fopen(file_path, "r");
  
  
  char format[3];
  fscanf(file, "%c %c", &format[0], &format[1]);
  
  if(format[0] != 'P' || format[1] != '2'){
    fclose(file);
    return NULL;
  }
  
  int width, height, max_color;
  if (fscanf(file, "%d %d", &width, &height) != 2){
    fprintf(stderr, "Error: \n");
    fclose(file);
    return NULL;
  }
  
  if (fscanf(file, "%d", &max_color) != 1) {
        fprintf(stderr, "Error:\n");
        fclose(file);
        return NULL;
   }

    int total_pixels = width * height;
    
    int* pixels = (int*) malloc(total_pixels * sizeof(int));
    
    for(int i=0; i< total_pixels; i++){
      fscanf(file, "%d", &pixels[i]);
    }
    fclose(file);
    int v_edges = (height - 1) * width;
    int h_edges = (width - 1) * height;
    int max_edges = v_edges + h_edges;
    GraphTDA* graph = malloc(sizeof(GraphTDA));
    graph->edges = malloc(max_edges * sizeof(Edge));
    graph->num_vertices = total_pixels;
    graph->num_edges = 0;
    for(int i = 0; i < height; i++){
	    for(int j = 0; j < width; j++) {
	    	int id = i * width + j;

		if(j < width - 1) {
			graph->edges[graph->num_edges].u = id;
			graph->edges[graph->num_edges].v = id + 1;
			graph->edges[graph->num_edges].color_diff = abs(pixels[id + 1] - pixels[id]);
			graph->num_edges++;
		}
		if(i < height - 1) {
			graph->edges[graph->num_edges].u = id;
			graph->edges[graph->num_edges].v = id + width;
			graph->edges[graph->num_edges].color_diff = abs(pixels[id + width] - pixels[id]);
			graph->num_edges++;

	    }
	    
    	}
    }
    free(pixels);
    return graph;
}

void free_graph(GraphTDA* g) {
	if(g) {
		if(g->edges) {
			free(g->edges);
		}
		free(g);
	}
}
	
