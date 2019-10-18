#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> lire_fichier(std::string const & nom_fichier)
{
  std::vector<std::string> lignes {};
  std::string ligne { "" };

  std::ifstream fichier { nom_fichier };
  if (!fichier)
    {
      // Si le fichier ne s'ouvre pas, alors on lance une exception pour le signaler.
      throw std::runtime_error("Fichier impossible à ouvrir. Mauvais nom ?");
    }

  while (std::getline(fichier, ligne))
    {
      lignes.push_back(ligne);
    }

  return lignes;
}

int main()
{
  std::string nom_fichier { "" };
  std::cout << "Donnez un nom de fichier : ";
  std::cin >> nom_fichier;

  try 
    {
      auto lignes = lire_fichier(nom_fichier);
      std::cout << "Voici le contenu du fichier :" << std::endl;
      for (auto const & ligne : lignes)
	{
	  std::cout << ligne << std::endl;
	}
    }
  catch (std::runtime_error const & exception)
    {
      std::cout << "ERROR /!\\ : " << exception.what() << std::endl;
    }
  catch (std::exception const & exception) // to catch all type of exceptions
    {
      std::cout << "An exception occur : " << exception.what() << std::endl;
    }
  return 0;
}
