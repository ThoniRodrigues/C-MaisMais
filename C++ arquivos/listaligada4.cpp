#include <iostream>
#include <string>
#include <malloc.h>


using namespace std;

typedef struct {		// Estrutura aluno
	int RA;
	float prova;
	float trab;
} aluno;

typedef struct n_ {		// Estrutura node
	aluno dado;
	struct n_ *next;
} node;

typedef struct { 		// Estrutura lista
	char nome[10];
	node *ini;
	node *ult;
	int  tam;
} lista;

// Funções
lista crialista(int a);
lista insere(lista l, aluno a);
lista inserePrim(lista l, aluno p);
void imprime(lista l);
void imprimeRA(lista l);
void imprimeMedias(lista l);
lista removeRA(lista l, int ra);
lista removePrim(lista l);
lista removeUlt(lista l);
void pesquisaRA(lista l, int ra);
void mostraaluno(aluno a);
void menu(lista l1, lista l2);
void limpaBuffer();

int main() {
	
	
	int op = 1;
	lista lista1, lista2;
	aluno p;

	lista1 = crialista(1);
	cout << "\n Lista 1 - " << lista1.nome << " criada. \n";
	lista2 = crialista(2);
	
	cout << "\n Lista 2 - " << lista2.nome << " criada. \n";
	system("CLS");
	
	menu(lista1, lista2);
	

	
	system("pause");
	return (0);
}

lista crialista(int a){ 
	node *aux;
	lista l;
	cout << "\n Digite o nome da lista " << a << ": ";
	cin.getline(l.nome, 9);
	limpaBuffer();
	aux = (node*) malloc(sizeof(node));
	if(aux == NULL){
		cout << "Sem memoria disponivel!\n";
		exit(1);}
	l.ini = aux;
	l.ult  = aux;
	l.tam = 0;
	return l;
}

lista insere(lista l, aluno p) {
	node *aux;
	aux = (node*) malloc(sizeof(node));
	if(aux == NULL){
		cout << "Sem memoria disponivel!\n";
		exit(1);}
	aux->dado = p;
	aux->next = NULL;
	l.ult->next = aux;
	l.ult = aux;
	l.tam++;
	return l;
}

lista inserePrim(lista l, aluno p) {
	node *aux;
	aux = (node*) malloc(sizeof(node));
	if(aux == NULL){
		cout << "Sem memoria disponivel!\n";
		exit(1);}
	aux->dado = p;
	aux->next = l.ini->next;
	l.ini->next = aux;
	l.tam++;
	return l;
}

void imprime(lista l){
	node *aux;
	aux = l.ini->next;
	while (aux != NULL) {
		mostraaluno(aux->dado);
		aux = aux->next;
	}
	return;
}

void imprimeMedias(lista l){
	node *aux;
	aluno p;
	float media;
	int cont = 0;
	
	aux = l.ini->next;
	
	while (aux != NULL) {
		p = aux->dado;
		media = (p.prova + p.trab)/2;
		if (media >= 6) {
			mostraaluno(p);
			cont++;
		}
		
		aux = aux->next;
		
	}
	cout << "\n Total de alunos com media >= 6: " << cont;
	return;
}

void imprimeRA(lista l){
	node *aux;
	aluno a;
	int i = 1;
	aux = l.ini->next;
	
	while (aux != NULL) {
		a = aux->dado;
		cout << "\n RA " << i << ": " << a.RA;
		i++;
		aux = aux->next;
	}
	return;
}

void mostraaluno(aluno p){
	cout << "\n RA  do  aluno: " << p.RA;
	cout << "\n Nota da prova: " << p.prova;
	cout << "\n Nota da  ATPS: " << p.trab;
	cout << "\n Media : " << (p.prova + p.trab)/2 << "\n";
	return;
}

