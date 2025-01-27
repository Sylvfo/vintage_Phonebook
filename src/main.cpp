/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:19:20 by sforster          #+#    #+#             */
/*   Updated: 2025/01/27 10:04:17 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

//FONCTIONS AU BON ENDROIT

int main(void)
{
	PhoneBook MyPhoneBook;

	while (MyPhoneBook.cmd != "EXIT")
	{
		MyPhoneBook.takeCommand();
		if (MyPhoneBook.cmd == "ADD")
			MyPhoneBook.addContact();
		if (MyPhoneBook.cmd == "SEARCH")
			MyPhoneBook.SearchPhonebook();
	}
	alistairSpeaking("I hope you enjoyed the vintage phonebook experiment. Bye bye!");

	return(0);
}