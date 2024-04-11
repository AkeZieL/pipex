/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:37:47 by mbilly            #+#    #+#             */
/*   Updated: 2023/03/16 14:43:17 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (ft_strlen(s) < start)
	{
		tmp = malloc(1);
		tmp[0] = 0;
		return (tmp);
	}
	if (start + len < ft_strlen(s))
		tmp = (char *)malloc(sizeof (*s) * len +1);
	else
		tmp = (char *)malloc(sizeof(*s) * (ft_strlen(s) - start + 1));
	if (!tmp)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
