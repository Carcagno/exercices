#include <iostream>
#include <string>

int print_rectangle(int &length, int &width)
{
  if (length < 1 || width < 1)
    {
      std::cout << "Dimensions must be at the minimum 1 x 1" << std::endl;
      return (-1);
    }
  
  for (int i = 0; i < length; ++i)
    {
      for (int j = 0; j < width; ++j)
	std::cout << "*";
      std::cout << std::endl;
    }
  return (0);
}

void test_cin_int(int &val)
{
  while (!(std::cin >> val))
    {
      std::cout << "Invalid value" << std::endl;
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
}

int main()
{
  int length{}, width{};
  
  std::cout << "Please enter length : " << std::endl;
  test_cin_int(length);

  std::cout << "Please enter width : " << std::endl;
  test_cin_int(width);

  if (print_rectangle(length, width) != 0)
    return (-1);
  return (0);
}
