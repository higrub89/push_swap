/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:57:41 by rhiguita          #+#    #+#             */
/*   Updated: 2025/01/05 12:57:45 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../inc/push_swap.h"

static int	count_words(char *s, char c) 
{
	int		count; 
	bool	inside_word; 

	count = 0;
	while (*s) 
	{
		inside_word = false; 
		while (*s == c) 
			++s; 
		while (*s != c && *s) 
		{
			if (!inside_word) 
			{
				++count; 
				inside_word = true; 
			}
			++s; 
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor) 
{
	char		*next_word; 
	int			len; 
	int			i; 

	len = 0;
	i = 0;
	while (s[*cursor] == c) 
		++(*cursor);
	while ((s[*cursor + len] != c) && s[*cursor + len]) 
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1); 
	if (!next_word) 
		return (NULL);
	while ((s[*cursor] != c) && s[*cursor]) 
		next_word[i++] = s[(*cursor)++]; 
	next_word[i] = '\0'; 
	return (next_word);
}

char **split_push_swap(char *s, char c)
{
	int		words_count; 
	char	**result_array;
    int     cursor;
	int		i; 

    cursor = 0;
	i = 0;
	words_count = count_words(s, c);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1)); 
	if (!result_array) 
		return (NULL);
	while (words_count-- > 0) 
	{
		result_array[i++] = get_next_word(s, c, &cursor);
		if (!result_array[i - 1])
        {
            while (--i  >= 0)
                free(result_array[i]);
            free(result_array);
            return (NULL);
        }    
	}
	result_array[i] = NULL; 
	return (result_array);
}

/*
static int ft_isspace(char c) 
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

static long ft_strtol(const char *str, char **endptr, int base) {
    long result = 0;
    int sign = 1;

    // Ignorar espacios iniciales
    while (ft_isspace(*str)) {
        str++;
    }

    // Manejar signo
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convertir los caracteres en números
    while (*str >= '0' && *str <= '9') {
        result = result * base + (*str - '0');
        str++;
    }

    // Configurar el endptr si no es NULL
    if (endptr) {
        *endptr = (char *)str;
    }

    return sign * result;
}

static char *ft_strcpy(char *dest, const char *src) {
    char *start = dest;
    while ((*dest++ = *src++) != '\0');
    return start;
}


static void remove_spaces(char *str) {
    char *i = str, *j = str;
    while (*i != '\0') {
        if (!ft_isspace(*i))
        {
            *j++ = *i;
        }
        i++;
    }
    *j = '\0';
}*/
/*
static void process_individual_numbers(const char *str) {
    const char *current = str;
    char *endptr;

    while (*current != '\0') {
        // Ignorar espacios al inicio
        while (ft_isspace(*current)) {
            current++;
        }

        // Intentar convertir un número
        long num = ft_strtol(current, &endptr, 10);

        // Si se ha convertido un número válido
        if (endptr != current) {
             printf("%ld\n", num);
            current = endptr; // Continuar desde el final del número
        } else {
            break; // Si no se puede convertir nada más, detener
        }
    }
}*/

/* Función para procesar argumentos
void process_arguments(int argc, char *argv[]) {
    int i = 1;
    while (i < argc) 
    {
        process_individual_numbers(argv[i]);
        i++; // Procesar cada argumento
    }
}

int main (int c, char **g)
{
    while (c < 2)
    {
        printf("ERROR TERMINAL");
        return (1);
    }

    process_arguments(c, g);
    return (0);   
}

void process_arguments(int argc, char *argv[], t_stack_node **a) {
    for (int i = 1; i < argc; i++) {
        const char *current = argv[i];
        char *endptr;

        while (*current != '\0') {
            // Ignorar espacios
            while (ft_isspace(*current)) {
                current++;
            }

            // Intentar convertir un número
            long num = ft_strtol(current, &endptr, 10);

            // Verificar si el número es válido
            if (endptr != current) {
                // Validar el rango de los números
                if (num < INT_MIN || num > INT_MAX) {
                    fprintf(stderr, "Error: número fuera de rango\n");
                    free_stack(a);
                    exit(EXIT_FAILURE);
                }

                // Agregar el número al stack
                stack_add_back(a, (int)num);

                // Continuar desde el final del número
                current = endptr;
            } else {
                break;
            }
        }
    }
}*/