/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:44 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:30 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static char	**ft_free_all(char **global, int l)
{
	while (l > 0)
	{
		free(global[--l]);
	}
	free(global);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[i] != c && s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*ft_temp(char const *s, char c, int i)
{
	char	*temp;
	int		count;
	int		j;

	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	temp = malloc(sizeof(char) * (j + 1));
	if (!temp)
		return (NULL);
	count = 0;
	while (count < j)
	{
		temp[count] = s[i];
		count++;
		i++;
	}
	temp[count] = '\0';
	return (temp);
}

static int	taille_i(const char *s, char c, int i)
{
	int	check;

	check = 0;
	if (s[i] != c && s[i] != '\0')
		check = 1;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (check == 0 && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		l;
	char	*temp;
	char	**global;

	i = 0;
	l = 0;
	global = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!global)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			temp = ft_temp(s, c, i);
			if (temp == NULL)
				return (ft_free_all(global, l));
			global[l++] = temp;
		}
		i = taille_i(s, c, i);
	}
	global[l] = NULL;
	return (global);
}
