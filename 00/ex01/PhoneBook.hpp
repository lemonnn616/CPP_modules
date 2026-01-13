/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:41:59 by iriadyns          #+#    #+#             */
/*   Updated: 2025/04/08 14:26:00 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int lastContact;
	int countContacts;

public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact& c);
	void displayContacts() const;
	void displayContactByIndex(int index) const;
};

#endif