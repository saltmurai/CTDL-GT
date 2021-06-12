#include <iostream>
using namespace std;
#define MAXV 100 //Maximum number of vertices

typedef struct edgenode
{
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV + 1]; // adjacency infog
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
    int directed;
} graph;

void initialize_graph(graph *g, bool directed) {
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for(i = 1; i <= MAXV; i++) {
        g->degree[i] = 0;
    }
    for(i = 1; i <= MAXV; i++) {
        g->edges[i] = nullptr;
    }
}

void insert_edge(graph *g, int x, int y, bool directed) {
    edgenode *p;
    p = new edgenode;
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
    if(!directed) {
        insert_edge(g, y, x, true);
    }
    else {
        g->nedges++;
    }
}

void read_graph(graph *g, bool directed) {
    int i;
    int m;
    int x, y;

    initialize_graph(g, directed);
    cin >> g->directed;
    cin >> m;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        insert_edge(g, x, y, directed);
    }
}



void print_graph(graph *g) {
    int i;
    edgenode *p;
    for(i = 1; i <= g->nvertices; i++) {
        cout << i;
        p = g->edges[i];
        while(p != nullptr) {
            cout << p->y;
            p = p->next;
        }
        cout << "\n";
    }
}


int main() {
    graph *g;
    read_graph(g, 0);
    return 0;
}