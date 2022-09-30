/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_breaker.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 04:52:26 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 21:10:21 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIND_BREAKER_HPP
# define MIND_BREAKER_HPP

# include <iostream>
# include <math.h>
# include "Pegs.hpp"
# include "Guesser.hpp"
# include "Guess.hpp"

class Pegs;
class Guesser;
class Guess;

int			ft_isnum(int nb);
long long	ft_longatoi(const char *str);
long long	*parser(int ac, char **av);


#endif