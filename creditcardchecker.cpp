/*

Written by AwesomeMc101

6.7.22 (30 minutes from ~ 1-1:30 A.M. :))

Using Luhn's Algorithm

Anybody who pastes just remember you're pasting from a 14 year old lol

Only credits are to:
https://7labs.io/tips-tricks/check-validity-of-credit-card-number.html
To where I learned how to use the algo!

*/
#include <iostream>
#include <string>
#include <vector>

//Use Luhn's Algorithm

void setEvens(std::vector<int>& odds) //meant to say evens.. oops!
{
	for (int i = 0; i < odds.size(); i++)
	{
		odds[i] = (2 * odds[i]);
		if (odds[i] >= 10) //double digit
		{
			int finalnum = 0;
			std::string temp = std::to_string(odds[i]); //12
			for (int z = 0; z < temp.size(); z++)
			{
				finalnum += temp[z]-'0';
			}
			odds[i] = finalnum;
		}
	}
}

int main()
{
  //Input like this: 4417 1234 5678 9113
  //With the spaces.
  std::string card;
  std::getline(std::cin, card);

	std::vector<std::string> sets;
	char* token;
	char* rest = (char*)card.c_str();
	while ((token = strtok_s(rest, " ", &rest)))
	{
		sets.push_back(token);
	}

	std::vector<int> odds, evens;
	for (std::string set : sets)
	{
		for (int i = 0; i < set.length(); i++)
		{
			if (i == 0 || (i % 2) == 0) //modulo to ensure its even
			{
				evens.push_back((set[i])-'0');
			}
			else
			{
				odds.push_back((set[i]) - '0');
			}
		}
	}

	setEvens(evens);

	int total = 0;
	for (int t : evens)
	{
		total += t;
	}
	for (int t : odds)
	{
		total += t;
	}

	std::cout << "Sum: " << total << std::endl;
	if (total % 10 == 0) //modulo to check if divisible by 10
	{
		std::cout << "Card is valid!" << std::endl;
	}
	else
	{
		std::cout << "Card is invalid!" << std::endl;
	}
}
