typedef struct no {
  int dado;
  struct no *prox;
} Celula;

void exibirLista(Celula *lista) {
  Celula *p;
  for (p = lista; p; p = p->prox) {
    cout << p->dado << endl;
  }
}


//inserir na lista de forma ordenada tendo como chave o valorGlicemia
Celula *inserirLista(int valor, Celula *lista) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
  novo->dado = valor;
  novo->prox = NULL;

  //percorrer para encontrar o local adequado na lista
  //testar se é a primeira vez
  if (!lista) return novo;

  Celula *p, *pR;
  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor < p->dado) break;
  }

  //é o primeiro
  if (p == lista) {
    novo->prox = lista;
    return novo;
  }
  //é o último
  if (!p) {
    pR->prox = novo;
  } else { //está no meio de duas celulas
    pR->prox = novo;
    novo->prox = p;
  }
  //retorna o inicio da lista
  return lista;  
}

//metodo que receba um valor, o localiza na lista e o remove da estrutura
Celula *excluirLista(int valor, Celula *lista) {
  Celula *p, *pR;

  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor == p->dado) {
      //eh o primeiro
      if (p == lista) {
        lista = lista->prox;
      } else if (!p->prox) { //eh o ultimo
        pR->prox = NULL;
      } else { //esta entre celulas
        pR->prox = p->prox;
      }
      free(p);
      return lista;
    }
  }
  cout << "Valor não localizado para exclusão!" << endl;
  return lista;
}

Celula *excluirR(int valor, Celula *lista) {
    if (lista) {
        //vou pesquisar e avançar
        if (valor == lista->dado) {
            //preparar para excluir
            Celula *backup = lista->prox;
            free(lista);
            return backup;
        } else {
            //não é o valor a ser excluido, então vamos avançar na lista
            lista->prox = excluirR(valor, lista->prox); //ponto de recursão, só com a teoria do joão e maria
            return lista;
        }
    } else {
        return NULL;
    }
}
//2) implementar o método localizar recursivo. O método deve receber um valor inteiro e o
//endereço da lista simples. Ao final, caso a valor exista na lista, retornar o endereço
//do valor, ou NULL caso não exista;

void localizar(int valor,Celula *lista){
  if(lista!=NULL){
    if(lista->dado==valor){
        cout <<"endereço do valor: "<<lista;
      }
    
    
    localizar(valor,lista->prox);
    } 
      
  
}
//3) implementar o método localizarPosicaoLogica de forma recursiva. O método deve receber
//um valor inteiro e o endereço da lista simples. Ao final, caso o valor exista na lista, 
//retornar sua posição lógica (0 é a primeira posição, 1 é a segunda, assim por diante).
//Caso o valor não esteja na lista, retornar -27;

void localizarposicao(int valor,int contador,Celula *lista){
  
  int posicao;
  if(lista!=NULL){
     contador++;
     
    if(lista->dado==valor){
      cout<<"posição logica é: "<<contador;
    }
    
  
  localizarposicao(valor,contador,lista->prox);
  
  }
  
  
  //cout<<"valor não encontrado erro: -27";  
}

//4) implementar um método recursivo que receba o endereço de uma lista simples e exiba todos os valores pares contigo na lista;

void localizarpares(Celula *lista){
  if(lista!=NULL){
    if(lista->dado%2==0){
      cout<<lista->dado<<endl;
     
    }
    
    localizarpares(lista->prox);
  }
  
}
//5) implementar um método recursivo que receba uma lista simples e retorne o total de elementos pares contidos na lista;
void contarpares(int contador,Celula *lista){
  
  if(lista!=NULL){
    
    if(lista->dado%2==0){
      contador++;
      cout<<contador<<endl;    
    }
    
    contarpares(contador,lista->prox); 
  }
  
}