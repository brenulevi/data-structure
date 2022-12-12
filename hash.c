#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11
#define true 1

typedef struct element {
  int value;
  struct element *next;
} Element;

typedef struct {
  Element *tab[SIZE];
} HashTable;

int calculateHash(int value) { return value % SIZE; }

// FEITO
void initializeHashTable(HashTable *th) {
  for (int i = 0; i < SIZE; i++) {
    th->tab[i] = NULL;
  }
}

// FEITO
void insertHashTable(HashTable *th, int value) {
  // ACHA A LINHA QUE O OBJETA VAI
  int paraOndeVai = calculateHash(value); // = 1

	// CRIA O OBJETO
  Element *novoElemento = malloc(sizeof(Element));
  novoElemento->value = value;
  novoElemento->next = NULL;

	// VERIFICA SE O OBJETO VAI PRO INÍCIO DO HASH OU PRO FINAL DA LISTA ENCADEADA
  if (th->tab[paraOndeVai] != NULL) {
    Element *aux;
    for (aux = th->tab[paraOndeVai]; aux != NULL; aux = aux->next) {
      if (aux->next == NULL)
      {
        
        aux->next = novoElemento;
        break;
      }
    }
  } else
    th->tab[paraOndeVai] = novoElemento;
}

void search(HashTable *th, int key) {
	
}

// FEITO
void removeElement(HashTable *th, int key) {
	// ACHA A LINHA DO ELEMENTO
	int linhaObjeto = calculateHash(key);
  // VERIFICA SE O ELEMENTO ESTÁ NO INÍCIO, NO MEIO OU NO FIM DA LISTA ENCADEADA
  Element *aux, *anterior;
  for (aux = th->tab[linhaObjeto]; aux != NULL; aux = aux->next){
    // VERIFICA SE O AUX CORRESPONDE AO ELEMENTO A SER DELETADO
    if (aux->value == key){
      // VERIFICA SE O AUX É O PRIMEIRO
      if(aux == th->tab[linhaObjeto])
        th->tab[linhaObjeto] = aux->next;
      // VERIFICA SE O AUX ESTÁ NO FINAL
      else if (aux->next == NULL)
        anterior->next = NULL;
      // VERIFICA SE O AUX ESTÁ NO MEIO
      else 
        anterior->next = aux->next;
      free(aux);
      return;
    }
    anterior = aux;
  }
	printf("%s\n", "Nenhum elemento encontrado");
}

// FEITO
void printLine(HashTable *th, int line) {
  if (th->tab[line] == NULL) {
    printf("%s\n", "Hash Vazio");
    return;
  } 
  
  Element *aux;
  for (aux = th->tab[line]; aux != NULL; aux = aux->next)
    printf("%d\n", aux->value);
}

// FEITO
void print(HashTable *th) {
	for (int i = 0; i<SIZE; i++) {
		printf("Linha %d:\n", i);
    printLine(th,i);
		printf("\n");
		
	}
}

int main() {
  HashTable th;
  initializeHashTable(&th);

	// 3
  insertHashTable(&th, 14);
  insertHashTable(&th, 25);
  insertHashTable(&th, 36);
  insertHashTable(&th, 47);
  insertHashTable(&th, 58);

	// 0
  insertHashTable(&th, 11);
  insertHashTable(&th, 22);
  insertHashTable(&th, 33);

	// 1
  insertHashTable(&th, 12);
  insertHashTable(&th, 23);
  insertHashTable(&th, 34);

  print(&th);
	
	
	

  // printf("\n\nTabela vazia: \n");
  // print(&th);

  // insertHashTable(&th, 7);
  // insertHashTable(&th, 17);
  // insertHashTable(&th, 36);
  // insertHashTable(&th, 100);
  // insertHashTable(&th, 106);
  // insertHashTable(&th, 205);
  // printf("\n\nTabela apos insercoes: \n");
  // print(&th);

  // printf("\n\nBuscando elementos: \n");
  // search(&th, 14);
  // search(&th, 205);

  // removeElement(&th, 205);
  // removeElement(&th, 7);
  // removeElement(&th, 106);
  // printf("\n\nTabela apos remocoes: \n");
  // print(&th);

  return 0;
}