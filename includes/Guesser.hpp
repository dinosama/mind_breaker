/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guesser.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:55:32 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 08:57:24 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESSER_HPP
# define GUESSER_HPP

# include "mind_breaker.hpp"

class Guess;

class   Guesser
{
    private:
        Guess			*guesses;
		Guess			*actual_guess;
        int             score[2];
        int				guess_nbr;
		int				tries;
		int				max_try;
        int				positions;
		int				colors;
    public:
        Guesser(int max_try, int positions, int colors);
        ~Guesser();
        void    setColors(int colors);
        void    setTry(int max_try);
        void    setPositions(int positions);
        Guess   *getGuesses(void);
        void	showGuesses(void);
};

#endif