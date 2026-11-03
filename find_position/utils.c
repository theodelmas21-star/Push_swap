/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:07:09 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:54:53 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

int	stack_len(t_stack *global)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (!global)
		return (0);
	temp = global;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_max(t_stack *a)
{
	int		rankmax;
	t_stack	*copy;

	if (!a)
		return (0);
	copy = a;
	rankmax = a->rank;
	while (copy != NULL)
	{
		if (copy->rank > rankmax)
		{
			rankmax = copy->rank;
		}
		copy = copy->next;
	}
	return (rankmax);
}

int	find_min(t_stack *a)
{
	int		rankmin;
	t_stack	*copy;

	if (!a)
		return (0);
	copy = a;
	rankmin = a->rank;
	while (copy != NULL)
	{
		if (copy->rank < rankmin)
		{
			rankmin = copy->rank;
		}
		copy = copy->next;
	}
	return (rankmin);
}
