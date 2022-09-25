/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:57:42 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/25 18:04:38 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESS_HPP
# define GUESS_HPP

# include "mind_breaker.hpp"

class	Guess()
{
    private:
        int     *answer;
        int     state;
        int     score[2];
		int		*g_scores;
    public:
		Guess();
		Guess(const Guess &copy);
		~Guess();
		Guess	&operator=(const Guess& op);
}

#endif