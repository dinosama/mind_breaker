/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pegs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:42:55 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/30 16:34:13 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/mind_breaker.hpp"

Pegs::Pegs()
{
	this->black = 0;
	this->white = 0;
}

Pegs::Pegs(int black, int white) : black(black), white(white)
{
}

Pegs::~Pegs()
{
}

int		Pegs::getBlack()
{
	return (this->black);
}

int		Pegs::getWhite()
{
	return (this->white);
}

int		Pegs::getPegsLevel()
{
	int		level;

	level = 0;
	level = this->black * this->positions;
	level = level + this->white;
	return (level);
}

bool	Pegs::operator==(Pegs &rhs)
{
	if (this->black != rhs.getBlack())
		return (0);
	if (this->white != rhs.getWhite())
		return (0);
	return (1);
}

bool	Pegs::operator!=(Pegs &rhs)
{
	if (*this == rhs)
		return (0);
	return (1);
}

bool	Pegs::operator<(Pegs &rhs)
{
	if (this->black < rhs.getBlack())
		return (1);
	if (this->black == rhs.getBlack() && this->white < rhs.getWhite())
		return (1);
	return (0);
}

bool	Pegs::operator<=(Pegs &rhs)
{
	if (*this == rhs || *this < rhs)
		return (1);
	return (0);
}

bool	Pegs::operator>(Pegs &rhs)
{
	if (this->black > rhs.getBlack())
		return (1);
	if (this->black == rhs.getBlack() && this->white > rhs.getWhite())
		return (1);
	return (0);
}

bool	Pegs::operator>=(Pegs &rhs)
{
	if (*this == rhs || *this > rhs)
		return (1);
	return (0);
}

Pegs	&Pegs::operator=(Pegs &rhs)
{
	this->black = rhs.getBlack();
	this->white = rhs.getWhite();
}

void	Pegs::setPegs(int black, int white, int positions)
{
	this->black = black;
	this->white = white;
	this->positions = positions;
}

std::ostream    &operator<<(std::ostream & out, Pegs &pegs)
{
	out << "black : " << pegs.getBlack() << " white : " << pegs.getWhite();
	return (out);
}