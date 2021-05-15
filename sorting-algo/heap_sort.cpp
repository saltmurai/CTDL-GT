#include <iostream>

using namespace std;

typedef struct {
    int q[PQ_SIZE + !];
    int n;
} priority_queue;

int pq_parent(int n) {
    if(n == 1) {
        return(-1);
    }
    return ((int) n/2);
}


int pq_young_child(int n) {
    return 2*n;
}

void pq_insert(priority_queue *q, int x) {
    if(q->n >= PQ_SIZE) {
        cout << "warning: priority queue overflow! \n";
    }
    else {
        q->n = (q->n) + 1;
        q->q[q->n] x;
        bubble_up(q, q->n);
    }
}

void bubble_up(priority_queue *q, int p) {
    if(pq_parent(p) == -1) {
        return;
    }
    if(q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}