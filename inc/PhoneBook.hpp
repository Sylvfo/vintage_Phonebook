/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:06 by sforster          #+#    #+#             */
/*   Updated: 2025/01/27 10:16:54 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>
#include <cstdlib>
#include "colors.hpp"
#include "Contact.hpp"

void	alistairSpeaking(std::string blabla);

class PhoneBook
{
	public:
	Contact	contacts[8];
	std::string cmd;
	int nb_contacts;
	int wichOne;

	void 	printPhonebookHeader();
	void 	printPhonebookFooter();
	void	alistairTheDog();
	void	takeCommand();
	void	addContact();
	void	SearchPhonebook();
	void	DisplayPhonebook();
	void	wichContact();

	PhoneBook();
	~PhoneBook();
	private:
};


# endif 
