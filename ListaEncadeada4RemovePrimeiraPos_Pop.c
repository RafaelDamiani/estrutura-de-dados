//Fun��o que remove primeira posicao
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);

List* createList() {
	List* list = (List*) malloc(sizeof(List)); // malloc(sizeof(List)) - serve para alocar um espa�o na memoria

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

void printList(List* list) {
	
	if (isEmpty(list)) {
		printf("Lista vazia\n");
		return;
	}
	
	Node* pointer = list->head;
	
	while (pointer != NULL) {
		printf ("%d ", pointer->data.id);
		pointer = pointer->next;
	}
	
	printf ("\n");
}

bool isEmpty(List* list) {
	return (list->size == 0);
}

void pop(List* list) {
	if (!isEmpty(list)){
		Node* pointer = list->head; //aloca o primeiro registro na variavel pointer
		list->head = pointer->next; //aloca o registro seguinte como o principal/primeiro
		free(pointer); //limpa o primeiro registro
		list->size--; //decrementa a lista (reduz o tamanho)
	}	
}

int main() {
	List* l = createList();
	
	DataNode data;
	data.id = 5;
	push(l, data);
	
	data.id = 9;
	push(l, data);
	
	data.id = 7;
	push(l, data);
	
	data.id = 3;
	push(l, data);
	
	data.id = 8;
	push(l, data);	
	
	printList(l);
	pop(l);
	printList(l);
	
}
