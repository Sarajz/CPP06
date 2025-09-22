/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:40:52 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/15 22:01:19 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.number = 42;
	data.text = "Hello, World!";

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Original Data number: " << data.number << std::endl;
	std::cout << "Original Data text: " << data.text << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized Data (uintptr_t): " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data number: " << deserialized->number << std::endl;
	std::cout << "Deserialized Data text: " << deserialized->text << std::endl;

	return 0;
}