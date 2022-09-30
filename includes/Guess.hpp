/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:57:42 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 21:06:38 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESS_HPP
# define GUESS_HPP

# include "mind_breaker.hpp"

class	Guess			// represent one guess among all guesses
{
    private:
        int     *answer;
        int     state;
        Pegs	pegs;
		int		*g_scores;
		int		g_score;
		int		positions;
		Guesser	*guesser;
    public:
		Guess();
		Guess(const Guess &copy);
		~Guess();
		void	initialize(int *answer, int state, Guesser *guesser, int positions, int number);
		Guess	&operator=(const Guess& op);
		Guesser	*getGuesser(void) const ;
		int		getPositions(void) const ;
		int		*getAnswer(void);
		Pegs	&getPegs(void);
		void	setState(int state);
		void	setGscores(int *tab);
		void	setGscore(int score);
		int		getScore(void);
		int		getState(void);
		bool	operator==(Guess &rhs);
		bool	operator==(int *rhs);
		bool	operator!=(int *rhs);
		bool	operator<(Guess &rhs);
		void	generatePegs(Guess *guess);
};

std::ostream    &operator<<(std::ostream & out, Guess & guess);

#endif
