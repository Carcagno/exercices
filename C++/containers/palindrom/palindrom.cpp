#include <iostream>
#include <string>
#include <algorithm>

int main(int ac, char **av)
{
  if (ac == 2)
    {
      std::string normal {av[1]};
      std::string reverse {av[1]};
      std::reverse(std::begin(reverse), std::end(reverse));
      

      if (normal.compare(reverse) == 0)
	std::cout << "Y" << std::endl;
      else
	std::cout << "N" << std::endl;
    }
  else
    std::cout << "Usage : ./a.out \"a string \"" << std::endl;
  return (0);
}
