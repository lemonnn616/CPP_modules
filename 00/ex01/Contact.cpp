/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:50:20 by iriadyns          #+#    #+#             */
/*   Updated: 2025/04/08 14:03:07 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string& value)
{
	this->firstName = value;
}

void Contact::setLastName(const std::string& value)
{
	this->lastName = value;
}

void Contact::setPhoneNumber(const std::string& value)
{
	this->phoneNumber = value;
}

void Contact::setAge(const std::string& value)
{
	this->age = value;
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string Contact::getAge() const
{
	return this->age;
}
