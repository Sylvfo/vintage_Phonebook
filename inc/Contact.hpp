/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:18:46 by sforster          #+#    #+#             */
/*   Updated: 2025/01/27 10:16:52 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>
#include <cstdlib>
#include "colors.hpp"

bool 	checknames(std::string names, char a);
bool 	checknumbers(std::string numbers, char a);

class Contact
{
	public:
	
	int index;
	std::string	firstName;
	std::string lastName;
	std::string nickName;

	void setnum(std::string number);
	void setsecret(std::string darksecret);
	std::string getnum(void) const;
	std::string getsecret(void) const;
	void	printItem(std::string words);
	void displayContact();
	void printPrivateMode();

	void newContact();
	void reinitialisation();

	Contact();
	~Contact();

	private:
	std::string secret;
	std::string phonenumber;
};

# endif 