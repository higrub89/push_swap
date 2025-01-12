#include "push_swap.c"

int is_valid_number(char *s)
{
    int i = 0;
    int len = strlen(s);

    if (!s || len == 0)
        return (0);

    // Eliminar espacios al principio
    while (isspace(s[i]))
        i++;

    // Eliminar espacios al final
    while (isspace(s[len - 1]))
        len--;

    // Verificar que la cadena no quede vacía después de eliminar espacios
    if (i == len)
        return (0);

    // Si el primer carácter es '+' o '-', permitirlo y mover el índice
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Si la cadena contiene solo el signo y no hay más caracteres, es inválida
    if (i == len)
        return (0);

    // Asegurarse de que todos los caracteres restantes sean dígitos
    while (i < len)
    {
        if (!isdigit(s[i]))
            return (0);
        i++;
    }

    return (1);
}

int is_duplicates_number(int *arr, int size)
{
    int i = 0;
    int j;

    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int *numbers;
    int i = 1;
    long num;
    char *endptr;

    if (argc < 2)
    {
        printf("Error: No raguments provided\n");
        return (1);
    }

    numbers = malloc((argc - 1) * sizeof(int));
    if (!numbers)
    {
        printf("ERROR: Memory allocation failed\n");
        return (1);
    }

    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
        {
            printf("ERROR: Invalid argments\n");
            free(numbers);
            return (1);
        }
        num = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0')
        {
            printf("ERROR: invalid number format '%s'\n", argv[i]);
            free(numbers);
            return (1);
        }

        if (num < INT_MIN || num > INT_MAX)
        {
            printf("Error: Arguments '%s' out of range\n", argv[i]);
            free(numbers);
            return (1);
        }
        numbers[i - 1] = (int)num;
        i++;
    }

    if (is_duplicates_number(numbers, argc - 1))
    {
        printf("ERROR: DUPLICATE NUMBERS\n");
        free(numbers);
        return (1);
    }

    printf ("ALL ARGUMENTS ARE VALID\n");
    free(numbers);
    return (0);
}