#include <stdio.h>
#include <stdlib.h>
#include "tda.h"


UnionFind* create_uf(int num_elements){
	UnionFind* uf= malloc(sizeof(UnionFind));
	uf->parent = malloc(num_elements * sizeof(int));
	uf->nivel = malloc(num_elements* sizeof(int));
	for(int i = 0; i < num_elements; i++){
		uf->parent[i] = i;
		uf->nivel[i] = 0;
	}
	uf->num_elements = num_elements;
	return uf;
}	

int find_set(UnionFind* uf, int i){
	if(uf->parent[i] == i){
		return i;
	}
	int raiz = find_set(uf,uf->parent[i]);
	uf->parent[i] = raiz;
	return raiz;
}

void union_set(UnionFind* uf, int i,int j){

	i = find_set(uf,i);
	j = find_set(uf,j);
	
	
	if(i == j){
		return;
	}

	if(uf->nivel[i] < uf->nivel[j]){
		uf->parent[i] = j;
	}else if(uf->nivel[j] < uf->nivel[i]){
		uf->parent[j] = i;
	}else{
		uf->parent[i] = j;
		uf->nivel[j]++;
	}
}

void free_uf(UnionFind* uf){
	free(uf->parent);
	free(uf->nivel);
	free(uf);
}
