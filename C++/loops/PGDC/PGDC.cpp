#include <iostream>
#include <cstdlib>

int main(int ac, char **av)
{
  if (ac == 3)
  {
    int nbr1 = atoi(av[1]), nbr2 = atoi(av[2]), r{};
    r = nbr1 % nbr2;
    while (r != 0)
    {
      nbr1 = nbr2;
      nbr2 = r;
      r = nbr1 % nbr2;
    }
    std::cout << "The greater common denominator is : " << nbr2 << std::endl;
  }
  else
  {
    std::cout << "Please use this program with two numerical arguments : ./a.out nbr1 nbr2" << std::endl;
  }
  return 0;
}
