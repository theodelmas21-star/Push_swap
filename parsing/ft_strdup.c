/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:08:15 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:37 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*global;

	i = 0;
	while (s[i])
		i++;
	global = malloc(sizeof(char) * (i + 1));
	if (!global)
		return (NULL);
	i = 0;
	while (s[i])
	{
		global[i] = s[i];
		i++;
	}
	global[i] = '\0';
	return (global);
}
