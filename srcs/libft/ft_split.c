/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:05:58 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/06 12:17:37 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	while (i > 0)
	{
		free(arr[(i--) - 1]);
	}
	free(arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;	

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*create_arr(char const *s, char c, int *x)
{
	size_t	i;
	size_t	len;
	size_t	start;
	char	*word;

	while (s[*x] && s[*x] == c)
		(*x)++;
	start = *x;
	len = 0;
	while (s[*x + len] && s[*x + len] != c)
		len++;
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i + start];
		i++;
	}
	word[len] = '\0';
	*x += len;
	return (word);
}

static void	add_to_arr(char **arr, char const *word, char c, size_t count)
{
	size_t	i;
	int		x;

	x = 0;
	i = 0;
	while (i < count)
	{
		arr[i] = create_arr(word, c, &x);
		if (!arr[i])
		{
			ft_free(arr);
			return ;
		}
		i++;
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	add_to_arr(arr, s, c, words);
	return (arr);
}
