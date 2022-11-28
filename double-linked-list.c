// Nome: Breno Soares Alves
// Matricula: 2211100022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
  int id;
  char name[31];
  double salary;
  struct employee *next;
};

typedef struct employee Employee;

// finished
Employee *insertNodeOnStart(Employee *first, int id, char name[], double salary)
{
  // insert node on start and return the first element in list
  Employee *aux;
  aux = malloc(sizeof(Employee));
  aux->id = id;
  strcpy(aux->name, name);
  aux->salary = salary;
  aux->next = first;
  first = aux;

  return first;
}

// finished
Employee *insertNodeOnEnd(Employee *first, int id, char name[], double salary)
{
  // insert node on end and return the first element in list
  Employee *aux;
  Employee *new = malloc(sizeof(Employee));
  new->id = id;
  strcpy(new->name, name);
  new->salary = salary;
  new->next = NULL;

  for (aux = first; aux != NULL; aux = aux->next)
  {
    if (aux->next == NULL)
    {
      aux->next = new;
      break;
    }
  }

  return first;
}

// finished
Employee *deleteNode(Employee *first, int idDelete)
{
  // delete node with id parameter and return the first element in list
  Employee *aux, *previous;
  for (aux = first; aux != NULL; aux = aux->next)
  {
    if (aux->id == idDelete)
    {
      if (aux == first)
      {
        // its the first element in list
        first = first->next;
      }
      else
      {
        previous->next = aux->next;
      }
      free(aux);
      break;
    }
    previous = aux;
  }

  return first;
}

// finished
void printList(Employee *first)
{
  // print all elements
  Employee *aux;
  if (first == NULL)
  {
    printf("Lista vazia\n");
    return;
  }
  for (aux = first; aux != NULL; aux = aux->next)
  {
    printf("Id: %d\nName: %s\nSalary: %.2f\n\n", aux->id, aux->name, aux->salary);
  }
}

// finished
void reversePrintList(Employee *aux)
{
  // this function must be recursive
  if (aux->next == NULL)
  {
    printf("Id: %d\nName: %s\nSalary: %.2f\n\n", aux->id, aux->name, aux->salary);
    return;
  }
  reversePrintList(aux->next);
  printf("Id: %d\nName: %s\nSalary: %.2f\n\n", aux->id, aux->name, aux->salary);
}

// finished
int countNodes(Employee *first)
{
  int counter;
  Employee *aux;
  for (aux = first; aux != NULL; aux = aux->next)
  {
    counter++;
  }

  return counter;
}

// finished
Employee *destroyList(Employee *first)
{
  // destroy the list (remove all employees)
  Employee *aux;
  while (first != NULL)
  {
    aux = first;
    first = first->next;
    free(aux);
  }

  return NULL;
}

int main()
{
  Employee *first = NULL;

  first = insertNodeOnStart(first, 54, "Bety", 5000);
  first = insertNodeOnEnd(first, 59, "Bill", 1500);
  // Inserir mais nodos...

  printList(first);

  reversePrintList(first);

  first = deleteNode(first, 54);

  printList(first);

  destroyList(first);

  return 0;
}