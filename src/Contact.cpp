/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:19:03 by sforster          #+#    #+#             */
/*   Updated: 2025/01/27 10:16:47 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::displayContact()
{
	std::cout << DARK_TURQUOISE "|8|" LIGHT_AQUA;
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << this->index << '|';
	printItem(this->firstName);
	printItem(this->lastName);
	printItem(this->nickName);
	std::cout <<  DARK_TURQUOISE"8|";
	std::cout << std::endl;
}

void	Contact::printItem(std::string words)
{
	if(words.length() == 10)
	{
		std::cout << words;
	}
	else if (words.length() < 10)
	{
		std::cout << std::setfill (' ') << std::setw (10);
 		std::cout << words;
	}
	else
	{
		std::cout << words.substr(0, 9) << '.';
	}
	std::cout << '|';
	return ;
}

//------------------------------------------------------

//display contact details

void Contact::printPrivateMode()
{
	alistairSpeaking("Excellent choice!\nVoilaaa your contact details:");
	std::cout << LIGHT_AQUA "Contact index: " << this->index << std::endl;
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nick Name: " << this->firstName << std::endl;
	std::cout << "Phone number: " << this->getnum() << std::endl;
	std::cout << "Darkest secret: " << this->getsecret() << std::endl;
	std::cout << DARK_TURQUOISE "                            not judging... not judging...\n" C_RESET;;
	alistairSpeaking("You are welcome my dear. I'm only doing my duty!");
}

std::string Contact::getnum(void) const
{
	return this->phonenumber;
}

std::string Contact::getsecret(void) const
{
	return this->secret;
}

//------------------------------------------------------

void Contact::newContact()
{
	std::string number;
	std::string darksecret;

	while(checknames(this->firstName, 'a')== false)
	{
		std::cout << BOLD LIGHT_BRONZE "Please enter first name: " RESET << std::endl;
		std:: getline(std::cin, this->firstName);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
	}
	while(checknames(this->lastName, 'a')== false)
	{
		std::cout << BOLD LIGHT_BRONZE "Please enter last name: " RESET << std::endl;
		std:: getline(std::cin, this->lastName);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
	}
	while(checknames(this->nickName, 'a')== false)
	{
		std::cout << BOLD LIGHT_BRONZE "Please enter nick name: " RESET << std::endl;
		std:: getline(std::cin, this->nickName);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
	}
	while(checknumbers(number, 'a') == false)
	{
		std::cout << BOLD LIGHT_BRONZE "Please enter phone number: " RESET << std::endl;
		std:: getline(std::cin, number);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
	}
	this->setnum(number);
	alistairSpeaking("I promise I will not judge...");
	while(checknames(darksecret, 's')== false)
	{
		std::cout << BOLD LIGHT_BRONZE "Please enter " << this->firstName << "'s darkest secret: " << RESET << std::endl;
		std:: getline(std::cin, darksecret);
		if (std::cin.eof())
		{
			alistairSpeaking("\nOh nooooo...  This damned D made us die...");
			exit(EXIT_FAILURE) ;
		}
	}
	alistairSpeaking("You may rest assured of our complete discretion at all times.");
	this->setsecret(darksecret);
}

void Contact::reinitialisation()
{
	this->index = 1;
	this->firstName.clear();
	this->lastName.clear();
	this->nickName.clear();
}

bool checknames(std::string names, char a)//differents namespace?
{
	if (names.empty())
	{
		return (false);
	}
	for (size_t i = 0; i < names.size();i++)
	{
		if (isalpha(names[i]) == 0 && names[i] != ' ' && names[i] != '\'')// rajouter accents??
		{
			if (a == 'a')
				alistairSpeaking("I am afraid this is not how you should call a gentleman or a Lady... Please use letters, spaces or \'");
			if (a =='s')
				alistairSpeaking("No secret codes here... Please use letters, spaces or \'");

			return (false);
		}
	}
	if (names.length() > 50)
	{
		alistairSpeaking("My Gosh! This is way to much for an old phonebook like this");
		return (false);
	}
	return (true);
}

bool checknumbers(std::string numbers, char a)//differents namespace?
{
	if (numbers.empty())
		return(false);
	for (size_t i = 0; i < numbers.size();i++)
	{
		if (isdigit(numbers[i]) == 0 && numbers[i] != ' ' && numbers[i] != '+' && numbers[i] != '-')// rajouter accents??
		{
			if (a == 'a')
				alistairSpeaking("Oh oh oh! Telephones with letters exist only in science fictions novels.\n\n    Oh oh oh!!");
			if (a == 's')
				alistairSpeaking("Mmmmh no...\n");
			return (false);
		}
		if (numbers.length() > 20)
		{
			alistairSpeaking("What on earth is this number!\nAre you going to call aliens? \n\nOh oh oh!!");
			return (false);
		}
	}
	return (true);
}

//------------------------------------------------------

void Contact::setnum(std::string number)
{
	this->phonenumber = number;
	return ;
}

void Contact::setsecret(std::string darksecret)
{
	this->secret = darksecret;
	return ;
}

//------------------------------------------------------

Contact::Contact()
{
	this->index = 1;
	return;
}

Contact::~Contact()
{
	return;
}