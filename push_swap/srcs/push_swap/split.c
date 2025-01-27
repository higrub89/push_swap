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
	bool	inside_word;
	int		count;

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
	char	*next_word;
	int		len;
	int		i;

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

char	**split_push_swap(char *s, char c)
{
	char	**result_array;
	int		words_count;
	int		cursor;
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
			while (--i >= 0)
				free(result_array[i]);
			free(result_array);
			return (NULL);
		}
	}
	result_array[i] = NULL;
	return (result_array);
}
