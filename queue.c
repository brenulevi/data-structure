// Nome: Breno Soares Alves
// Matricula: 2211100022

#include <stdio.h>
#include <stdlib.h>

typedef struct queueItem
{
    int id;
    char value;
    struct queueItem *next;
} Item;

typedef struct queue
{
    Item *first;
    Item *last;
} Queue;

// Initialize queue
Queue *initializeQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

// Count nodes
int countNode(Queue *queue)
{
    int count = 0;
    Item *aux;
    for (aux = queue->first; aux != NULL; aux = aux->next)
    {
        count++;
    }
    return count;
}

// Verify if the queue are in crescent order (ASCII)
int verifyCrescent(Queue *queue)
{
    Item *aux;
    Item *previous;
    previous = queue->first;
    for (aux = queue->first->next; aux != NULL; aux = aux->next)
    {
        if (aux->value < previous->value)
        {
            return 0;
        }
        previous = aux;
    }
    return 1;
}

// Delete from start
void deleteNode(Queue *queue)
{
    Item *aux = queue->first;
    queue->first = queue->first->next;
    free(aux);
}

// Insert on end
Item *insertNode(Queue *queue, char value)
{
    if (value != '*')
    {
        Item *new = malloc(sizeof(Item));
        new->value = value;
        new->next = NULL;
        if (countNode(queue) == 0)
        {
            new->id = 0;
            queue->first = new;
            queue->last = new;
        }
        else
        {
            new->id = queue->last->id + 1;
            queue->last->next = new;
            queue->last = new;
        }
        return new;
    }
    else
    {
        deleteNode(queue);
    }
}

// Get a copy of the queue
Queue *copyQueue(Queue *queue)
{
    Queue *copiedQueue = malloc(sizeof(Queue));
    Item *aux;
    for (aux = queue->first; aux != NULL; aux = aux->next)
    {
        Item *new = insertNode(copiedQueue, aux->value);
        new->id = aux->id;
    }
    return copiedQueue;
}

// Print all elements in queue
void printQueue(Queue *queue)
{
    if (countNode(queue) == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    Item *aux;
    for (aux = queue->first; aux != NULL; aux = aux->next)
    {
        printf("%d - %c\n", aux->id, aux->value);
    }
}

// Destroy all elements in queue
void destroyQueue(Queue *queue)
{
    Item *aux;
    while (queue->first != NULL)
    {
        aux = queue->first;
        queue->first = queue->first->next;
        free(aux);
    }
    queue->last = NULL;
}

int main()
{
    Queue *myQueue = initializeQueue();

    insertNode(myQueue, 'e');
    insertNode(myQueue, '*');
    insertNode(myQueue, 's');
    insertNode(myQueue, 'a');
    insertNode(myQueue, 'b');
    insertNode(myQueue, 'c');
    insertNode(myQueue, '*');
    insertNode(myQueue, 'd');

    printQueue(myQueue);

    printf("\n");

    Queue *myCopyQueue = copyQueue(myQueue);
    printQueue(myCopyQueue);

    destroyQueue(myQueue);

    return 0;
}