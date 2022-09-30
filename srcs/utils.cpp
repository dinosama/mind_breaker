/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:28:02 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 07:07:41 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

int	ft_isnum(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

long long	ft_longatoi(const char *str)
{
	long long	i;
	int			neg;
	long long	stock;

	i = 0;
	neg = 1;
	stock = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (neg == -1)
			stock = (stock * 10) - (str[i] - 48);
		else
			stock = (stock * 10) + (str[i] - 48);
		i++;
	}
	return (stock);
}
