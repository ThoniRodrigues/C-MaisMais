#include <iostream>
#include <malloc.h>

using namespace std;

   
struct RegAluno {
	int matricula;
	float media;
	struct RegAluno *prox;
};
typedef struct RegAluno Aluno;

/* função de criação: retorna uma Aluno vazia */
Aluno* lst_Cria()
{
return NULL;
}

/* inserção no início: retorna a Aluno atualizada */
Aluno* lst_insere (Aluno* lst, int mat,float nt)
{
Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
novo->matricula = mat;
novo->media = nt;
novo->prox = lst;
return novo;
}

void lst_imprime (Aluno *lst)
{
Aluno  *p;
int cont = 0;

for (p = lst; p != NULL; p = p->prox)
{
   if (p->media >= 6) {
   	cout << p->matricula << "\t" << p->media << "\n";
   	cont++;
	}
}
cout << "\n Quantidade de alunos com media maior ou igual a 6: " << cont << "\n\n";
system ("pause");
}

int main (void)
{
    int mat_aux;
    float media_aux;
Aluno* lst; /* declara uma Aluno não inicializada */
lst = lst_Cria(); /* cria e inicializa Aluno como vazia */
for(int x=0;x<5;x++)
{
        cout << "Digite a " << x+1 << " matricula: ";
        cin >> mat_aux;
        cout <<"Digite a " << x+1 << " media: ";
        cin >> media_aux;
lst = lst_insere(lst, mat_aux, media_aux); 
}

//printf("%d",lst->info);
lst_imprime(lst);

return 0;
}
