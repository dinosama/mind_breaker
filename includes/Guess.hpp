/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:57:42 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 12:46:55 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESS_HPP
# define GUESS_HPP

# include "mind_breaker.hpp"

class	Guess
{
    private:
        int     *answer;
        int     state;
        Pegs	pegs;
		int		*g_scores;
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
		bool	operator==(Guess &rhs);
		bool	operator<(Guess &rhs);
		void	generatePegs(Guess &guess);
};

std::ostream    &operator<<(std::ostream & out, Guess & guess);

#endif
