/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:45:45 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/22 20:17:24 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() 
{}

Base*	generate(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
	{
		std::cout << "A class generated" << std::endl;
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << "B class generated" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C class generated" << std::endl;
		return (new C());
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer C" << std::endl;
	else
		std::cout << "Pointer unknown" << std::endl;
}

void identify(Base& p)
{
	
	Base* ptr = &p;

	if (dynamic_cast<A*>(ptr))
		std::cout << "Reference: A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "Reference: B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "Reference: C" << std::endl;
	else
		std::cout << "Reference: Unknown type" << std::endl;
}


