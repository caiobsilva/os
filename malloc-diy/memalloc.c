#include <stdio.h>
#include <stddef.h>

char memoria[20000];

struct bloco {
  size_t  tamanho;
  int     libera;
  struct  bloco *prox;
};

struct bloco *memoLivre=(void*)memoria;

void inicializar() {
  memoLivre->tamanho=20000-sizeof(struct bloco);
  memoLivre->libera=1;
  memoLivre->prox=NULL;
}

void quebra(struct bloco *encaixe_de_memo,size_t tamanho) {
  struct bloco *new=(void*)((void*)encaixe_de_memo+tamanho+sizeof(struct bloco));
  new->tamanho=(encaixe_de_memo->tamanho)-tamanho-sizeof(struct bloco);
  new->libera=1;
  new->prox=encaixe_de_memo->prox;
  encaixe_de_memo->tamanho=tamanho;
  encaixe_de_memo->libera=0;
  encaixe_de_memo->prox=new;
}

void *aloca(size_t nDeBytes) {
  struct bloco *atual,*prev;
  void *resultado;
  if(!(memoLivre->tamanho)) {
    inicializar();
    printf("Memória inicializada\n");
  }
  atual=memoLivre;
  while((((atual->tamanho)<nDeBytes)||((atual->libera)==0))&&(atual->prox!=NULL)) {
    prev=atual;
    atual=atual->prox;
    printf("Bloco verificado\n");
  }
  if((atual->tamanho)==nDeBytes) {
    atual->libera=0;
    resultado=(void*)(++atual);
    printf("Bloco de encaixe exato alocado\n");
    return resultado;
  }
  else if((atual->tamanho)>(nDeBytes+sizeof(struct bloco))) {
    quebra(atual,nDeBytes);
    resultado=(void*)(++atual);
    printf("Bloco de encaixe alocado com uma divisão\n");
    return resultado;
  } else {
    resultado=NULL;
    printf("Sem memória suficiente para alicação\n");
    return resultado;
  }
}

void misturar(){
  struct bloco *atual,*prev;
  atual=memoLivre;

  while((atual->prox)!=NULL){
    if((atual->libera) && (atual->prox->libera)){
      atual->tamanho+=(atual->prox->tamanho)+sizeof(struct bloco);
      atual->prox=atual->prox->prox;
      }
    prev=atual;
    atual=atual->prox;
  }
}

void libera(void* ptr){
  if(((void*)memoria<=ptr)&&(ptr<=(void*)(memoria+20000))){
    struct bloco* atual=ptr;
    --atual;
    atual->libera=1;
    misturar();
  }
  else printf("Forneça um ponteiro válido alocado por aloca\n");
}
