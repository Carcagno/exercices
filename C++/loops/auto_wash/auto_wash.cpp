#include <iostream>

int main()
{
  int laundry_weight{}, nbr_five_kilo{}, nbr_ten_kilo{};
;

  std::cout << "How many kilograms of laundry do you need to wash ? : " << std::endl;
  std::cin >> laundry_weight;
  while (std::cin.fail())
  {
    std::cout << "You entered something wrong ! Try again :" << std::endl;
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::cin >> laundry_weight;  
  }
  std::cout << "You want to wash " << laundry_weight << " of laundry. here is ho you should split it : " << std::endl;
  while (laundry_weight > 0)
  {
    if (laundry_weight <= 5)
    {
      nbr_five_kilo++;
      laundry_weight -= laundry_weight;
    }
    else
    {
      nbr_ten_kilo++;
      laundry_weight -= 10;
    }
  }
  std::cout << "You should use " << nbr_five_kilo << " 5 kilograms machines and " << nbr_ten_kilo << " 10 kilograms machines" << std::endl;
  return 0;
}
