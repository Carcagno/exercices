#include <iostream>
#include <cmath>

int main()
{
  float xA{}, yA{}, xB{}, yB{}, AB{};

  std::cout << "Please, enter the coordinates of the point A (xA, yA) : " << std::endl;
  std::cin >> xA;
  std::cin >> yA;

  std::cout << "Please, enter the coordinates of the point B (xB, yB) : " << std::endl;
  std::cin >> xB;
  std::cin >> yB;

  AB = sqrt(pow((xB - xA), 2) + pow((yB - yA), 2));

  std::cout << "The distance AB is : " << AB << std::endl;

  return 0;
}
