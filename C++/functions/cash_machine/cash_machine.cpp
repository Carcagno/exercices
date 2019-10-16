#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int set_string_cin(std::string &val)
{
  while (!(std::cin >> val))
    {
      std::cout << "Invalid value" << std::endl;
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
  return (0);
}

int set_int_cin(int &val)
{
  while (!(std::cin >> val))
    {
      std::cout << "Invalid value" << std::endl;
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
  return (0);
}

int ask_user_money_type(std::vector<int> &money_type)
{
  std::string val{};
  
  std::cout << "Enter the values available in the cash machine, then enter \"quit\"" << std::endl;
  while (val.compare("quit"))
    {
      val.clear();
      set_string_cin(val);
      if (val.compare("quit"))
	{
	  money_type.push_back(std::stoi(val));
	  
	}
      else
	{ 
	  std::cout << "Exiting ..." << std::endl;
	  break;
	}
    }
  return (0);
}

int distribute_cash(std::vector<int> &money_type, int &money_asked)
{
  std::cout << "trying to distribute " << money_asked << ": " << std::endl;

  std::sort(money_type.begin(), money_type.end(), std::greater<int>());
  
  for (int i : money_type)
    {
      if (i <= 0)
	break;
      int number_of_type{};
      while (money_asked >= i)
	{
	  number_of_type++;
	  money_asked -= i;
	}
      std::cout << i << ": " << number_of_type << std::endl;
    }
  return (0);
}

int main()
{
  std::vector<int> money_type{};
  int money_asked{};

  if (ask_user_money_type(money_type) == 0)
    {
      std::cout << "How many cash do you want to withdraw ?" << std::endl;
      set_int_cin(money_asked);
      if (distribute_cash(money_type, money_asked) != 0)
	return (-1);
    }
  return (0);
}
