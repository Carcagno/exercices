#include <iostream>

int main()
{
  int age{};

  std::cout << "Enter your age please :" << std::endl;
  if (std::cin >> age)
  {
      if (age < 0)
    std::cout << "You can't have a negative age ..." << std::endl;
  else if (age > 0 && age <= 3)
    std::cout << "You are really too young to be in front of a computer !" << std::endl;
  else if (age > 3 && age <= 12)
    std::cout << "You are a kid !" << std::endl;
  else if (age > 12 && age <= 18)
    std::cout << "You are an adolescent" << std::endl;
  else if (age > 18 && age < 60)
    std::cout << "You are an adult" << std::endl;
  else if (age >= 60 && age < 100)
    std::cout << "You are a senior" << std::endl;
  else
    std::cout << "Still alive :o ?" << std::endl;
  return 0;
  }
  else
  {
    std::cout << "What you enter is not an age ..." << std::endl;
    std::cin.clear();
    std::cin.ignore(255, '\n');
  }
}
