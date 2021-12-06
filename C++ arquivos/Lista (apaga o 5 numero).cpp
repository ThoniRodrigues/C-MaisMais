#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct _node {
	int x;
	struct _node *prox;
} node;

typedef struct _lista {
	int num;
	node *head;
	node *tail;
} lista;

lista cria(lista lst, int x) {
	node *aux;
	aux = (node*)malloc(sizeof(node));
	lst.num = x;
	lst.head = aux;
	lst.tail = aux;
	return lst;

}

lista insereFIM(lista lst, int x) {
	node *aux;
	aux = (node*)malloc(sizeof(node));
	aux->x = x;
	aux->prox = NULL;
	lst.tail->prox = aux;
	lst.tail = aux;
	return lst;

}

void mostra(lista lst) {
	node *aux;
	aux = lst.head->prox;
	while (aux != NULL) {
		cout << aux->x << "\n";
		aux = aux->prox;
			
	}

}

lista insereINI(lista lst, int x) {
	node *aux;
	aux = (node*)malloc(sizeof(node));
	aux->prox = lst.head;
	lst.head->x = x;
	lst.head = aux;
	return lst;
}

lista removeINI(lista lst) {
	node *aux;
	cout << "\n Elemento removido: " << lst.head->prox->x << "\n";
	aux = lst.head;
	lst.head = lst.head->prox;
	free(aux);
	return lst;
}


lista removeFIM(lista lst) {
	node *aux;
	node *ant;
	aux = lst.head->prox;
	while (aux->prox != NULL) {
		ant = aux;
		aux = aux->prox;
	}
	
	cout << "\n Elemento removido: " << aux->x << "\n";
	
	lst.tail = ant;
	lst.tail->prox = NULL;
	free(aux);
	return lst;

}
int main() {

	lista Lista1, Lista2;
	int x;
	
	Lista1 = cria(Lista1, 1);
	Lista2 = cria(Lista2, 2);
	for (int i=0; i<5; i++){
		cout << "\n Digite o valor " << i+1 << ": ";
		cin >> x;
		Lista1 = insereFIM(Lista1, x);
	}
	
	mostra(Lista1);
	Lista1 = removeFIM(Lista1);
	mostra(Lista1);
	cout << "\n";
	
	for (int i=0; i<5; i++){
		cout << "\n Digite o valor " << i+1 << ": ";
		cin >> x;
		Lista2 = insereINI(Lista2, x);
	}
	
	mostra(Lista2);
	Lista2 = removeINI(Lista2);
	mostra(Lista2);
	cout << "\n";
	system("pause");
	
}

