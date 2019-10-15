#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char** av)
{
  if (ac == 2)
  {
    int number_word{}, number_line{}, number_char{};
    std::ifstream file {av[1]};

    if (file.is_open())
    {
      std::string temp_sentence{};
      while (std::getline(file, temp_sentence))
      {
        number_word++;
        for (std::string::iterator it = temp_sentence.begin(); it != temp_sentence.end(); ++it)
        {
          if (*it == ' ' || *it == '\n' || *it == '\0')
            number_word++;
          else
            number_char++;
        }
        number_line++;
      }
      std::cout << "The file " << av[1] << " has :\n" << number_line << " lines\n" << number_word << " words\n" << number_char << " chars" << std::endl;
    }
    else
    {
      std::cout << "The file " << av[1] << " cannot be opened. Wrong name ?" << std::endl;
      return (2);
    }
  }
  else
  {
    std::cout << "Usage : ./a.out filename" << std::endl;
    return (1);
  }

  return (0);
}
