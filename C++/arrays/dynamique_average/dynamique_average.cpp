#include <iostream>
#include <vector>

int main()
{
  float total{};
  std::vector<float> numbers{};

  std::cout << "Enter the numbers on which you want to calculate an average. Enter -1 when you have ended" << std::endl;

  float number = 0;
  while (number >= 0)
  {
    while (!(std::cin >> number))
    {
      std::cout << "Wrong entries" << std::endl;
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
    if (number >= 0)
      numbers.push_back(number);
  }
  for (auto const number : numbers)
  {
    total += number;
  }
  if (numbers.size() > 0)
    std::cout << "The average is " << total / numbers.size() << std::endl;
  else
    std::cout << "No numbers to calculate an average :/" << std::endl;
  return 0;
}
