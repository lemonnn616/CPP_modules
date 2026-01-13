/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:24:59 by iriadyns          #+#    #+#             */
/*   Updated: 2025/04/08 17:55:17 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl << "EOF_1 reached. Exiting..." << std::endl; // ctr +d 
			break;
		}
		if (command == "EXIT")
		{
			std::cout << "Exiting!" << std::endl;
			break;
		}
		else if (command == "ADD")
		{
			Contact c;
			std::string input;

			std::cout << "Enter First Name: ";
			if (!std::getline(std::cin, input) || input.empty())
			{
				std::cout << "Error: field cannot be empty." << std::endl;
				continue; // pri ctrl + d u nas continiu chtobi napisalo EOF_1
			}
			c.setFirstName(input);

			std::cout << "Enter Last Name: ";
			if (!std::getline(std::cin, input) || input.empty())
			{
				std::cout << "Error: field cannot be empty." << std::endl;
				continue;
			}
			c.setLastName(input);

			std::cout << "Enter Phone Number: ";
			if (!std::getline(std::cin, input) || input.empty())
			{
				std::cout << "Error: field cannot be empty." << std::endl;
				continue;
			}
			c.setPhoneNumber(input);

			std::cout << "Enter Age: ";
			if (!std::getline(std::cin, input) || input.empty())
			{
				std::cout << "Error: field cannot be empty." << std::endl;
				continue;
			}
			c.setAge(input);

			phoneBook.addContact(c);
			std::cout << "Contact added successfully!" << std::endl;
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			std::cout << "Enter the index of the contact you want to display: ";

			std::string indexStr;
			if (!std::getline(std::cin, indexStr))
			{
				std::cout << std::endl << "EOF_2 reached. Exiting..." << std::endl; // texnicheski ne obyazatelno ispolzovat EOF_2 no togda nam nado obiedenit emty line + break vmesto continiu, no togda polzovatel esli vvedet ctrl +d to uvidet soobshenie ustaya stroka + EOF_1, chto ne sovsem pravilno
				break;
			}
			if (indexStr.empty())
			{
				std::cout << "Error: index cannot be empty." << std::endl;
				continue;
			}
			int index = std::atoi(indexStr.c_str()); // atoi rabotaet tolko s tipom char *str, a u nas std::string poetmou c_str sozdaet nam pointer na nachalo pervogo simvola s string, chtobi mi ispolzovali kak * char (atoi po drugomu ne rabotaet)
			phoneBook.displayContactByIndex(index);
		}
		else
		{
			std::cout << "Unknown command: " << command << std::endl;
			std::cout << "Please use ADD, SEARCH or EXIT." << std::endl;
		}
	}

	return 0;
}
