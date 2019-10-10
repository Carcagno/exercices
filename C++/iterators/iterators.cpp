#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vect{2, 4, 6, 8, 10, 12};

  //declaring an iterator on the vector<int> vect
  std::vector<int>::iterator begin_of_vect {std::begin(vect)};

  //Same declaration on the end of vect with auto
  auto end_of_vect {std::end(vect)};


  return 0;
}
