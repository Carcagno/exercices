#include <iostream>

int main()
{
  int a{}, b{}, c{};

  std::cout << "Please enter the value of a and b which will be swaped : " << std::endl;
  std::cin >> a;
  std::cin >> b;

  c = a;
  a = b;
  b = c;
  std::cout << "Result :\nA : " << a << "\nB : " << b << std::endl;

  return 0;
}
