#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct _node {
	int x;
	struct _node *prox;
} node;

node *head;
node *tail;

node* qaloca(){					// Aloca um nó
	node *aux;
	aux = (node*)malloc(sizeof(node));
	if (aux == NULL) {
		cout << "\n Erro de alocação.";
		exit(1);
	}
	return aux;
}

int qvazia(node *lst) {			// Verifica se a lista está vazia
	
	return ( lst->prox == NULL ? 1 : 0 );
}

node* criaq() { 				// Cria a fila vazia
	node *aux;
	aux = qaloca();
	head = aux;
	head->prox = NULL;
	tail = head;
	return head;

}

void q(node *lst, int x) { 		// Insere (queue) na fila (insere no fim)
	node *aux;
	aux = qaloca();
	aux->x = x;
	cout << "\n Elemento inserido: " << aux->x << "\n";
	aux->prox = NULL;
	tail->prox = aux;
	tail = aux;
	return ;

}

node* dq(node *lst) {			// Remove (dequeue) da fila (remove no inicio)
	node *aux;
	aux = lst;
	
	if (aux->prox == NULL) { 
		cout << "\n A fila está vazia. (retira)"; 
	} 
	else {
		aux= aux->prox;
		cout << "\n Elemento removido: " << aux->x << "\n";
		lst->prox = aux->prox;
		head = lst;
		if (head->prox == NULL) {
			tail = head;
			}
		free(aux);
	}
	return lst;
}

void mostraq(node *lst) {		// Mostra elementos da fila
	node *aux;
	aux = lst->prox;
	if (qvazia(lst)) {
		cout << "\n A fila esta vazia. (mostra)";
	}
	else {
		cout << "\n Fila: ";
		while (aux != NULL) {
			cout  << aux->x << "  ";
			aux = aux->prox;
		}
	}
	cout << "\n";
	return;
}

void qconsulta(node *lst) {		// Mostra o primeiro elemento da fila
	if(qvazia(lst)) {
		cout << "\n A fila esta vazia. (consulta)";
	}
	else {
		cout << "\n Primeiro elemento da fila: " << lst->prox->x ;
	}
	return;
}

void limpaq(node *lst) {		// Remove (dequeue) da fila (remove no inicio)
	node *aux;
	aux = lst;
	if (aux->prox == NULL) { 
			cout << "\n A fila está vazia. (limpa)"; 
	}
	else { 
		while (aux->prox != NULL) {
			aux= aux->prox;
			cout << "\n Elemento removido: " << aux->x << "\n";
			lst->prox = aux->prox;
			head = lst;
			if (head->prox == NULL) {
				tail = head;
				}
			free(aux);
		}
		cout << "\n A fila foi esvaziada."; 
	}
	return ;
}


int main() {
	
	node *fila;
	int x;
	fila = criaq();
	
	system("CLS");
	
	for (int i=0; i<5; i++){
		x = (i+1)*3;
		q(fila,  x);
	}
	mostraq(fila);
	qconsulta(fila);
	fila = dq(fila);
	mostraq(fila);
	x  = 33;
	q(fila, x);
	mostraq(fila);
	qconsulta(fila);
	fila = dq(fila);
	mostraq(fila);
	fila = dq(fila);
	mostraq(fila); 
	if (qvazia(fila)) {
		cout << "\n A fila esta vazia. (main) ";
	}
	for (int i=0; i<2; i++){
		x = (i+1) * 2;
		q(fila,  x);
	}
	mostraq(fila);
	limpaq(fila);
	mostraq(fila); 
	limpaq(fila);
	qconsulta(fila);
	mostraq(fila); 
	// destroi fila
	free(fila);
	system("pause");
	return 0;
	
}

