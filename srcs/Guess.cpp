/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:05:19 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 21:56:57 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

Guess::Guess()
{
	this->g_scores = NULL;
}

Guess::~Guess()
{
	delete[] this->answer;
}

void	Guess::initialize(int *answer, int state, Guesser *guesser, int positions, int number)
{
	int		i = 0;
	this->state = state;
	this->positions = positions;
	this->answer = new int[positions];
	while (i < positions)
	{
		this->answer[i] = answer[i];
		i++;
	}
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
		out << (char)(answer[i] + 96);
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

bool	Guess::operator==(int *rhs)
{
	int		i;

	i = 0;
	while (i < this->positions)
	{
		if (this->answer[i] != rhs[i])
			return (0);
		i++;
	}
	return (1);
}

bool	Guess::operator!=(int *rhs)
{
	if (*this == rhs)
		return (0);
	return (1);
}

bool	Guess::operator<(Guess &rhs)
{
	if (this->pegs < rhs.getPegs())
		return (1);
	return (0);
}

void	Guess::setState(int state)
{
	this->state = state;
}

int		Guess::getState(void)
{
	return (this->state);
}

void	Guess::generatePegs(Guess *other)
{
	int		black;
	int		white;
	int		i;
	int		j;
	int		positions = other->getPositions();
	int		answer_copy[positions];
	int		*answer = other->getAnswer();
	int		this_copy[positions];

	i = 0;
	while (i < positions)
	{
		this_copy[i] = this->answer[i];
		answer_copy[i] = answer[i];
		i++;
	}
	black = 0;
	white = 0;
	i = 0;
	while (i < positions)
	{
		if (answer_copy[i] == this_copy[i] && this_copy[i] != 0)
		{
			black++;
			this_copy[i] = 0;
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
			if (answer_copy[i] == this_copy[j] && this_copy[j] != 0)
			{
				white++;
				answer_copy[i] = 0;
				this_copy[j] = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	this->pegs.setPegs(black, white, this->positions);
}

void	Guess::setGscores(int *tab)
{
	this->g_scores = tab;
}

void	Guess::setGscore(int score)
{
	this->g_score = score;
}

int		Guess::getScore(void)
{
	return (this->g_score);
}