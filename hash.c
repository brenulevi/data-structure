#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11

typedef struct element
{
  int value;
  struct element *next;
} Element;

typedef struct
{
  Element *tab[SIZE];
} HashTable;

int calculateHash(int value) { return value % SIZE; }

// Finished
void initializeHashTable(HashTable *th)
{
  for (int i = 0; i < SIZE; i++)
  {
    th->tab[i] = NULL;
  }
}

// Finished
void insertHashTable(HashTable *th, int value)
{
  int index = calculateHash(value);

  Element *new = malloc(sizeof(Element));
  new->value = value;
  new->next = NULL;

  if (th->tab[index] != NULL)
  {
    Element *aux;
    // for can be replaced by while
    for (aux = th->tab[index]; aux != NULL; aux = aux->next)
    {
      if (aux->next == NULL)
      {
        aux->next = new;
        break;
      }
    }
  }
  else
    th->tab[index] = new;
}

// Finished
void search(HashTable *th, int key)
{
  int index = calculateHash(key);
  Element *aux;
  for (aux = th->tab[index]; aux != NULL; aux = aux->next)
  {
    if (aux->value == key)
    {
      printf("Elemento %d está na linha %d", aux->value, index);
      return;
    }
  }
  printf("Elemento %d não existe\n", key);
}

// Finished
void removeElement(HashTable *th, int key)
{
  int index = calculateHash(key);
  Element *aux, *previous;
  for (aux = th->tab[index]; aux != NULL; aux = aux->next)
  {
    if (aux->value == key)
    {
      if (aux == th->tab[index])
        th->tab[index] = aux->next;
      else if (aux->next == NULL)
        previous->next = NULL;
      else
        previous->next = aux->next;
      free(aux);
      return;
    }
    previous = aux;
  }
  printf("%s\n", "Nenhum elemento encontrado");
}

// Finished
void printLine(HashTable *th, int line)
{
  if (th->tab[line] == NULL)
  {
    printf("%s\n", "Hash Vazio");
    return;
  }

  Element *aux;
  for (aux = th->tab[line]; aux != NULL; aux = aux->next)
    printf("%d\n", aux->value);
}

// Finished
void print(HashTable *th)
{
  for (int i = 0; i < SIZE; i++)
  {
    printf("Linha %d:\n", i);
    printLine(th, i);
    printf("\n");
  }
}

int main()
{
  HashTable th;
  initializeHashTable(&th);
  printf("\n\nTabela vazia: \n");
  print(&th);

  insertHashTable(&th, 7);
  insertHashTable(&th, 17);
  insertHashTable(&th, 36);
  insertHashTable(&th, 100);
  insertHashTable(&th, 106);
  insertHashTable(&th, 205);
  printf("\n\nTabela apos insercoes: \n");
  print(&th);

  printf("\n\nBuscando elementos: \n");
  search(&th, 14);
  search(&th, 205);

  removeElement(&th, 205);
  removeElement(&th, 7);
  removeElement(&th, 106);
  printf("\n\nTabela apos remocoes: \n");
  print(&th);

  return 0;
}