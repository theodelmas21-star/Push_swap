/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:35:24 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:59:23 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

static t_stack	*find_node_before_min(t_stack *a)
{
	t_stack	*copy;
	int		min_rank;

	if (!a)
		return (NULL);
	min_rank = find_min(a);
	if (a->rank == min_rank)
		return (NULL);
	copy = a;
	while (copy->next != NULL)
	{
		if (copy->next->rank == min_rank)
			return (copy);
		copy = copy->next;
	}
	return (NULL);
}

static t_stack	*find_best_position(t_stack *a, t_stack *node)
{
	t_stack	*copy;
	t_stack	*best;

	copy = a;
	best = NULL;
	while (copy != NULL)
	{
		if (copy->rank < node->rank)
		{
			if (!best || copy->rank > best->rank)
				best = copy;
		}
		copy = copy->next;
	}
	return (best);
}

t_stack	*find_position(t_stack *node, t_stack *a)
{
	int	min_rank;
	int	max_rank;

	if (!a || !node)
		return (NULL);
	min_rank = find_min(a);
	max_rank = find_max(a);
	if (node->rank < min_rank || node->rank > max_rank)
		return (find_node_before_min(a));
	return (find_best_position(a, node));
}

int	find_position_index(t_stack *a, t_stack *node)
{
	t_stack	*temp;
	t_stack	*fp;
	int		i;

	if (!a || !node)
		return (0);
	fp = find_position(node, a);
	if (!fp)
		return (0);
	temp = a;
	i = 0;
	while (temp != NULL && temp != fp)
	{
		temp = temp->next;
		i++;
	}
	if (temp == fp)
		return (i + 1);
	return (0);
}
