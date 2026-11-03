/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:33:13 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:08 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>

int	min(const char *nptr)
{
	int		i;
	char	*str;

	i = 0;
	str = "-2147483648";
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == str[i] && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	verif_0(const char *nptr)
{
	int	sign;

	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr == '0')
		nptr++;
	if (*nptr != '\0')
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int		sign;
	long	a;

	sign = 1;
	a = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + (*nptr - '0');
		nptr++;
		if ((a > 2147483648 && sign == -1) || (a >= 2147483648 && sign == 1))
			return (0);
	}
	return (a * sign);
}
