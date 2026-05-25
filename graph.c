#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"


GraphTDA* load_image_to_graph(char* path){
  FILE* file = fopen(path, "r");
  
  
  char format[3];
  
  if(format[0] != 'P' || format['] != '2'){
    fclose(file);
    return NULL;
  }
  
  int width, height, max_color;
  if (fscanf(file), "%d %d". &width, &height) != 2){
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
    
    int max_edges = (width-1) * height + (height - 1) * width;
    
    
    
  


