/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_errorcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:00:39 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 14:56:35 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	second_errorcase(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && i != 0)
		{
			if ((s[i - 1] >= '0') && (s[i - 1] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}

char	*assembleur_core(char *def, char **av, int i)
{
	char	*temp;

	temp = def;
	def = ft_strjoin(def, av[i]);
	free(temp);
	if (!def)
		return (NULL);
	if (av[i + 1] != NULL)
	{
		temp = def;
		def = ft_strjoin(def, " ");
		free(temp);
		if (!def)
			return (NULL);
	}
	return (def);
}

t_stack	*trieur_core(t_stack *a, char **global)
{
	t_stack	*temp;
	int		i;

	i = 1;
	while (global[i])
	{
		if (ft_atoi(global[i]) == 0 && verif_0(global[i]) != 0)
			return (ft_lstclear(&a), NULL);
		temp = ft_lstnew(ft_atoi(global[i]), i);
		if (!temp)
			return (ft_lstclear(&a), NULL);
		ft_lstadd_back(&a, temp);
		i++;
	}
	return (a);
}
