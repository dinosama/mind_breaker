/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:05:19 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 10:28:05 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

Guess::Guess()
{
}

Guess::~Guess()
{
}

void	Guess::initialize(int *answer, int state, Guesser *guesser, int positions, int number)
{
	int		i = 0;
	this->state = state;
	this->positions = positions;
	this->answer = new int[positions];
	std::cout << number << " : ";
	while (i < positions)
	{
		this->answer[i] = answer[i];
		std::cout << answer[i];
		i++;
	}
	std::cout << std::endl;
}

Guesser		*Guess::getGuesser(void) const
{
	return (this->guesser);
}

int		*Guess::getAnswer(void)
{
	return (this->answer);
}

int		Guess::getPositions(void) const
{
	return (this->positions);
}

std::ostream    &operator<<(std::ostream & out, Guess & guess)
{
	int		i;
	int		*answer;
	int		positions;

	i = 0;
	positions = guess.getPositions();
	answer = guess.getAnswer();
	while (i < positions)
	{
		out << answer[i];
		i++;
	}
	return (out);
}

Pegs	&Guess::getPegs(void)
{
	return (this->pegs);
}

bool	Guess::operator==(Guess &rhs)
{
	if (this->pegs == rhs.getPegs())
		return (1);
	return (0);
}

bool	Guess::operator<(Guess &rhs)
{
	if (this->pegs < rhs.getPegs())
		return (1);
	return (0);
}