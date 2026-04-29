/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:00:02 by sarajime          #+#    #+#             */
/*   Updated: 2026/04/29 14:40:26 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() 
{}

static void printChar(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(value);
	if (!isprint(c))
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

static void printInt(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	int i = static_cast<int>(value);
	std::cout << "int: " << i << std::endl;
}

static void printFloat(double value)
{
	float f = static_cast<float>(value);
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{	
	double value;
	
	if (str.length() == 1 && std::isprint(str[0]))
		value = static_cast<double>(str[0]);
	else
	{
		char* endPtr = NULL;
		value = std::strtod(str.c_str(), &endPtr);

		if (endPtr == str.c_str() || (*endPtr != '\0' && *endPtr != 'f'))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}