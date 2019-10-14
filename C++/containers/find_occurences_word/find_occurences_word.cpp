#include <iostream>
#include <algorithm>
#include <string>

int main()
{
  std::string sentence {"This is an example of a sentence here !"};

  std::string::iterator begin {std::begin(sentence)};
  std::string::iterator end {std::end(sentence)};

  while (begin != end)
    {
      std::string::iterator space {std::find(begin, end, ' ')};
      long int count {std::count(begin, space, 'e')};
      
      for (std::string::iterator it {begin}; it != space; it++)
      {
	std::cout << *it;
      }

      std::cout << ": " << count << std::endl;
      if (space == end)
	begin = end;
      else
	begin = space + 1;
    }

  return 0;
}
