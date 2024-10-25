/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:54:22 by ctommasi          #+#    #+#             */
/*   Updated: 2024/10/08 12:54:25 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc_z(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = malloc(nmemb * size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb)
		temp[i++] = '\0';
	return (temp);
}

char	*ft_strjoin_free(char *total_chars, char *temp)
{
	char	*res;
	size_t	i;
	size_t	total_len;
	size_t	temp_len;

	if (!total_chars || !temp)
		return (NULL);
	total_len = ft_strlen(total_chars);
	temp_len = ft_strlen(temp);
	res = malloc(total_len + temp_len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		res[i] = total_chars[i];
		i++;
	}
	while (i < total_len + temp_len)
	{
		res[i] = temp[i - total_len];
		i++;
	}
	res[i] = '\0';
	return (free(total_chars), res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
