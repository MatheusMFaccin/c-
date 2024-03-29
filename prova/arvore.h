typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
    int fb; //fator de balanceamento
} Arvore;

typedef struct noString {
    string  valor;
    struct noString *esq;
    struct noString *dir;
    int fb; //fator de balanceamento
} ArvoreString;


int calcularAltura(Arvore *raiz) {
    if (raiz) {
        int altEsq = calcularAltura(raiz->esq);      

        int altDir = calcularAltura(raiz->dir); 
        
        
        if (altEsq > altDir) {
            return altEsq + 1;
        } else {
            return altDir + 1;
        }
    } else {
        return 0;
    }
}

int calcularAlturaString(ArvoreString *raiz) {
    if (raiz) {
        int altEsq = calcularAlturaString(raiz->esq);
        
        int altDir = calcularAlturaString(raiz->dir);
        
        
        if (altEsq > altDir) {
            return altEsq + 1;
        } else {
            return altDir + 1;
        }
    } else {
        return 0;
    }
}

Arvore *rodaEsquerda(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->dir;
    tmp = filho->esq;
    r = filho;
    filho->esq = pai;
    pai->dir = tmp;
    return r;
}

Arvore *rodaDireita(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->esq;
    tmp = filho->dir;
    r = filho;
    filho->dir = pai;
    pai->esq = tmp;
    return r;
}

void atualizarFB(Arvore *raiz) {
    if (raiz) {
        atualizarFB(raiz->esq);
        atualizarFB(raiz->dir);
        raiz->fb = calcularAltura(raiz->esq) - calcularAltura(raiz->dir);
    }
}

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        if(valor == raiz->valor){
          return raiz;
        }
        if (valor < raiz->valor) { //avançar ou empilhar para a esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else { //avançar ou empilhar para a direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        raiz->fb = calcularAltura(raiz->esq) - calcularAltura(raiz->dir);

        //descobrir se esta ou nao balanceado
        if (raiz->fb == -2) { //rotacao para esquerda
            //descobrir se eh rotacao simples
            if (raiz->fb < 0 && raiz->dir->fb < 0) {
                raiz = rodaEsquerda(raiz);
            } else {
                //rotacao dupla
                //1 - rodar o filho para direita
                raiz->dir = rodaDireita(raiz->dir);
                //2 - rodar o pai para a esquerda
                raiz = rodaEsquerda(raiz);
            }
            //atualizar o fb dos nodos da raiz
            atualizarFB(raiz);
        } else if (raiz->fb == 2) { //rotacao para direita
            //descobrir se eh rotacao simples
            if (raiz->fb > 0 && raiz->esq->fb > 0) {
                raiz = rodaDireita(raiz);
            } else {
                //rotacao dupla
                //1 - rodar o filho para esquerda
                raiz->esq = rodaEsquerda(raiz->esq);
                //2 - rodar o pai para a direita
                raiz = rodaDireita(raiz);
            }
            //atualizar o fb dos nodos da raiz
            atualizarFB(raiz);
        }
        return raiz;
    } else {
        //se estamos aqui, pq chegamos em um folha e estamos prontos para           adicionar o nodo na árvore
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;    
        novo->fb = 0; //todo nodo inserido, o fb é 0    
        return novo;
    }
}

ArvoreString *inserirString(string valor, ArvoreString *raiz) {
    if (raiz) {
        if (valor < raiz->valor) { //avançar ou empilhar para a esquerda
            raiz->esq = inserirString(valor, raiz->esq);
        } else { //avançar ou empilhar para a direita
            raiz->dir = inserirString(valor, raiz->dir);
        }
        raiz->fb = calcularAlturaString(raiz->esq) - calcularAlturaString(raiz->dir);
        return raiz;
    } else {
        //se estamos aqui, pq chegamos em um folha e estamos prontos para          adicionar o nodo na árvore
        ArvoreString *novo = (ArvoreString*)malloc(sizeof(ArvoreString));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;    
        novo->fb = 0; //todo nodo inserido, o fb é 0    
        return novo;
    }
}

Arvore *excluir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) { //valor localizado e pronto pra exclusão
            //eh folha
            if (!raiz->esq && !raiz->dir) {
                free(raiz);
                return NULL;
            } else {
                Arvore *novoPai;
                Arvore *p;
                if (raiz->esq) novoPai = raiz->esq;
                else novoPai = raiz->dir;
                
                for (p = novoPai; p->dir; p = p->dir);

                p->dir = raiz->dir;

                free(raiz);
                return novoPai;
            }
        } else {
            if (valor < raiz->valor) { //avancar para esquerda
                raiz->esq = excluir(valor, raiz->esq);
            } else { //avancar para direita
                raiz->dir = excluir(valor, raiz->dir);
            }
        }
        return raiz;
    }
    return NULL;
}

