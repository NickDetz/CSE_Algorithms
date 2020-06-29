//Collaborated with Tristan Fong
#include <iostream>
#include <array>
using namespace std;
//Making structures for code
struct Graph {
    //int array[]
    int V;
    struct AdjList* array;
};

struct AdjList {
  struct AdjListNode *head;
};

struct AdjListNode {
    int weight;
    int destination;
    struct AdjListNode* next;
};
//Made a structure to the list
struct AdjListNode* newAdjListNode(int destination, int weight) {
// Memory allocation of adjusting Nodes
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
//making new pointers pointing to specific weights
    newNode->next = NULL;
    newNode->destination = destination;
    newNode->weight = weight;

    return newNode;
};
// Creating Graph structure for main below
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    graph->V = V;
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
};
// function add an edge to the graph expanding it
void addEdge(struct Graph* graph, int source, int destination, int weight) {
    struct AdjListNode* newNode =newAdjListNode(destination, weight);
    newNode->next = graph->array[source].head;
    graph->array[source].head = newNode;
    newNode = newAdjListNode(source, weight);
    newNode->next = graph->array[destination].head;
    graph->array[destination].head = newNode;
}
//   struct MinHeapNodeQueue
//      int v;
//      int key;
//Structures for the various heaps i made
struct MinHeapNode {
    int v;
    int key;
};
struct MinHeap {
    int size;
    int *pos;
    int capacity;
    struct MinHeapNode **array;
};
struct MinHeapNode* newMinHeapNode(int v, int key) {

    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
};

struct MinHeap* createMinHeap(int capacity) {

    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;

};
// made a swap fucntion for the Heaps
void swapMinHeapNode(struct MinHeapNode** A, struct MinHeapNode** B) {
    struct MinHeapNode* temp = *A;
    *A = *B;
    *B = temp;
}
// Making the Checks for the structures of my heaps
void heapify(struct MinHeap* minHeap, int index) {
    int minNode, leftNode, rightNode;
    minNode = index;
    rightNode = (2 * index + 2);
    leftNode = (2 * index + 1);
//Checking the Left
    if (minHeap->array[leftNode]->key < minHeap->array[minNode]->key && leftNode < minHeap->size )
        minNode = leftNode;

//Checking the Right
    if (minHeap->array[rightNode]->key < minHeap->array[minNode]->key && rightNode < minHeap->size)
        minNode = rightNode;


//Index Check or code give out more numbers than needed
    if (minNode != index) {

        MinHeapNode *minNodeNode = minHeap->array[minNode];
        MinHeapNode *indexNode = minHeap->array[index];
        minHeap->pos[minNodeNode->v] = index;
        minHeap->pos[indexNode->v] = minNode;
        swapMinHeapNode(&minHeap->array[minNode], &minHeap->array[index]);
        heapify(minHeap, minNode);  }}
// Making the Empty function to delete all heaps
bool isEmpty(struct MinHeap* minHeap) {
    bool empty = false;
    if (minHeap->size == 0)
        empty = true;
    return empty;
}
// Making the extracting using the lowest value to do bottom up approach
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;
    struct MinHeapNode* rootNode = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[rootNode->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    heapify(minHeap, 0);
    return rootNode;
};
// Function for Decoding the Keys that were given in the previous function
void decKey(struct MinHeap* minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;
    while (minHeap->array[i]->key < minHeap->array[(i - 1)/2]->key) {
        minHeap->pos[minHeap->array[i]->v] = ((i - 1)/2);
        minHeap->pos[minHeap->array[(i - 1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1)/2]);
        i = (i - 1) / 2;
    }
}

//breaks code
// Cutting the Graph to reduce run time
//void Cut(struct Graph* Vector){
//    int V = graph;
//    int parentNode
//
//    int i = 0
//    for (i = 1; i < V; ++i) {
//        minHeap->pos[i] = i;
//        key[i] = 214747;
//        parentNode[i] = -1;
//        minHeap->array[i] = newMinHeapNode(i, key[i]);
//    }
//}
// read the decode
//void decKey(struct MinHeap* minHeap, v, key) {
//    int i = minHeap->pos[v];
//    minHeap->array[i]->key = key;
//    while (minHeap->array[i]->key < minHeap->array[i/2]->key) {
//        minHeap->pos[minHeap->array[i]->v] = ((i - 1)/2);
//        minHeap->pos[minHeap->array[(i - 1)/2]->v] = i;
//        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1)/2]);
//        i = i / 2;
//    }

void Prim(struct Graph* graph) {
    // Intoduce the nodes with the 3D vector
    int V = graph->V;
    int parentNode[V];
    int key[V];
    // Make a Minheap structure to temporarily hold values
    struct MinHeap* minHeap = createMinHeap(V);
    int i = 0;
    for (i = 1; i < V; ++i) {
        minHeap->pos[i] = i;
        key[i] = 2147483647;
        parentNode[i] = -1;
        minHeap->array[i] = newMinHeapNode(i, key[i]);
    }
    //Creating Keys now for values of the Heap
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;
    minHeap->size = V;
//check for heap not being empty
    while (!isEmpty(minHeap)) {
      //Making Structs, 1 heap for in que data and 1 to adjust the Node
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct AdjListNode* crawl = graph->array[u].head;
        while (crawl != NULL) {
          //Using the crawl function to get to the destination
            int v = crawl->destination;
            if (crawl->weight < key[v] && (minHeap->pos[v] < minHeap->size)) {
                key[v] = crawl->weight;
                parentNode[v] = u;
                decKey(minHeap, v, key[v]);
            }

            crawl = crawl->next;
        }
    }

    for (i = 1; i <= V - 1; i++)
        cout << parentNode[i] << endl;
}

void print(int array[], int j) {

    int i = 0;

    for (i = 1; i < j; ++i)
        cout << array[i] << endl;
}
//Start code here
int main() {
  // Introducing interger variables that will be needed (might need more/less
    int vertices, edges, x, y, z;
    cin >> vertices;
    struct Graph* graph = createGraph(vertices);
    cin >> edges;
    //putting values toward the edges for my 3 d matrix
    for (int i = 0; i < edges; i++) {
        cin >> x;
        cin >> y;
        cin >> z;
        addEdge(graph, x, y, z);
    }
// Go to Prim with 3D vector
    Prim(graph);

    return 0;
}
