/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_scenario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:33:01 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 11:15:38 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

t_stack	*prefind_position(t_stack *copy, t_stack *node, t_stack *a)
{
	int	i;

	i = find_min(a);
	while (copy->rank != i)
		copy = copy->next;
	while (node->rank > copy->rank)
	{
		copy = copy->next;
		if (copy == NULL)
			copy = a;
	}
	return (copy);
}

void	apply_scenario(t_stack **a, t_stack **b)
{
	t_scenario	best;

	while (*b != NULL)
	{
		best = calcul_best(*a, *b);
		verif_type(best, a, b);
	}
	return ;
}

void	prefinal(int j, t_stack **a, t_stack *copy)
{
	int	i;

	i = find_min(*a);
	while (copy->rank != i)
	{
		copy = copy->next;
		j++;
	}
	i = stack_len(*a);
	if (j < i / 2)
	{
		while (j-- > 0)
			ra(a);
	}
	else
	{
		while (j != i)
		{
			rra(a);
			j++;
		}
	}
	return ;
}

void	final_sort(t_stack **a, t_stack **b)
{
	int		j;
	t_stack	*copy;

	j = 0;
	apply_scenario(a, b);
	copy = *a;
	prefinal(j, a, copy);
	return ;
}
