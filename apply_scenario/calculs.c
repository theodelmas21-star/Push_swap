/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:46:17 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 11:15:22 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

int	calculs_total(int cost_uu, int cost_ud, int cost_du, int cost_dd)
{
	int	min;

	min = cost_uu;
	if (cost_ud < min)
		min = cost_ud;
	if (cost_du < min)
		min = cost_du;
	if (cost_dd < min)
		min = cost_dd;
	return (min);
}

t_scenario	calculs_rotations(t_data data, t_stack *node)
{
	t_scenario	scenario;
	int			position_a;

	position_a = find_position_index(data.a, node);
	scenario = initialise_scenario();
	scenario.node = node;
	scenario.rb = data.index;
	scenario.rrb = data.len_b - data.index;
	scenario.ra = position_a;
	scenario.rra = data.len_a - position_a;
	return (scenario);
}

t_type	calculs_type(int cost_uu, int cost_ud, int cost_du, int cost_dd)
{
	t_type	type;
	int		min;

	min = cost_uu;
	type = UU;
	if (cost_ud < min)
	{
		type = UD;
		min = cost_ud;
	}
	if (cost_du < min)
	{
		type = DU;
		min = cost_du;
	}
	if (cost_dd < min)
	{
		type = DD;
		min = cost_dd;
	}
	return (type);
}

t_scenario	calculs_scenario(t_scenario scenario)
{
	int	cost_uu;
	int	cost_ud;
	int	cost_du;
	int	cost_dd;

	if (scenario.ra > scenario.rb)
		cost_uu = scenario.ra;
	else
		cost_uu = scenario.rb;
	if (scenario.rra > scenario.rrb)
		cost_dd = scenario.rra;
	else
		cost_dd = scenario.rrb;
	cost_ud = scenario.ra + scenario.rrb;
	cost_du = scenario.rra + scenario.rb;
	scenario.type = calculs_type(cost_uu, cost_ud, cost_du, cost_dd);
	scenario.total = calculs_total(cost_uu, cost_ud, cost_du, cost_dd);
	return (scenario);
}

t_scenario	calcul_best(t_stack *a, t_stack *b)
{
	t_scenario	best;
	t_scenario	scenario;
	t_stack		*node;
	t_data		data;

	data.len_b = stack_len(b);
	data.len_a = stack_len(a);
	data.index = 0;
	data.a = a;
	node = b;
	best.total = INT_MAX;
	while (node != NULL)
	{
		scenario = calculs_rotations(data, node);
		scenario = calculs_scenario(scenario);
		if (scenario.total < best.total)
			best = scenario;
		node = node->next;
		data.index++;
	}
	return (best);
}
