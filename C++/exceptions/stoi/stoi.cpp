#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

int check_cin(std::string &number)
{
  while (!(std::cin >> number))
    {
      std::cout << "Wrong entrie, try again please" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  return (0);
}

void caller()
{
  int number_int{};
  std::string number{};

  try
    {
      check_cin(number);
      number_int = std::stoi(number);
      std::cout << number_int << std::endl;
    }
  catch (std::invalid_argument const & exception)
    {
      std::cout << "Error, try again ! " << number << " is not something convertible in a numerical form !" << std::endl;
      caller();
    }
  catch (std::out_of_range const & exception)
    {
      std::cout << number << " Does not fit in an int. Try with a smaller number pls" << std::endl;
      caller();
    }
  

}

int main()
{
  caller();
  return (0);
}
