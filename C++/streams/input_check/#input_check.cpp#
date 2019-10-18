#include <iostream>
#include <string>
#include <limits>

int check_cin(int &number)
{
  while (!(std::cin >> number))
    {
      std::cout << "Wrong entrie, try again please" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  return (0);
}

int check_cin(double &number)
{
  while (!(std::cin >> number))
    {
      std::cout << "Wrong entrie, try again please" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  return (0);
}

int main()
{
  int number{};
  double numberd{};

  check_cin(number);
  check_cin(numberd);
  return (0);
}
