/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:31:33 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:43 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*global;

	if (!s1 || !s2)
		return (ft_strdup(""));
	global = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!global)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		global[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		global[i++] = s2[j++];
	global[i] = '\0';
	return (global);
}
