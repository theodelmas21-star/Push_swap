/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:12:38 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 15:02:43 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*findmin(t_stack **globala, long tabmin)
{
	t_stack	*temp;
	t_stack	*memory;

	temp = (*globala);
	memory = NULL;
	while (temp != NULL)
	{
		if (tabmin < (long)temp->content)
		{
			if (memory == NULL || memory->content > temp->content)
				memory = temp;
		}
		temp = temp->next;
	}
	return (memory);
}

/*void	print_list(t_stack *global)
{
	t_stack	*curr;

	curr = global;
	while (curr != NULL)
	{
		printf("%d ", curr->content);
		curr = curr->next;
	}
}*/

int	presorted_list(t_stack *a)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!a || !a->next)
		return (0);
	curr = a->next;
	prev = a;
	while (prev->rank < curr->rank)
	{
		if (curr->next == NULL)
			return (0);
		curr = curr->next;
		prev = prev->next;
	}
	return (1);
}

int	ranking(t_stack **globala)
{
	t_stack	*temp;
	int		rankeur;
	long	tab;
	int		j;

	rankeur = 0;
	temp = (*globala);
	tab = -2147483649;
	while (temp->next != NULL)
		temp = temp->next;
	j = temp->rank + 1;
	while (rankeur < j)
	{
		temp = findmin(globala, tab);
		temp->rank = rankeur;
		rankeur++;
		tab = temp->content;
	}
	if (presorted_list(*globala) == 0)
		return (0);
	return (j);
}
