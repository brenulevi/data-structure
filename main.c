/*
 Este é um esqueleto que deve ser utilizado como base para implementação do trabalho;
    - As funções não têm os parâmetros definidos; se necessário, estes devem ser incluídos; Os tipos de retorno podem ser alterados, se necessário;
    - Devem ser respeitados os nomes atribuídos às funções e estruturas, porém, novas estruturas e funções podem ser criadas, caso julgue necessário;
    - Faça os includes necessários;
    - A organização das funções fica a critério do programador;
    - A indentação correta faz parte da nota;
    - Não são permitidas variáveis globais;
    - Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT 10 // valor fixo para a opção que finaliza a aplicação
#define CHOOSE_1 1
#define CHOOSE_2 2
#define CHOOSE_3 3
#define CHOOSE_4 4
#define CHOOSE_5 5

// Struct que representa um item de uma lista de compras armazenada em uma arvore binaria de busca
struct item
{
    char product[50];
    int qtd;
    struct item *left;
    struct item *right;
};
typedef struct item Item;

// Apresenta o primeiro menu da aplicação e retorna a opção selecionada
int menu1()
{
    int op = 0;
    printf("\nMenu principal\n");
    printf("%d - Gerenciar lista de compras A\n", CHOOSE_1);
    printf("%d - Gerenciar lista de compras B\n", CHOOSE_2);
    printf("%d - Verificar itens duplicados\n", CHOOSE_3);
    printf("%d - Sair do programa\n", EXIT);
    printf("\nDigite a opcao: ");
    scanf("%d", &op);
    return op;
}

// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
    int op = 0;
    printf("Submenu - Gerenciar lista de compras\n");
    printf("%d - Inserir item\n", CHOOSE_1);
    printf("%d - Pesquisar por produto\n", CHOOSE_2);
    printf("%d - Atualizar quantidade de produto\n", CHOOSE_3);
    printf("%d - Listar em ordem alfabética\n", CHOOSE_4);
    printf("%d - Deletar item\n", CHOOSE_5);
    printf("%d - Retornar para o menu principal\n", EXIT);
    printf("\nDigite a opcao: ");
    scanf("%d", &op);
    return op;
}

// Permite o cadastro de um item (caso o produto ainda não exista) em uma lista de compas
Item *insert(Item *root, Item *new)
{
    if (root == NULL)
        return new;

    if (strcmp(root->product, new->product) == -1)
        root->left = insert(root->left, new);
    else
        root->right = insert(root->right, new);
    return root;
}

Item *createNew()
{
    Item *new = malloc(sizeof(Item));

    printf("\nDigite o nome do produto: ");
    char new_product[50];
    scanf("%s", new_product);

    printf("\nDigite a quantidade do produto: ");
    int new_qtd;
    scanf("%d", &new_qtd);

    strcpy(new->product, new_product);
    new->qtd = new_qtd;
    new->left = NULL;
    new->right = NULL;

    return new;
}

// Permite consultar se um item está em uma lista de compras
Item *query(Item *root, char product[])
{
    while (root != NULL)
    {
        if (strcmp(root->product, product) == -1)
            root = root->right;
        else if (strcmp(root->product, product) == 1)
            root = root->left;
        else {
            return root;
        }
    }
    return NULL;
}

// Permite a atualização da quantidade de um produto (caso exista) na lista de compras
void update()
{
    printf("atualizando");
    return;
}

// Listar todos os itens da lista de compras em ordem alfabética;
void list(Item *root)
{
    if (root == NULL)
    {
        return;
    }

    list(root->left);
    printf("Nome: %s\nQuantidade: %d\n", root->product, root->qtd);
    list(root->right);
}

// Permite excluir um item de uma lista de compras
void delete()
{
    printf("deletando");
    return;
}

void intersect()
{
    printf("interseccao");
}

// Programa principal
int main()
{
    int option1;
    int option2;
    Item *rootA = NULL;
    Item *rootB = NULL;
    option1 = 0;
    while (option1 != EXIT)
    {
        option1 = menu1();

        switch (option1)
        {
        case 1: // gerenciar lista de compras A
            option2 = 0;
            while (option2 != EXIT)
            {
                printf("\n\n** Lista de Compras A **\n\n");
                option2 = menu2();
                switch (option2)
                { // operacoes sobre a arvore A

                // insert item (A)
                case 1:
                    Item *new = createNew();
                    rootA = insert(rootA, new);
                    break;

                // verify if item exist (A)
                case 2:
                    printf("\nDigite o nome do produto: ");
                    char searchKey[50];
                    scanf("%s", searchKey);

                    Item *item = query(rootA, searchKey);
                    if (item == NULL)
                    {
                        printf("\nItem não encontrado!\n");
                        break;
                    }
                    printf("\nItem encontrado!\n");
                    printf("Nome: %s\nQuantidade: %d", item->product, item->qtd);
                    break;

                // update item qtd (A)
                case 3:
                    update(rootA);
                    break;

                // list in alphabetical order (A)
                case 4:
                    list(rootA);
                    break;

                // delete item (A)
                case 5:
                    delete (rootA);
                }
            }
            break;
        case 2: // gerenciar lista de compras B
            option2 = 0;
            while (option2 != EXIT)
            {
                printf("\n\n** Lista de Compras B **\n\n");
                option2 = menu2();
                switch (option2)
                { // operacoes sobre a arvore B

                // insert item (B)
                case 1:
                    Item *new = createNew();

                    insert(rootB, new);
                    break;

                // verify if item exist (B)
                case 2:
                    Item *item = query(rootB, "Banana");
                    if (item == NULL)
                    {
                        printf("\nItem não encontrado!\n");
                        break;
                    }
                    printf("\nItem encontrado!\n");
                    printf("Nome: %s\nQuantidade: %d", new->product, new->qtd);
                    break;

                // update item qtd (B)
                case 3:
                    update(rootB);
                    break;

                // list in alphabetical order (B)
                case 4:
                    list(rootB);
                    break;

                // delete item
                case 5:
                    delete (rootB);
                }
            }
        case 3: // Visualizar itens duplicados
            intersect();
        }
    }
    return 0;
}
