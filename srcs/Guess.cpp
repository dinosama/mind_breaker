/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Guess.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:05:19 by aaapatou          #+#    #+#             */
/*   Updated: 2022/09/25 20:25:43 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mind_breaker.hpp"

Guess::Guess(int *answer, int *first_answer, int positions, int state)
{
	int		*tab;

	tab = new int[positions];
	this->answer = tab;
	this->answer = answer;
	this->state = state;
}