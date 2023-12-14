typedef struct maxHeap {
    int *arr;
    int maxSize;
    int heapSize;
} Heap;

int createMaxHeap(Heap *, int);
void maxHeapfy(Heap *, int);
int parent(int);
int lChild(int);
int rChild(int);
int removeMax(Heap *);
void increaseKey(Heap *, int, int);
int getMax(Heap *);
int curSize(Heap *);
void deleteKey(Heap *, int);
void insertKey(Heap *, int);


