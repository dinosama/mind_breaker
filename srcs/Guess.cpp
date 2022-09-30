/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:05:19 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 13:28:55 by aaapatou         ###   ########.fr       */
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
	//std::cout << number << " : ";
	while (i < positions)
	{
		this->answer[i] = answer[i];
		std::cout << answer[i];
		i++;
	}
	//std::cout << std::endl;
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
		out << (char)(answer[i] + 65);
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

void	Guess::generatePegs(Guess &other)
{
	int		black;
	int		white;
	int		i;
	int		j;
	int		positions = other.getPositions();
	int		answer_copy[positions];
	int		*answer = other.getAnswer();

	//std::cout << *this << " " << other << std::endl;
	i = 0;
	while (i < positions)
	{
		answer_copy[i] = answer[i];
		i++;
	}
	black = 0;
	white = 0;
	i = 0;
	while (i < positions)
	{
		if (answer_copy[i] == this->answer[i])
		{
			black++;
			answer_copy[i] = 0;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < positions)
	{
		while (j < positions)
		{
			if (answer_copy[j] == this->answer[i])
			{
				white++;
				answer_copy[j] = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	//std::cout << black << " " << white << std::endl;
	this->pegs.setPegs(black, white);
}