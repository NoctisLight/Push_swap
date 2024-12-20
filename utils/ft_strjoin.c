/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:06:23 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/08 16:10:24 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	const char *tmp;

	tmp = s;
	while (*s)
		s++;
	return (s - tmp);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	
	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int i;
	unsigned int a;
	unsigned int lensrc;

    if (size == 0)
        return (ft_strlen(src));
    i = 0;
    lensrc = 0;
    while (dest[i] != '\0' || src[lensrc] != '\0')
    {
        if (dest[i] != '\0')
            i++;
        if (src[lensrc] != '\0')
            lensrc++;
    }
    if (size <= i)
        return (lensrc + size);
    a = i;
    while (a < size - 1 && src[a - i] != '\0')
    {
        dest[a] = src[a - i];
        a++;
    }
    dest[a] = '\0';
    return (i + lensrc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*string;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	ft_strlcat(string, (char *)s2, len + 1);
	return (string);
}