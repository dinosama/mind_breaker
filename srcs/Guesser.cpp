/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guesser.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:05:49 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 09:15:09 by aaapatou         ###   ########.fr       */
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
	this->guesses[0].initialize(tab, 1, this, positions, 1);
	i = 1;
	while (i <= this->guess_nbr && over < positions)
	{
		tab[positions - 1]++;
		this->guesses[i].initialize(tab, 1, this, positions, i + 1);
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
	delete[]	this->guesses;
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
        std::cout << this->guesses[i] << std::endl;
        i++;
    }
}