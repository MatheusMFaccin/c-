#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>


using namespace std;

#include "arvore.h"



int converter(string texto){
  return stoi(texto);
}


int main() {
  
  Arvore *raiz = NULL;
  string texto;
  string arquivo;
  int numeros = 0;

  
  cout << "digite o nome do arquivo: ";
  cin >> arquivo;

  
  ifstream MyReadFile(arquivo);

  
  while (getline (MyReadFile, texto)) {
    
    numeros = converter(texto);

    raiz = inserir(numeros,raiz);
    
  }
  MyReadFile.close();
   
  cout << "estao nom mesmo nivel ? "<<endl;
  
  bool verificar = verificarniveis(raiz);
  
  cout<<verificar<<endl;

  cout <<" digite um valor da arvore para verificar se o valor é uma folha : " 
  <<endl;
  cin >> numeros;
  
  verificar = verificarfolha(numeros,raiz);
  
  cout << verificar;
  
    
}