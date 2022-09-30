/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guesser.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:55:32 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 21:05:36 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESSER_HPP
# define GUESSER_HPP

# include "mind_breaker.hpp"

class Guess;

class   Guesser			// Core class of mind_breaker contain all possibles guesses and sort them following Knuth's Algorithm
{
    private:
        Guess			*guesses;
		Guess			*actual_guess;
        Pegs            actual_pegs;
        int				guess_nbr;
		int				tries;
		int				max_try;
        int				positions;
		int 			colors;
    public:
        Guesser(int max_try, int positions, int colors);
        ~Guesser();
        void    setColors(int colors);
        void    setTry(int max_try);
        void    setPositions(int positions);
        Guess   *getGuesses(void);
        void	showGuesses(void);
        void	find_first_guess(void);
		bool	guess(void);
		void	sortguesses(void);
		void	find_next_guess(void);
		void	sort_next_guess(void);
};

#endif