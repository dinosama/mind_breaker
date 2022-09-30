/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:29:01 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 13:15:22 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

void	ft_read_argument(int ac, char **av, long long *tab)
{
	int		arg;
	int		i;
	int		tabincr;

	arg = 1;
	tabincr = 0;
	while (arg < ac)
	{
		i = 0;
		while (av[arg][i] != 0)
		{
			while ((av[arg][i] == ' ' || av[arg][i] == '-') && av[arg][i] != 0)
				i++;
			if (ft_isnum(av[arg][i]))
			{
				tab[tabincr] = ft_longatoi(av[arg] + i);
				if (av[arg][i - 1] == '-')
					tab[tabincr] = tab[tabincr] * -1;
				tabincr++;
			}
			while (ft_isnum(av[arg][i]) && av[arg][i] != 0)
				i++;
		}
		arg++;
	}
}

int	ft_check_argument(int ac, char **av)
{
	int		arg;
	int		i;
	int		argnum;

	arg = 1;
	argnum = 0;
	while (arg < ac)
	{
		i = 0;
		while (av[arg][i] != 0)
		{
			if (ft_isnum(av[arg][i]))
				argnum++;
			while (ft_isnum(av[arg][i]) && av[arg][i] != 0)
				i++;
			while (av[arg][i] == ' ' && av[arg][i] != 0)
				i++;
			if (!(ft_isnum(av[arg][i])) && av[arg][i] != 0)
				return (-1);
		}
		arg++;
	}
	return (argnum);
}

long long	*parser(int ac, char **av)
{
	int				argnum;
	long long 		*tab;

	argnum = ft_check_argument(ac, av);
	if (argnum != 3)
		return (NULL);
	tab = new long long[argnum];
	ft_read_argument(ac, av, tab);
	return (tab);
}
