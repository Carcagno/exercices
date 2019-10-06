#include <iostream>

int main()
{
  int number{};
  double average{};

  std::cout << "Please enter 5 numbers on which you want to calculate an average" << std::endl;
  std::cin >> number;
  average += number;
  std::cin >> number;
  average += number;
  std::cin >> number;
  average += number;
  std::cin >> number;
  average += number;
  std::cin >> number;
  average += number;

  average /= 5.;

  std::cout << "\nThe average is : " << average << std::endl;


  return EXIT_SUCCESS;
}
