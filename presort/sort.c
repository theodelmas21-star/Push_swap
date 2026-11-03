/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:30:10 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:57:47 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

int	fastway(t_stack **global, t_chunks *buckets)
{
	t_stack	*high;
	t_stack	*low;

	high = *global;
	low = *global;
	if (!low || !high)
		return (0);
	while (low->next != NULL)
		low = low->next;
	while (high->rank > buckets->end && low->rank > buckets->end)
	{
		high = high->next;
		low = low->previous;
	}
	if (high->rank <= buckets->end)
		return (1);
	else if (low->rank <= buckets->end)
		return (2);
	return (0);
}

void	decoupesort(t_stack **global, t_chunks **buckets, t_stack **globalb,
		int i)
{
	if (!(*global))
		return ;
	if (fastway(global, buckets[i]) == 1)
	{
		while ((*global)->rank > buckets[i]->end)
			ra(global);
		pb(global, globalb);
		if ((*globalb)->rank < buckets[i]->mid)
			rb(globalb);
	}
	else
	{
		while ((*global)->rank > buckets[i]->end)
			rra(global);
		pb(global, globalb);
		if ((*globalb)->rank < buckets[i]->mid)
			rb(globalb);
	}
}

void	first_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->rank;
	mid = (*a)->next->rank;
	bot = (*a)->next->next->rank;
	if (top > mid && mid < bot && bot > top)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && top > bot && mid < bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

t_stack	*presort(t_stack **a, t_chunks **buckets)
{
	int		i;
	int		j;
	t_stack	*b;
	int		len;

	i = 0;
	b = NULL;
	len = stack_len(*a);
	while (buckets[i] && len > 3)
	{
		j = 0;
		while (j < buckets[i]->size && *a && len > 3)
		{
			decoupesort(a, buckets, &b, i);
			j++;
			len--;
		}
		i++;
	}
	if (len == 3)
		first_three(a);
	if (len == 2 && (*a)->rank > (*a)->next->rank)
		sa(a);
	return (b);
}