void menu (lista l1, lista l2) {
	aluno p;
	lista ls;
	int op, op1 = 99, op2 = 99, ra;
	
	do {
		system ("CLS");
		cout << "\n\n  Escolha a lista: \n";
		cout << "\n 1- Lista " << l1.nome;
		cout << "\n 2- Lista " << l2.nome;
		cout << "\n 0- sair ";
		cout << "\n\n Escolha sua opcao: ";
		cin >> op1;
		
		switch (op1) {
		case 1: 
		case 2: {
			if (op1 == 1) {
				ls = l1;
			}
			else {
				ls = l2;
			}
			do {
				system("CLS");
				cout << "\n\n  Menu de opcoes lista " << ls.nome << ": \n";
				cout << "\n 1- Inserir dados na lista ";
				cout << "\n 2- Mostrar todos os dados da lista ";
				cout << "\n 3- Mostrar somente RAs da lista ";
				cout << "\n 4- Pesquisar RA";
				cout << "\n 5- Remover RA da lista";
				cout << "\n 6- Remover o primeiro RA";
				cout << "\n 7- Remover o último RA";
				cout << "\n 8- Medias maiores que 6";
				cout << "\n 9- Inserir primeiro";
				cout << "\n 0- Sair";
				cout << "\n\n Escolha sua opcao: ";
				cin >> op2;
				switch (op2) {
					case 1: {
						system("CLS");
						cout << "\n Inserir dados na lista " << ls.nome << ": \n\n";
						op = 99;
						while (op != 0) {
							cout << " Digite RA: ";
							cin >> p.RA;
							cout << " Digite a nota da prova: ";
							cin >> p.prova;
							cout << " Digite a nota do trabalho: ";
							cin >> p.trab;
							ls = insere(ls, p);
							cout << "\n Continuar? 1= sim, 0 = nao): ";
							cin >> op;
						}
						break;
						}
					case 2: {
						system("CLS");	
						cout << "\n Lista 1 - " << ls.nome << "\n";
						imprime(ls);
						cout << "\n\n";
						system("pause");
						break; 
						}
					case 3: {
						system("CLS");	
						cout << "\n Lista 1 - " << ls.nome << "\n";
						imprimeRA(ls);
						cout << "\n\n";
						system("pause");
						break;
					}
					case 4: {
						system("CLS");
						cout << "\n Pesquisar RA na lista " << ls.nome << "\n";
						cout << "\n Digite o RA: ";
						cin >> ra;
						pesquisaRA(ls, ra);
						cout << "\n\n";
						system("pause");
						break;
					}
					case 5: {
						system("CLS");
						cout << "\n Remover RA da lista " << ls.nome << "\n";
						cout << "\n Digite o RA: ";
						cin >> ra;
						ls = removeRA(ls, ra);
						cout << "\n\n";
						imprimeRA(ls);
						cout << "\n\n";
						system("pause");
						break;
					}
					case 6: {
						system("CLS");
						cout << "\n Remover o primeiro RA da lista " << ls.nome << "\n";
						ls = removePrim(ls);
						cout << "\n\n";
						imprimeRA(ls);
						cout << "\n\n";
						system("pause");
						break;
					}
					case 7: {
						system("CLS");
						cout << "\n Remover o ultimo RA da lista " << ls.nome << "\n";
						ls = removeUlt(ls);
						cout << "\n\n";
						imprimeRA(ls);
						cout << "\n\n";
						system("pause");
						break;
					}
					case 8: {
						system("CLS");
						cout << "\n Alunos com media maior que 6 \n";
						imprimeMedias(ls);
						cout << "\n\n";
						system("pause");
					}
					case 9: {
					system("CLS");
						cout << "\n Inserir dados no inicio " << ls.nome << ": \n\n";
						op = 99;
						while (op != 0) {
							cout << " Digite RA: ";
							cin >> p.RA;
							cout << " Digite a nota da prova: ";
							cin >> p.prova;
							cout << " Digite a nota do trabalho: ";
							cin >> p.trab;
							ls = inserePrim(ls, p);
							cout << "\n Continuar? 1= sim, 0 = nao): ";
							cin >> op;
						}
						break;
						}
					case 0: {
						break;
					}
					default: {
						cout << "\n Opcao invalida";
						break;
					}
				}
			} while (op2 != 0);
			break;		
		}			
		case 0: {
			break;
		}
		default : {
			cout << "\n Opção inválida";
			break;
			}
		}
						
		} while (op1 != 0);
	return;
}

void pesquisaRA(lista l, int x) {
	node *aux;
	aluno a;
	int flag = 0;
	aux = l.ini->next;
	while(aux !=NULL) {
		a = aux-> dado;
		if (a.RA == x){
			cout << "\n Item encontrado: \n";
			mostraaluno(a);
			flag = 1;
			aux = NULL; }
		else {
			aux = aux->next;}
	}
	if (flag == 0) {
		cout << "\n Item nao encontrado. \n\n";
	}
}

lista removeRA(lista l, int x) {
	node *aux;
	node *link;
	aluno a;
	
	int flag = 0;
	aux = l.ini->next;
	link = l.ini;
	
	while(aux !=NULL) {
		a = aux->dado;
		if (a.RA == x){
			cout << "Removendo RA: " << x << "\n\n";
			link->next = aux->next;
			if (aux = l.ult) {
				l.ult = link;
			}
			flag = 1;
			free(aux);
			aux = NULL;
		} // liberar memoria aqui
		else {
			aux = aux->next;
			link = link->next;}
	}
	if (flag == 0) {
		cout << "\n RA nao encontrado. \n\n";
	}


	return l;
}

lista removePrim(lista l) {
	node *aux;
	node *ant;
	aluno a;
	
	ant = l.ini;
	aux = l.ini->next;
	a = aux->dado;
	cout << "Removendo RA: " << a.RA << "\n\n";
	free(ant);
	l.ini = aux;
	return l;
}

lista removeUlt(lista l) {
	node *aux;
	node *link;
	node *ant;
	aluno a;
	
	aux = l.ini->next;
	link = l.ini;
	
	while(aux !=NULL) {
		ant = link;
		aux = aux->next;
		link = link->next;
	}
	a = link->dado;
	cout << "Removendo RA: " << a.RA << "\n\n";
	ant->next = NULL;
	l.ult = ant;
	free(link);
	return l;
}

void limpaBuffer(){
	cin.clear();
	while (cin.get() != '\n') 
	{
    	continue;
	}
}
