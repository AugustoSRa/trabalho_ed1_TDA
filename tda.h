#ifndef TDA_H
#define TDA_H
// Definição da estrutura do motor matemático (Union-Find)
typedef struct {
    int* parent;   // Vetor que guarda o índice do 'líder' de cada elemento
    int* nivel;    // Vetor que guarda a altura da árvore de cada grupo
    int num_elements; // Quantidade total de elementos no universo
} UnionFind;

// Primitivas topológicas fundamentais
UnionFind* create_uf(int num_elements);
int find_set(UnionFind* uf, int i);
void union_set(UnionFind* uf, int i, int j);
void free_uf(UnionFind* uf);

// Função orquestradora que vamos implementar no main ou tda.c
// Esta função percorrerá as arestas e extrairá os dados de persistência
void extrair_persistencia_0d(int num_pixels, int num_arestas, void* arestas);


#endif
