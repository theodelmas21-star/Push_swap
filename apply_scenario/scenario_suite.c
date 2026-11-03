/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:21:22 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 11:15:56 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

t_scenario	initialise_scenario(void)
{
	t_scenario	scenario;

	scenario.node = NULL;
	scenario.ra = 0;
	scenario.rb = 0;
	scenario.rra = 0;
	scenario.rrb = 0;
	scenario.type = UU;
	scenario.total = 0;
	return (scenario);
}

void	suite_verif_type(t_scenario best, t_stack **a, t_stack **b)
{
	if (best.type == DD)
	{
		while (best.rra != 0 && best.rrb != 0)
		{
			rrr(a, b);
			best.rra--;
			best.rrb--;
		}
		while (best.rra-- != 0)
			rra(a);
		while (best.rrb-- != 0)
			rrb(b);
		pa(a, b);
	}
	if (best.type == DU)
	{
		while (best.rb-- != 0)
			rb(b);
		while (best.rra-- != 0)
			rra(a);
		pa(a, b);
	}
	return ;
}

void	verif_type(t_scenario best, t_stack **a, t_stack **b)
{
	if (best.type == UU)
	{
		while (best.ra != 0 && best.rb != 0)
		{
			rr(a, b);
			best.ra--;
			best.rb--;
		}
		while (best.ra-- != 0)
			ra(a);
		while (best.rb-- != 0)
			rb(b);
		pa(a, b);
	}
	if (best.type == UD)
	{
		while (best.rrb-- != 0)
			rrb(b);
		while (best.ra-- != 0)
			ra(a);
		pa(a, b);
	}
	suite_verif_type(best, a, b);
}
