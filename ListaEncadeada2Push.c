//funcao que insere elemento no começo da lista - push
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
void push(List* list, DataNode data);

List* createList() {
	List* list = (List*) malloc(sizeof(List)); // malloc(sizeof(List)) - serve para alocar um espaço na memoria

	list->size = 5;
	list->head = NULL;
	
	return list;
}

void push(List* list, DataNode data) {
	Node* node = (Node*) malloc(sizeof(Node));
	
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
}

int main() {
	List* l = createList();
	
	DataNode data;
	data.id = 5;
	
	push(l, data);
	data.id = 9;
	push(l, data);
	
	printf ("%d %d", l->head->data.id, l->head->next->data.id);
}
