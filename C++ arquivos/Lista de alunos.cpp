#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Aluno {
	char del;
	int ra;
	char nome[30];
};

Aluno aluno;


void mostra(fstream& arq) {
	
	system("cls");
	cout << "\n Listando \n";
	arq.clear();
	arq.seekg(0,arq.beg);	
	while(arq.read((char *) &aluno, sizeof(Aluno))) {
		if (aluno.del != '*') {
		cout << "Del: " << aluno.del;
		cout << "RA: " << aluno.ra << endl;
		cout << "Nome: " << aluno.nome << endl << endl;
	}
	}

	
}

int pesquisa(fstream& arq, int ra) {
	system("cls");
	
	int flag = 0;
	int pos = -1, find;
	cout << "Pesquisando";
	arq.clear();
	arq.seekg(0,arq.beg);	
	
	while(arq.read((char *) &aluno, sizeof(Aluno))) {
		pos++;
		if (aluno.ra == ra) {
			cout << "\n RA encontrado: \n" << "RA: " << aluno.ra << endl;
			cout << "Nome: " << aluno.nome << endl << endl;
			flag = 1;
			find = pos;
		}
		
	}
	if (flag == -1) {
		cout << "\n RA não encontrado.";
	}
	cout << pos <<"\n";
	
	arq.clear();
	arq.seekg(find * sizeof(Aluno), arq.beg);
	arq.read((char *) &aluno, sizeof(Aluno));
	
	cout << "Del: " << aluno.del;
	cout << "RA: " << aluno.ra << endl;
	cout << "Nome: " << aluno.nome << endl << endl;
	system("pause");	
	aluno.del = '*';
	arq.seekp(find * sizeof(Aluno), arq.beg);
	arq.write((char *) &aluno, sizeof(Aluno));

	return find;
	
}


void insere(fstream& arq) {
	
	do{
		system("cls");
		aluno.del = ' ';
		cout << "RA (0 para sair): ";
		cin >> aluno.ra;
		if(!aluno.ra>0) break;
		cin.ignore();
		cout << "Nome (ENTER para sair): ";
		cin.getline(aluno.nome, 30);
		if (strlen(aluno.nome)==0) break;
		arq.write((char *) &aluno, sizeof(Aluno));
	} while(1);

}

int main()
{
	fstream arq;
	arq.open("alu.dat", ios_base::in|ios_base::out|ios_base::binary|ios_base::ate);
	if (arq.fail()) {
		cout << "\n Erro no arquivo. ";
		exit(1);
	}
	int pes, ra;
		
	insere(arq);	
	mostra(arq);
	system("pause");
	mostra(arq);
	system("pause");
	cout << "\n Digite um RA para pesquisa: ";
	cin >> ra;
	pes = pesquisa(arq, ra);
	cout << "\n Ultima posicao: " << pes;
	mostra(arq);
	system("pause");
	arq.close();
	return 0;
	
}
