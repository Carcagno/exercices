#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vect{2, 4, 6, 8, 10, 12};

  //declaring an iterator on the vector<int> vect
  std::vector<int>::iterator begin_of_vect {std::begin(vect)};

  //Same declaration on the end of vect with auto
  //  auto end_of_vect {std::end(vect)};
  
  std::cout << "The first element is : " << *begin_of_vect << std::endl;

  //browse an entire container with an iterator
  for (std::vector<int>::iterator it {std::begin(vect)}; it != std::end(vect); ++it)
    {
      std::cout << *it << std::endl;
    }

  //create a container initialized with sub-assembly of another container
  std::vector<int> sub_vect {std::begin(vect) + 2, std::end(vect) - 3};

  std::cout << "sub_assambly :" << std::endl;
  for (std::vector<int>::iterator it {std::begin(sub_vect)}; it != std::end(sub_vect); ++it)
    {
      std::cout << *it << std::endl;
    }

  return 0;
}
