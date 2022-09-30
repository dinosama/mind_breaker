/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_breaker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:23:44 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 22:03:34 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

int     main(int ac, char **av)
{
    long long     *tab;

    tab = parser(ac, av);
    if (!tab)
    {
        delete[] tab;
        return (1);
    }
    if (tab[1] > 7 || tab[0] > 10)
    {
        std::cout << "max arguments value is 10 for colors and 7 for positions to prevent crashes." << std::endl;
        delete[] tab;
        return (0);
    }
    Guesser     guesser(tab[2], tab[1], tab[0]);
    guesser.guess();
    delete[] tab;
    return (0);
}