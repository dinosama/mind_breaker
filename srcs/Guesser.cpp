/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guesser.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:05:49 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 22:08:57 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mind_breaker.hpp"

Guesser::Guesser(int max_try, int positions, int colors) : max_try(max_try), positions(positions), colors(colors)
{
	int		tab[positions];
	int		current_position;
	int		i = 0;
	int		over = 0;

	this->guess_nbr = pow(colors, positions);
	this->tries = 0;
	this->guesses = new Guess[guess_nbr];
	while (i < positions)
	{
		tab[i] = 1;
		i++;
	}
	this->guesses[0].initialize(tab, 2, this, positions, 1);
	i = 1;
	while (i <= this->guess_nbr && over < positions)
	{
		tab[positions - 1]++;
		this->guesses[i].initialize(tab, 2, this, positions, i + 1);
		current_position = positions - 1;
		while (current_position > over && tab[current_position] == colors)
		{
			if (current_position == positions - 1)
				tab[current_position] = 0;
			else
			{
				tab[current_position] = 1;
			}
			if (tab[current_position - 1] != colors)
			{
				tab[current_position - 1]++;
				break ;
			}
			current_position--;
		}
		if (tab[over] == colors)
			over++;
		i++;
	}
}

Guesser::~Guesser()
{
	delete[] this->guesses;
}

void    Guesser::setColors(int colors)
{
	this->colors = colors;
}

void    Guesser::setTry(int max_try)
{
	this->max_try = max_try;
}

void    Guesser::setPositions(int positions)
{
	this->positions = positions;
}

Guess   *Guesser::getGuesses(void)
{
	return (this->guesses);
}

void	Guesser::showGuesses(void)
{
    int         i;

    i = 0;
    while (i < this->guess_nbr)
    {
        std::cout << this->guesses[i] << " state : " << this->guesses[i].getState() 
			<< " score : " << this->guesses[i].getScore() << std::endl;
        i++;
    }
}

void	Guesser::find_first_guess(void)
{
	int		tab[this->positions];
	int		i;

	i = 0;
	while (i < this->positions)
	{
		if (i < this->positions / 2 || this->colors == 1)
			tab[i] = 1;
		else
			tab[i] = 2;
		i++;
	}
	i = 0;
	while (i < this->guess_nbr)
	{
		if (this->guesses[i] == tab)
		{
			this->actual_guess = &this->guesses[i];
			return ;
		}
		i++;
	}
}

void	Guesser::sortguesses(void)
{
	int		i;

	i = 0;
	while (i < this->guess_nbr)
	{
		this->guesses[i].generatePegs(this->actual_guess);
		if (this->guesses[i].getPegs() != this->actual_pegs && this->guesses[i].getState() != 0)
			this->guesses[i].setState(1);
		i++;
	}
}

void	Guesser::find_next_guess(void)
{
	int		i;
	int		j;
	int		*g_scores;
	int		max;
	int		min;
	int		score;

	i = 0;
	j = 0;
	while (i < this->guess_nbr)
	{
		j = 0;
		g_scores = new int[this->positions * this->positions]();
		while (j < this->guess_nbr)
		{
			this->guesses[j].generatePegs(&this->guesses[i]);
			g_scores[this->guesses[j].getPegs().getPegsLevel()]++;
			j++;
		}
		j = 0;
		max = 0;
		while (j < this->positions * this->positions)
		{
			if (g_scores[j] > max)
			{
				max = g_scores[j];
				score = j;
			}
			j++;
		}
		this->guesses[i].setGscore(score);
		delete[] g_scores;
		i++;
	}
	i = 0;
	min = this->guess_nbr;
	while (i < this->guess_nbr)
	{
		if (this->guesses[i].getScore() <= min && this->guesses[i].getState() == 2
			&& this->actual_guess->getState() != 2)
		{
			min = this->guesses[i].getScore();
			this->actual_guess = &this->guesses[i];
		}
		i++;
	}
	this->actual_guess->setState(0);
}

bool	Guesser::guess(void)
{
	int		black;
	int		white;
	this->find_first_guess();
	while (this->tries < this->max_try)
	{
		std::cout << "\033[1;32mAttempt " << this->tries + 1 << "\033[0m" << std::endl;
		std::cout << *this->actual_guess << std::endl;
		std::cout << "How many correct letters are in the correct position?" << std::endl;
		std::cin >> black;
		if (black == this->positions)
		{
			std::cout << "It's win!" << std::endl;
			return (1);
		}
		std::cout << "How many correct letters are in the incorrect position?" << std::endl;
		std::cin >> white;
		this->actual_guess->setState(0);
		this->actual_pegs.setPegs(black, white, this->positions);
		this->sortguesses();
		this->find_next_guess();
		this->tries++;
	}
	return (0);
}
