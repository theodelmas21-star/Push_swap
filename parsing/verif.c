/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:31:40 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:56:06 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	boucle(t_stack *temp, int *tab)
{
	int	j;
	int	i;

	i = 1;
	while (temp != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (temp->content == tab[j])
				return (0);
			j++;
		}
		tab[i] = temp->content;
		i++;
		temp = temp->next;
	}
	return (1);
}

int	decoupeverif(t_stack **global, int i)
{
	int		*tab;
	t_stack	*temp;

	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (0);
	temp = *global;
	tab[0] = temp->content;
	temp = temp->next;
	if (boucle(temp, tab) == 0)
		return (free(tab), 0);
	return (free(tab), 1);
}

int	verif(t_stack **global)
{
	unsigned long	i;
	t_stack			*temp;

	i = 0;
	temp = *global;
	while (temp != NULL)
	{
		if (temp->content > INT_MAX || temp->content < INT_MIN)
			return (0);
		i++;
		temp = temp->next;
	}
	if (decoupeverif(global, i) == 0)
		return (0);
	return (1);
}
