/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:04:50 by iriadyns          #+#    #+#             */
/*   Updated: 2025/04/08 17:35:29 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static std::string trimField(const std::string &field)
{
	if (field.size() > 10)
		return field.substr(0, 9) + "."; // 9 simvolov nachinaya s 0ogo
	return field;
}

PhoneBook::PhoneBook()
{
	this->lastContact = 0;
	this->countContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(const Contact& c)
{
	this->contacts[this->lastContact] = c;
	this->lastContact = (this->lastContact + 1) % 8;
	if (this->countContacts < 8)
		this->countContacts++;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Phone Num." << std::endl;

	int entriesToShow = (this->countContacts < 8) ? this->countContacts : 8;

	for (int i = 0; i < entriesToShow; i++)
	{
		std::cout << std::setw(10) << i << "|";

		const Contact &c = this->contacts[i];

		std::cout << std::setw(10) << trimField(c.getFirstName()) << "|"
					<< std::setw(10) << trimField(c.getLastName()) << "|"
					<< std::setw(10) << trimField(c.getPhoneNumber()) << std::endl;
	}
}

void PhoneBook::displayContactByIndex(int index) const
{
	if (index < 0 || index >= this->countContacts || index >= 8)
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	const Contact &c = this->contacts[index];

	std::cout << "First Name:  " << c.getFirstName() << std::endl;
	std::cout << "Last Name:   " << c.getLastName() << std::endl;
	std::cout << "Phone Num.:  " << c.getPhoneNumber() << std::endl;
	std::cout << "Age:         " << c.getAge() << std::endl;
}