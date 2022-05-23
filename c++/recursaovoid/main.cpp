
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>


using namespace std;


#include "lista.h"


Celula *popular(Celula *lista, int n) {
  srand(time(NULL));
  
  for (int i = 0; i < n; i++) {
    lista = inserirLista(rand() % 100, lista);
  }
  return lista;
}

int main() {
  int qtdNumerosLista = 30;
  int contador = 0;
  int valor = 0;
  Celula *lista = NULL;

  lista = popular(lista, qtdNumerosLista);
  cout << "Lista inicial" << endl;
  exibirLista(lista);

  cout << "\ndigite o valor da lista que deseja encontrar o endereço da memoria \n"<<endl;
  cin >> valor;
  localizar(valor,lista);
  cout << "\ndigite o valor que deseja encontrar a posição logica\n"<<endl;
  cin >> valor;
  localizarposicao(valor,contador,lista);
  cout<<"\nvalores pares abaixo"<<endl;
  localizarpares(lista);
  
  cout<<"\nnumero total de pares:"<<endl;
  contarpares(contador,lista);
  
  
  //exibirLista(lista);
  
  return 1;
}