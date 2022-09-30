/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pegs.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:37:14 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 21:09:51 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEGS_HPP
# define PEGS_HPP

# include "mind_breaker.hpp"

class Pegs				// represent the answer gived by the codemaker and used to calculate multiple possibilities
{
private:
	int		black;
	int		white;
	int		positions;
public:
	Pegs();
	Pegs(int black, int white);
	~Pegs();
	void	setPegs(int black, int white, int positions);
	int		getPegsLevel();
	int		getBlack();
	int		getWhite();
	bool	operator==(Pegs &rhs);
	bool	operator!=(Pegs &rhs);
	bool	operator<(Pegs &rhs);
	bool	operator<=(Pegs &rhs);
	bool	operator>(Pegs &rhs);
	bool	operator>=(Pegs &rhs);
	Pegs	&operator=(Pegs &rhs);
};

std::ostream    &operator<<(std::ostream & out, Pegs &pegs);

#endif
