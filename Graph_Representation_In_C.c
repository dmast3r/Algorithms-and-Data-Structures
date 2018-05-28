/* This representation is done using Adjacency List

vertex 1 [head-node] -> [next-node] -> ...... -> [last-node] -> null
vertex 2 ....

each vertex has a list of adjacent nodes called as adjancency list. An array of such lists is our graph.
*/

#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
	int dest; // dest represents the value of the node.
	struct AdjListNode *next;
};

// represents Adjacency List for each vertex. Each stores pointer to the head node. Which further chains till the NULL node.
struct AdjList {
	struct AdjListNode *head;
};

// The entire graph is an Array of Adjacency List
struct Graph {
	int vertices; // vertices represents the total number of vertices in the Graph.
	struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest) {
	struct AdjListNode *new_node = (struct AdjListNode *) malloc(sizeof (struct AdjListNode));
	new_node -> dest = dest;
	new_node -> next = NULL;
	return new_node;
}

struct Graph *createGraph(int vertices) {
	struct Graph *new_graph = (struct Graph *) malloc(sizeof (struct Graph));
	new_graph -> vertices = vertices;
	new_graph -> array = (struct AdjList *) malloc(vertices * sizeof(struct AdjList));

	// initialise to null the Head of each AdjList
	for(int i = 0; i < vertices; ++i)
		new_graph -> array[i].head = NULL;
	
	return new_graph;
}

// A utility function that adds a new edge between source and destination.
void addEdge(struct Graph *graph, int src, int dest) {
	struct AdjListNode *new_node = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
	new_node -> dest = dest;
	new_node -> next = graph -> array[src].head;
	graph -> array[src].head = new_node;

	// since graph is undirected add an edge between destination to source node as well.
	new_node = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
	new_node -> dest = src;
	new_node -> next = graph -> array[dest].head;
	graph -> array[dest].head = new_node;

	return;
}

void printGraph(struct Graph *graph) {
	for(int i = 0; i < graph -> vertices; ++i) {
		printf("Listing adjacent vertices of the vertex number: %d", i);
		printf("\nHead -> ");

		struct AdjListNode *crawl = graph -> array[i].head;
		while(crawl != NULL) {
			printf("%d -> ", crawl -> dest);
			crawl = crawl -> next; 
		}

		printf("NULL\n");
	}

}

int main(int argc, char const *argv[]) {
	
	// create a graph with 5 vertices
	int vertices = 5;
	struct Graph *graph = createGraph(vertices);

	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
	return 0;
}
