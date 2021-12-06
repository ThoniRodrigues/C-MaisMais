#include <iostream>
using namespace std;

main()
{

struct data
{
       int dia, mes, ano; };
       
struct RegProduto 
{ 
       char origem[30], destino[30];
       data data_viagem;
       int hora, minuto;
       int poltrona;
       float distancia; } produto[2];
       
       for (int x=0; x<2; x++)
       {
       
       cout << "\n--------------------";
       cout << "\n\n PASSAGEM DE ONIBUS";
     cout << "\n\n--------------------"; 
       
       cout << "\n\nDigite o local de origem: ";
       cin.getline(produto[x].origem,30); // JAMAIS ESQUECER DO PRODUTO
       cout << "\nDigite o local de destino: ";
       cin.getline(produto[x].destino,30); // [x] declarado por causa do "FOR"
       cout << "\nDigite o dia da viagem: ";
       cin >> produto[x].data_viagem.dia;
       cout << "\nDigite o mes da viagem: ";
       cin >> produto[x].data_viagem.mes;
       cout << "\nDigite o ano da viagem: ";
       cin >> produto[x].data_viagem.ano;
       cout << "\nDigite a hora da viagem: ";
       cin >> produto[x].hora;
       cout << "\nDigite o minuto da viagem: ";
       cin >> produto[x].minuto;
       cout << "\nDigite a sua poltrona: ";
       cin >> produto[x].poltrona;
       cout << "\nDigite a distancia: ";
       cin >> produto[x].distancia;
       
       // mostrar os dados digitados
       cout << "Origem: " <<produto[0].origem; // DO PRIMEIRO
       cout << "\nDestino: " <<produto[1].destino;
       cout << "\nPoltrona: " <<produto[0].poltrona;
       fflush(stdin);
       }
       system("pause");
       }
