#include <iostream>
#include <cstdlib>


int main(int ac, char **av)
{
  if (ac == 2)
  {
    int nbr = atoi(av[1]), res{}, iterator{1};
    while (iterator <= nbr)
    {
      res += iterator;
      iterator++;
    }
    std::cout << "Res : " << res << std::endl;
  }
  else
  {
    std::cout << "usage : ./a.out nbr" << std::endl;
  }
  return 0;
}
