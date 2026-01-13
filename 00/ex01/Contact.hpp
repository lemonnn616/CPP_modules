/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:49:58 by iriadyns          #+#    #+#             */
/*   Updated: 2025/04/08 14:01:56 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string phoneNumber;
	std::string age;

public:
	Contact();
	~Contact();

	void setFirstName(const std::string& value);
	void setLastName(const std::string& value);
	void setPhoneNumber(const std::string& value);
	void setAge(const std::string& value);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getPhoneNumber() const;
	std::string getAge() const;
};

#endif