void exibir(Arvore *raiz, int nivel) {
    if (raiz) {
        exibir(raiz->dir, nivel + 1); //empilhando tudo para direita, busca-se exibir os maiores primeiro
        
        for (int i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << raiz->valor << "->" << raiz->fb << endl; 

        exibir(raiz->esq, nivel + 1); //empilhando tudo para esquerda, busca-se exibir os menores
    }
}


void exibirString(ArvoreString *raiz, int nivel) {
    if (raiz) {
        exibirString(raiz->dir, nivel + 1); //empilhando tudo para direita, busca-se exibirString os maiores primeiro
        
        for (int i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << raiz->valor << "->" << raiz->fb << endl; 

        exibirString(raiz->esq, nivel + 1); //empilhando tudo para esquerda, busca-se exibir os menores
    }
}


int localizarNivel(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return 0;
        if (valor < raiz->valor) {
            //ir para esquerda
            int resposta = localizarNivel(valor, raiz->esq);
            if (resposta == -1) return -1; //se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        } else {
            //ir para direita
            int resposta = localizarNivel(valor, raiz->dir);
            if (resposta == -1) return -1; //se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        }
    } else {
        return -1; //chegou nas folhas e o valor nao foi localizado
    }
}

int localizarNivelString(string valor, ArvoreString *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return 0;
        if (valor < raiz->valor) {
            //ir para esquerda
            int resposta = localizarNivelString(valor, raiz->esq);
            if (resposta == -1) return -1; //se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        } else {
            //ir para direita
            int resposta = localizarNivelString(valor, raiz->dir);
            if (resposta == -1) return -1; //se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        }
    } else {
        return -1; //chegou nas folhas e o valor nao foi localizado
    }
}

Arvore *menorElemento(Arvore *raiz) {
    if (!raiz) return NULL;
    Arvore *p;
    
    for (p = raiz; p->esq; p = p->esq);

    return p;
}

ArvoreString *menorElementoString(ArvoreString *raiz) {
    if (!raiz) return NULL;
    ArvoreString *p;
    
    for (p = raiz; p->esq; p = p->esq);

    return p;
}


Arvore *maiorElemento(Arvore *raiz) {
    if (!raiz) return NULL;

    Arvore *p;
    for (p = raiz; p->dir; p = p->dir);

    return p;
}

ArvoreString *maiorElementoString(ArvoreString *raiz) {
    if (!raiz) return NULL;

    ArvoreString *p;
    for (p = raiz; p->dir; p = p->dir);

    return p;
}

int contarVezes(int valor, Arvore *raiz) {
    if (raiz) {
        int qtdVezesEsquerda = contarVezes(valor, raiz->esq);//empilhar tudo para esquerda
        int qtdVezesDireita = contarVezes(valor, raiz->dir);//empilhar tudo para direita

        //so então testar, ou seja, o teste vem das folhas em direção a raiz
        if (valor == raiz->valor) return 1 + qtdVezesEsquerda + qtdVezesDireita;
        return 0 + qtdVezesEsquerda + qtdVezesDireita;
    } else {
        return 0;
    }
}

int contarVezesString(string valor, ArvoreString *raiz) {
    if (raiz) {
        int qtdVezesEsquerda = contarVezesString(valor, raiz->esq);//empilhar tudo para esquerda
        int qtdVezesDireita = contarVezesString(valor, raiz->dir);//empilhar tudo para direita

        //so então testar, ou seja, o teste vem das folhas em direção a raiz
        if (valor == raiz->valor) return 1 + qtdVezesEsquerda + qtdVezesDireita;
        return 0 + qtdVezesEsquerda + qtdVezesDireita;
    } else {
        return 0;
    }
}
bool verificarniveis(Arvore *raiz){
  Arvore *menor = menorElemento(raiz);
  Arvore *maior = maiorElemento(raiz);
  int menorvalor = menor->valor;
  int maiorvalor = maior->valor;
  int nivelmenor = localizarNivel(menorvalor,raiz);
  int nivelmaior = localizarNivel(maiorvalor,raiz);
  if(nivelmenor == nivelmaior){
    return true;
  }else{
    return false;
  }
}
bool verificarfolha(int valor,Arvore *raiz){
  if(raiz){
    if(valor==raiz->valor){
      if(raiz->esq == NULL && raiz->dir == NULL){
        return false;
      }else{
        return true;
      }
    }
    if(valor<raiz->valor){
      verificarfolha(valor,raiz->esq);
      
      
    }
    if(valor>raiz->valor){
      verificarfolha(valor,raiz->dir);
    }
    
  }
  return;
}