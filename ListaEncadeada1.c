#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode {
	int id;
} DataNode;

typedef struct node {
	DataNode data;
	struct node* next;
} Node;

typedef struct list {
	int size;
	Node* head;
} List;

List* createList();

List* createList() {
	List* list = (List*) malloc(sizeof(List)); // malloc(sizeof(List)) - serve para alocar um espaço na memoria

	list->size = 5;
	list->head = NULL;
	
	return list;
}

int main() {
	List* lista = createList();
	printf ("%d", lista->size);
	
}
