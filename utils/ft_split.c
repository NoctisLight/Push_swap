/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:53:15 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/08 21:55:33 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *string)
{
	char *tab;
	int i;

	i = ft_strlen(string) + 1;
	tab = malloc(i);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, string, i);
	tab[i + 1] = '\0';
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static int	counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
}

static char	*extract_word(const char *s, char c, int *i)
{
	int		start;
	char	*word;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = ft_substr(s, start, *i - start);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(tab = malloc((counter(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(tab[j++] = extract_word(s, c, &i)))
			{
				free_all(tab, j - 1);
				return (NULL);
			}
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}