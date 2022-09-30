/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_breaker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:23:44 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 20:31:22 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

int     main(int ac, char **av)
{
    long long     *tab;

    tab = parser(ac, av);
    if (!tab)
        return (1);
    Guesser     guesser(tab[2], tab[1], tab[0]);
    guesser.guess();
    delete[] tab;
    return (0);
}