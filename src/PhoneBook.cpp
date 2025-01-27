/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:19:36 by sforster          #+#    #+#             */
/*   Updated: 2025/01/27 10:12:27 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::takeCommand()
{
	while (this->cmd != "ADD" && this->cmd != "SEARCH" && this->cmd != "EXIT")
	{
		std::cout << BOLD PASTEL_CREAM "ADD, SEARCH or EXIT: " RESET;
		std::getline(std::cin, this->cmd);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
	}
}

//------------------------------------------------------

void	PhoneBook::addContact()
{
	this->cmd.clear();
	int a;
	if (this->nb_contacts < 8)
		this->nb_contacts++;
	a = this->nb_contacts - 1;
	while (a > 0)
	{
		this->contacts[a] = this->contacts[a - 1];
		this->contacts[a].index = a + 1;
		a--;
	}
	this->contacts[0].reinitialisation();
	this->contacts[0].newContact();

}

//------------------------------------------------------

void	PhoneBook::SearchPhonebook()
{
	this->cmd.clear();
	if (this->nb_contacts == 0)
	{
		alistairSpeaking("Oh nooooo... there are no contacts in this phonebook. What an emptiness!");
		return ;	
	}
	DisplayPhonebook();
	this->wichContact();
	this->contacts[this->wichOne].printPrivateMode();
}

void	PhoneBook::DisplayPhonebook()
{
	printPhonebookHeader();
	for (int x = 0; x < this->nb_contacts; x++)
		this->contacts[x].displayContact();
	printPhonebookFooter();
}

void	PhoneBook::printPhonebookHeader()
{
	std::cout << BRIGHT_MAGENTA    "\n\n.-'o.°'*.o'*°.O'`o'.-*,            .*o'°.O'`°*.o\n" ;							   
	std::cout << DARK_LIME STRIKE " ='-. '_. '_. '=. ' " RESET << BRIGHT_MAGENTA",o *.      .-o'," << DARK_LIME STRIKE " _. '_. '= " RESET;
	std::cout << BRIGHT_MAGENTA     "\no'*.'O°.o'*(.o'`°.o'*°             `*°.'O°.o'*:O,\n.°'\n";

	std::cout << DARK_CYAN UNDERLINE"                                                 \n" RESET;
	std::cout << DARK_TURQUOISE     "|o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o|\n|8|";
	std::cout << DARK_LIME UNDERLINE"     Index|First Name| Last Name|  Nickname"  << RESET DARK_TURQUOISE "|8|\n" << RESET;
}

void PhoneBook::printPhonebookFooter(void)
{
	std::cout << UNDERLINE "|o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o.o'o|\n" ;
	std::cout << DARK_CYAN ULINE"                                                 \n\n\n" RESET;

}

void	PhoneBook::wichContact()
{
	std::string	numInd;

	alistairSpeaking("May I kindly ask you the index of the contact you want to see?");
	while (1)
	{
		std::getline(std::cin, numInd);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
		if (checknumbers(numInd, 's') == true)
		{
			this->wichOne = std::atoi(numInd.c_str());
			if (this->wichOne >= 1 && this->wichOne <= this->nb_contacts)
			{
				break ;
			}
		}
		alistairSpeaking("I strongly recommand you to make an other choice!");
	}
	this->wichOne--;
}

//------------------------------------------------------

PhoneBook::PhoneBook(void)
{
	this-> cmd = "VIDE";
	this->nb_contacts = 0;

	alistairSpeaking("Good morning Ladies and Gentlemen!\n\nLet me introduce myself. I'm Alistair and I will be your guide for this incredible Vintage Phonebook experiment!");
	alistairTheDog();
	alistairSpeaking("Please select one of the options below:");
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void alistairSpeaking(std::string blabla)
{
	std::cout << std::endl;
	std::cout << DARK_TURQUOISE << ITALIC << blabla << RESET;
	std::cout << std::endl << std::endl;
}

void PhoneBook::alistairTheDog()
{
	std::cout << BOLD PASTEL_ROSE "                           ,.\n                           (" <<LIGHT_CHARCOAL   "*.>" LIGHT_PINK << "\n                  *(:;:;:;:;)\n" << BRIGHT_BEIGE"                   / \\.   / \\.\n" RESET;
}


