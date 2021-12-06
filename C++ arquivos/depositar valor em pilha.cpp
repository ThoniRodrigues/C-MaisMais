/* Desenvolvido por Thoni Rodrigues
    
*/

#include <iostream>
#include <malloc.h>
using namespace std;

// estrutura principal
typedef struct _node { int dado; struct _node *prox; } node;

// variavel global para capturar o elemento removido
int rem = 0;

// funções da pilha retornam o nó atual da pilha após cada operação
// por isso tem que chamar as funções com as seguintes sintaxes:
//      pilha = criapilha();
//      pilha = pop(pilha);
//      pilha = push(pilha, valor);
//      int = pvazia(pilha);        (retorna 1 se vazia, 0 se não vazia)
//      int = topo(pilha);          (retorna o valor do topo da pilha)
//      mostra(pilha);              (mostra os valores inseridos, do topo para o fundo)


// função auxiliar para alocar um novo nó na pilha
node* paloca() {
	node *aux;
	aux = (node*)malloc(sizeof(node));
	if (aux == NULL) { cout << "\n Erro de alocação. "; exit(1); }
	return aux;
}

// teste se a pilha está vazia
int pvazia(node *p) {
    return(p->prox == NULL ? 1 : 0);
    }

// cria uma pilha (podem ser criadas várias pilhas)
node* criapilha() {
    node *aux;
    aux = paloca();
    aux->prox = NULL;
    return aux;
    }

// insere um elemento: push
node* push(node *p, int x) {
    node *aux;
    aux = paloca();
    //	cout << "\n Elemento inserido: " << x << "\n";
	aux->prox = p;
	p->dado = x;
	p = aux;
	return p;
	}

// remove um elemento do topo: pop
node* pop(node *p) {
	node *aux;
	aux = p;
	int x;
	if (aux->prox == NULL) { cout << "\n A pilha esta vazia. (pop) \n"; }
	else { aux= aux->prox; x = aux->dado; rem = x; p->prox = aux->prox; free(aux); }
	return p;
	}

// verifica o topo da pilha:
int topo(node *p){
    node *aux;
    aux = p->prox;
    return aux->dado;
    }

// mostra os valores da pilha
void mostra(node *p) {
	node *aux;
	aux = p->prox;
	if (pvazia(p)) { cout << "\n A pilha esta vazia. (mostra)"; }
	else { while (aux != NULL) { cout  << aux->dado << "  "; aux = aux->prox; } }
	cout << "\n";
	return;
}

// função para receber as caixas
node* recebeCaixaNoDeposito(node *pilhaA, node *pilhaB, node *pilhaC) {
	int x, y, z, op = 99;
	char s;
    // cria as três pilhas necessárias
	pilhaA = criapilha(); // principal
	pilhaB = criapilha(); // temporária para as caixas de 5 toneladas
	pilhaC = criapilha(); // temporária para as caixas de 3 toneladas

// loop de recebimento das caixas
    while (op != 0) {
        system("CLS");
        cout << "\n Insira o peso da caixa: ";
        cin >> y;
        // detecta pesos invalidos na entrada
        if (y != 3 && y !=5 && y != 7) {
            cout << "\n Peso invalido.\n\n";}
        else {
            // se a pilha A estiver vazia, simplesmente empilha a caixa
            if (pvazia(pilhaA) == 1 ){
                pilhaA = push(pilhaA, y);
                cout << "\n\n Empilhando " << y << " em A. \n";
                cout << "\n\n Caixas na pilha A: ";
                mostra(pilhaA);
                cout << "\n";
                }

            else {
                // se houver caixas na pilha, verifica qual o peso que está no topo
                z = topo(pilhaA);
                // loop retira as caixas menores que o peso de entrada e empilha nas pilhas auxiliares
                while (z < y && pvazia(pilhaA) == 0){
                    if ( z == 3 ) {
                        pilhaA = pop(pilhaA);
                        x = rem;
                        cout << "\n Desempilhando " << x << " de A, ";
                        pilhaC = push(pilhaC, x);
                        cout << " empilhando " << x << " em C.";
                    }
                    if ( z == 5) {
                        pilhaA = pop(pilhaA);
                        x = rem;
                        cout << "\n Desempilhando " << x << " de A, ";
                        pilhaB = push(pilhaB, x);
                        cout << " empilhando " << x << " em B.";
                    }
                    // após retirar uma caixa, verifica se a pilha esvaziou
                    if (pvazia(pilhaA) == 1) {
                        break;
                    }
                    // atualiza o peso que está no topo da pilha
                    z = topo(pilhaA);
                }
                // aqui a pilha A já foi devidamente verificada, então empilha o valor da entrada
                pilhaA = push(pilhaA, y);
                cout << "\n\n Empilhando " << y << " em A. \n";
                // retorna as caixas da pilha B para a pilha principal A
                while (pvazia(pilhaB) == 0) {
                    pilhaB =  pop(pilhaB);
                    x = rem;
                    cout << "\n Desempilhando " << x << " de B, ";
                    pilhaA = push(pilhaA, x);
                    cout << " empilhando " << x << " em A.";
                }
                // retorna as caixas da pilha C para a principal A
                while (pvazia(pilhaC) == 0) {
                    pilhaC = pop(pilhaC);
                    x = rem;
                    cout << "\n Desempilhando " << x << " de C, ";
                    pilhaA = push(pilhaA,x);
                    cout << " empilhando " << x << " em A.";
                }
                // mostra a situação da pilha.
                cout << "\n\n Caixas na pilha A: ";
                mostra(pilhaA);
                cout << "\n";

            }

        }
        // para retornar ao inicio caso haja caixas para empilhar, senao sai
        cout << "\n\n Recebe outra caixa? (s/n)";
        cin >> s;
        if (s != 's') {
            break;
        }
    }
    return pilhaA;
}

// função principal
int main() {
    node *pilhaA, *pilhaB, *pilhaC;
    // chama a função recebeCaixaNoDeposito. O retorno atualiza a pilha.
    pilhaA = recebeCaixaNoDeposito(pilhaA, pilhaB, pilhaC);
    // apos os empilhamentos, mostra a situação da pilha e encerra o programa
    cout << "\n\n Situacao final no deposito: ";
    mostra(pilhaA);
    cout <<
    "\n\n\n";
	system("pause");
	return 0;
}


