#include "heap.h"
#include <stdlib.h>
#include <math.h>

void swap(int *, int, int);

int createMaxHeap(Heap *heap, int maxSize) {
    heap = (Heap *) malloc(sizeof(Heap));
    heap->arr = malloc(sizeof(int)*maxSize);

    if (heap == NULL || heap->arr == NULL) {
        return 0;
    }

    heap->maxSize = maxSize;
    heap->heapSize = 0;

    return 1;
}

int parent(int i) { return ceil(i / 2.0) - 1; }

int lChild(int i) { return i * 2 + 1; }

int rChild(int i) { return i * 2 + 2; }

void maxHeapfy(Heap *heap, int i) {
    int l = lChild(i);
    int r = rChild(i);
    int largest = i;

    if (l < heap->maxSize && heap->arr[l] > heap->arr[largest]) {
        largest = l;
    }

    if (r < heap->maxSize && heap->arr[r] > heap->arr[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(heap->arr, i, largest);
        maxHeapfy(heap, largest);
    }
}


void swap(int *arr, int i, int j) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void insertKey(Heap *heap, int x) {

    if (heap->heapSize >= heap->maxSize) {
        return;
    }

    heap->arr[heap->heapSize] = x;
    heap->heapSize++;

    int i = heap->heapSize - 1;
    int p = parent(i);

    while (p >= 0  && heap->arr[i] > heap->arr[p]) {
        swap(heap->arr, i, p);
        i = p;
        p = parent(i);
    }
}