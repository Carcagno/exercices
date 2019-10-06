#include <iostream>
#include <string>

int main()
{
  int field_length{}, field_width{}, field_perimeter{};

  std::cout << "Please enter the length of the field : " << std::endl;
  std::cin >> field_length;

  std::cout << "Please enter the width of the field : " << std::endl;
  std::cin >> field_width;

  field_perimeter = (field_length + field_width) * 2;

  std::cout << "The perimeter of the field is : " << field_perimeter << std::endl;

  return 0;
}
