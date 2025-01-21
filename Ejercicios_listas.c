#include "push_swap.h"

typedef struct s_node
{
    char *data;
    struct s_node *next;
    struct s_node *prev;
} t_node;

t_node *ft_node_new(char *content)
{
    t_node *n;

    n = (t_node *)malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->data = content;
    n->next = NULL;
    n->prev = NULL;
    return (n);
}

void enlazarNodo(t_node **nodo, t_node *nuevo)
{
    t_node *recorrido = *nodo;

    if (*nodo == NULL)
    {
        *nodo = nuevo;
        nuevo->prev = NULL;
        nuevo->next = NULL;
    }
    else
    {
        while (recorrido->next != NULL)
        {
            recorrido = recorrido->next;
        }
        recorrido->next = nuevo;
        nuevo->prev = recorrido;
        nuevo->next = NULL;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    t_node *list = NULL;
    t_node *nodo = NULL;

    while (argc > i)
    {
        nodo = ft_node_new(strdup(argv[i]));
        enlazarNodo(&list, nodo);
        i++;
    }

    printf("Lista hacia adelante\n");
    t_node *tem = list;
    while (tem)
    {
        printf("%s\n", tem->data);
        tem = tem->next;
    }

    printf("Lista hacia atras\n");
    tem = list;
    while (tem && tem->next != NULL)
    {
        tem = tem->next;
    }
    while (tem)
    {
        printf("%s\n", tem->data);
        tem = tem->prev;
    }
    return (0);
}