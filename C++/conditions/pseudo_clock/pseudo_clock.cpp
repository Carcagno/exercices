#include <iostream>
#include <string>

int main()
{
  int hour{};

  std::cout << "Enter the hour of the day (between 0 and 24): " << std::endl;
  if (std::cin >> hour)
  {
    if (hour < 0 || hour > 24)
    {
      std::cout << "You enter a wrong hour, please launch the program again and enter an hour between 0 and 24" << std::endl;
      return 2;
    }
    else
    {
      std::cout << "Time of the day : " << hour << std::endl;
      if (hour >= 0 && hour < 8)
        std::cout << "We are in the night" << std::endl;
      else if (hour >= 8 && hour <= 12)
        std::cout << "We are in the morning" << std::endl;
      else if (hour >= 13 && hour < 18)
        std::cout << "We are in the afternoon" << std::endl;
      else if (hour >= 18 && hour <= 22)
        std::cout << "We are in the evening" << std::endl;
      else
        std::cout << "We are in th night" << std::endl;
    }
  }
  else
  {
    std::cout << "You enter something different than a number corresponding to an hour. Please try again with a number between 0 and 24" << std::endl;
    return 1;
  }
  return 0;
}
