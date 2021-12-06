#include <iostream>
#include <fstream>
#include <locale.h>
#include <windows.h>
using namespace std;

typedef struct {
	char modelo[10];
	char fabricante[20];
	int passageiros;
	float comprimento;
	float altura;
	float velocidade;
	float altitude;
	float motor;
} aviao;
	
void SetCor(int ForgC, int BackC);
void gotoxy(int x, int y);

void telainfo() {
	SetCor(15,1); 
	gotoxy(2, 2); cout << "Modelo.......: ";
	gotoxy(2, 4); cout << "Fabricante...: ";
	gotoxy(2, 6); cout << "Passageiros..: ";
	gotoxy(2, 8); cout << "Comprimento..: ";
	gotoxy(2,10); cout << "Altura.......: ";
	gotoxy(2,12); cout << "Velocidade...: ";
	gotoxy(2,14); cout << "Altitude.....: ";
	gotoxy(2,16); cout << "Motor........: ";
}

void teladados() {
	SetCor(0,15); 
	gotoxy(18, 2); cout << "          ";
	gotoxy(18, 4); cout << "                    ";
	gotoxy(18, 6); cout << "    ";
	gotoxy(18, 8); cout << "      m";
	gotoxy(18,10); cout << "      m";
	gotoxy(18,12); cout << "      km/h";
	gotoxy(18,14); cout << "      km";
	gotoxy(18,16); cout << "      HP";
}
	
aviao dados(aviao a) {
		
	SetCor(0,15); 
	gotoxy(18, 2); cin >> a.modelo;
	gotoxy(18, 4); cin >> a.fabricante;
	gotoxy(18, 6); cin >> a.passageiros;
	gotoxy(18, 8); cin >> a.comprimento;
	gotoxy(18,10); cin >> a.altura;
	gotoxy(18,12); cin >> a.velocidade;
	gotoxy(18,14); cin >> a.altitude;
	gotoxy(18,16); cin >> a.motor;
	
	return a;
}	
	
void mostra(aviao a) {
	
	SetCor(0,15);
	teladados();
	gotoxy(18, 2); cout << a.modelo;
	gotoxy(18, 4); cout << a.fabricante;
	gotoxy(18, 6); cout << a.passageiros << " passageiros.";
	gotoxy(18, 8); cout << a.comprimento << " metros.";
	gotoxy(18,10); cout << a.altura << " metros.";
	gotoxy(18,12); cout << a.velocidade << "    km/h.";
	gotoxy(18,14); cout << a.altitude << "     km.";
	gotoxy(18,16); cout << a.motor << "     HP.";
	
	return;
}

void grava(aviao a, fstream& avi) {
		
	avi << a.modelo << ' ' 
		<< a.fabricante << ' ' 
		<< a.passageiros << ' ' 
		<< a.comprimento << ' ' 
		<< a.altura << ' ' 
		<< a.velocidade << ' ' 
		<< a.altitude << ' ' 
		<< a.motor << endl;
	
}

void mostraav(fstream& avi) {
	
	aviao a;
	avi.seekg(0);
	while(avi >> a.modelo 
			>> a.fabricante 
			>> a.passageiros 
			>> a.comprimento
	 		>> a.altura 
	 		>> a.velocidade 
	 		>> a.altitude 
	 		>> a.motor)
		{
			
			cout << "\n Modelo: " << a.modelo;
			cout << "\n Fabricante: " << a.fabricante;
			cout << "\n N. Passageiros: " << a.passageiros;
			cout << "\n Comprimento(m): " << a.comprimento;
			cout << "\n Altura(m): " << a.altura;
			cout << "\n Velocidade(km/h): " << a.velocidade;
			cout << "\n Altitude(km): " << a.altitude;
			cout << "\n Motor(HP): " << a.motor << "\n";	
		}
		
		
}	

int main(){
	int corf, corb, op;
	setlocale(LC_ALL,"");
	aviao av;
	
	fstream avi;
	avi.open("aviao.txt", ios_base::in|ios_base::out|ios_base::app);
	
	op = 99;
	do {
		SetCor(15,0);
		system("cls");
		
		cout << "\n 1. Inserir aviões";
		cout << "\n 2. Listar aviões";
		cout << "\n 0. Sair \n ";
		cin >> op;
		
		switch (op) {
			case 1: {
				while (op !=0) {
					SetCor(15,0);
					system("cls");
					telainfo();
					teladados();
					av = dados(av);
					grava(av, avi);
					mostra(av);
					gotoxy(2,23);
					op = 99;
					cout << "\n Digite 0 para sair";
					cin >> op;
						
					}
				op = 99;
				break;
				}
			case 2: {
				
				mostraav(avi);
				break;
				}
			default:
				break;
			}
			
		} while (op != 0);	
		
		
	SetCor(15,0);
	system("cls");	
	
	
	
	
	avi.close();
	
	gotoxy(2,23);
	system("pause");
	return 0;
}
	

void SetCor(int ForgC, int BackC) {
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x, y};
	SetConsoleCursorPosition(handle, position);
}
