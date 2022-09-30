/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_breaker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:23:44 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 09:11:23 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

int     main(int ac, char **av)
{
    Guesser     guesser(5, 4, 6);
    int         i;

    i = 0;
    guesser.showGuesses();
    return (0);
}