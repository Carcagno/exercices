#include <iostream>
#include <vector>

int main()
{
  int number{};
  std::vector<int> odd{}, even{};

  while (number >= 0)
  {
    while (!(std::cin >> number)) {
      std::cout << "Wrong entries !" << std::endl;
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
    if (number >= 0)
    {
      if (number % 2 == 0)
        even.push_back(number);
      else
        odd.push_back(number);
    }
  }
  std::cout << "Even entries : " << std::endl;
  for (auto const n : even)
  {
    std::cout << n << ", ";
  }
  std::cout << std::endl;

  std::cout << "Odd entries : " << std::endl;
  for (auto const n : odd)
  {
    std::cout << n << ", ";
  }
  std::cout << std::endl;
  return 0;
}
