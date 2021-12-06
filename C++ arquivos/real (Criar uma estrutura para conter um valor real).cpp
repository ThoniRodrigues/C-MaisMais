/* Criar uma estrutura para conter um valor real
	Thoni Rodrigues
*/

#include <iostream>
#include <math.h>

using namespace std;

// Criação da estrutura para representar um valor real
typedef struct {
	int  esq;
	int  dir;
} real;

int main() {
	
	// Criação de uma variável do tipo real
	real num1;
	float num3, aux1, aux2;
	
	// Entrada do número
	cout << " Entrada de números reais \n\n\n";
	cout << "\n Digite a parte inteira: ";
	cin >> num1.esq;
	cout << "\n Digite a parte decimal: ";
	cin >> num1.dir;
	
	// Para garantir somente valores positivos
	num1.dir = abs(num1.dir);
	
	// Mostra o número digitado
	cout << "\n O numero digitado foi: " << num1.esq << "." << num1.dir << "\n\n";
	
	// Conversão para float
	aux1 = num1.esq;		//parte inteira
	aux2 = num1.dir;		//parte decimal
	// Converte a parte decimal para o valor decimal correto
	while (aux2 > 1) {
		aux2 = aux2 /10;
	}
		
	cout << "\n Numero convertido em float: ";
	// Para evitar erros em numeros negativos
	if (aux1 < 0){ 
		num3 = (abs(aux1) + aux2) * -1;
	}
	else {
		num3 = aux1 + aux2;
	}
	cout << num3 << "\n\n";
	cout << " Teste do numero convertido \n";
	cout << "\n Numero multiplicado por 3: ";	
	cout << num3 * 3 << "\n";
	cout << "\n Numero dividido por 3: ";	
	cout << num3 / 3 << "\n\n\n";
	
	system("pause");
	return(0);
}

