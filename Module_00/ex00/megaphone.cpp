/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:01:49 by rbouizer          #+#    #+#             */
/*   Updated: 2025/02/25 00:01:52 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (!av[1])
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			std::cout << (char)std::toupper(av[j][i]);
			i++;
		}
		j++;
	}
	std::cout << std::endl;
}