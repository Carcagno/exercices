#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::string sentence {"This is an example of sentence !"};
  
  //std::count
  long int total_sentence {std::count(std::begin(sentence), std::end(sentence), 'n')};
  
  std::cout << "The sentence :\n" << "\"" << sentence << "\"\nHas " << total_sentence << " 'n'" << std::endl;

  std::cout << "\n" << std::endl;

  //std::find
  //Making an iterator on the first word
  std::string::iterator first_word {std::find(std::begin(sentence), std::end(sentence), ' ')};

  long int total_first_word {std::count(std::begin(sentence), first_word, 'h')};


  std::cout << "The first word of the sentence : \n\"" << sentence << "\"\nHas " << total_first_word << " 'h'" << std::endl;

  return 0;
}
