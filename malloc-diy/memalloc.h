#include <stdio.h>
#include <stddef.h>

#ifndef MEMALLOC_H
#define MEMALLOC_H

struct bloco;

void inicializar();
void quebra(struct bloco *encaixe_de_memo,size_t tamanho);
void *aloca(size_t nDeBytes);
void misturar();
void libera(void* ptr);

#endif
