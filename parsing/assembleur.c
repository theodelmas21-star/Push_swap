/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembleur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:36:45 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 12:09:28 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*assembleur(char **av)
{
	int		i;
	char	*def;

	i = 1;
	def = malloc(1);
	if (!def)
		return (NULL);
	def[0] = '\0';
	while (av[i] != NULL)
	{
		def = assembleur_core(def, av, i);
		if (!def)
			return (NULL);
		i++;
	}
	return (def);
}

int	errorcase(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '-'
			&& s[i] != '+')
			return (0);
		if ((s[i] == '-' && s[i + 1] == '-') || (s[i] == '-' && s[i
					+ 1] == '+'))
			return (0);
		if ((s[i] == '+' && s[i + 1] == '-') || (s[i] == '+' && s[i
					+ 1] == '+'))
			return (0);
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
}

char	*ft_free_all_assembleur(char **global)
{
	int	i;

	i = 0;
	while (global[i])
	{
		free(global[i]);
		i++;
	}
	free(global);
	return (NULL);
}

char	**decoupetrieur(char **av)
{
	char	*s;
	char	**global;
	int		i;

	i = 0;
	s = assembleur(av);
	if (!s)
		return (NULL);
	if (errorcase(s) == 0 || second_errorcase(s) == 0)
		return (free(s), NULL);
	global = ft_split(s, ' ');
	if (!global)
		return (free(s), NULL);
	free(s);
	return (global);
}

t_stack	*trieur(char **av)
{
	char	**global;
	t_stack	*a;

	global = decoupetrieur(av);
	if (!global)
		return (NULL);
	if (ft_atoi(global[0]) == 0 && verif_0(global[0]) != 0)
		return (ft_free_all_assembleur(global), NULL);
	a = ft_lstnew(ft_atoi(global[0]), 0);
	if (!a)
		return (ft_free_all_assembleur(global), NULL);
	a = trieur_core(a, global);
	if (!a)
		return (ft_free_all_assembleur(global), NULL);
	if (verif(&a) == 0)
		return (ft_free_all_assembleur(global), ft_lstclear(&a), NULL);
	return (ft_free_all_assembleur(global), a);
}
