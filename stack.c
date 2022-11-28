// Nome: Breno Soares Alves
// Matricula: 2211100022

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  char data;
  struct stack *next;
} Stack;

void insertNode(Stack **head, int value)
{
  Stack *new = malloc(sizeof(Stack));

  new->data = value;
  new->next = (*head);
  (*head) = new;
}

int removeNode(Stack **head)
{
  char res;
  Stack *top;

  top = *head;
  res = top->data;
  *head = top->next;
  free(top);
  return res;
}

int verifyPair(char c1, char c2)
{
  if (c1 == '(' && c2 == ')')
    return 1;
  else if (c1 == '{' && c2 == '}')
    return 1;
  else if (c1 == '[' && c2 == ']')
    return 1;
  else
    return 0;
}

int verifyBrackets(char arr[])
{
  int i = 0;

  Stack *stack = NULL;

  while (arr[i])
  {
    if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[')
      insertNode(&stack, arr[i]);

    if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']')
    {
      if (stack == NULL)
        return 0;
      else if (!verifyPair(removeNode(&stack), arr[i]))
        return 0;
    }
    i++;
  }
  if (stack == NULL)
    return 1; // correct
  else
    return 0; // incorrect
}

int main()
{
  char characters[100] = "(){[]}";

  if (verifyBrackets(characters))
    printf("Correto \n");
  else
    printf("Incorreto \n");
  return 0;
}
