// Nome: Breno Soares Alves
// Matricula: 2211100022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct plane
{
  char callsign[10];
  struct plane *next;
} Plane;

typedef struct queue
{
  Plane *first;
  Plane *last;
} Queue;

// Initialize the queue
Queue *createQueue()
{
  Queue *q = malloc(sizeof(Queue));
  q->first = NULL;
  q->last = NULL;
  return q;
}

// Get the queue size
int countPlanes(Queue *q)
{
  int count = 0;
  Plane *aux;
  for (aux = q->first; aux != NULL; aux = aux->next)
  {
    count++;
  }
  return count;
}

// Add a plane to the queue
void insertOnQueue(Queue *q, char callsign[])
{
  Plane *new = malloc(sizeof(Plane));
  strcpy(new->callsign, callsign);
  new->next = NULL;

  if (q->first == NULL)
  {
    q->first = new;
    q->last = new;
  }
  else
  {
    q->last->next = new;
    q->last = new;
  }
}

// Remove the first plane from the queue
void clearTakeOff(Queue *q)
{
  if (countPlanes(q) > 0)
  {
    Plane *aux = q->first;
    q->first = q->first->next;
    free(aux);
    return;
  }
  printf("No planes in queue");
}

// Print the queue
void printPlanes(Queue *q)
{
  if (countPlanes(q) == 0)
  {
    printf("No planes in queue");
    return;
  }
  Plane *aux;
  for (aux = q->first; aux != NULL; aux = aux->next)
  {
    printf("Plane Callsign: %s\n", aux->callsign);
  }
}

// Print the first plane in the queue
void printFirstPlane(Queue *q)
{
  if (countPlanes(q) == 0)
  {
    printf("No planes in queue");
    return;
  }
  Plane *aux = q->first;
  printf("Plane Callsign: %s\n", aux->callsign);
}

int main()
{
  Queue *SBCH = createQueue();

  insertOnQueue(SBCH, "GLO1295");
  countPlanes(SBCH);

  clearTakeOff(SBCH);

  insertOnQueue(SBCH, "TAM3831");
  countPlanes(SBCH);

  clearTakeOff(SBCH);

  insertOnQueue(SBCH, "AZU2898");
  countPlanes(SBCH);

  insertOnQueue(SBCH, "GLO1297");
  countPlanes(SBCH);

  clearTakeOff(SBCH);

  insertOnQueue(SBCH, "TAM3515");
  countPlanes(SBCH);

  printFirstPlane(SBCH);
  clearTakeOff(SBCH);
  clearTakeOff(SBCH);

  printPlanes(SBCH);

  return 0;
}