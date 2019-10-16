#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int get_file_name(std::string &file_name)
{
  std::cout << "Please enter the file name where you want to record" << std::endl;
      while (!(std::cin >> file_name))
	{
	  std::cout << "Please enter a file name" << std::endl;
	  std::cin.clear();
	  std::cin.ignore(255, '\n');
	}
  
   return (0);
}

int read_file_opener(std::ifstream &rfile, std::string file_name)
{
  bool open{false};

  while (open == false)
    {
      rfile.open(file_name, std::ios::app);

      if (rfile.is_open())
        open = true;
      else if (file_name.compare("quit") == 0)
        {
	  std::cout << "Exiting" << std::endl;
          return (-1);
        }
      else
	std::cout << "Cannot open the file. Please try again or type  \"quit\" to exit" << std::endl;
    }
  return (0);
}

int write_file_opener(std::ofstream &file, std::string option, std::string file_name)
{
  bool open{false};

  while (open == false)
    {
      if (option.compare("append") == 0)
	file.open(file_name, std::ios::app);
      else if (option.compare("overwrite") == 0)
	file.open(file_name);
      else
	{
	  std::cout << "Error on option to open the file in write mode. Exiting ..." << std::endl;
	    return (-1);
	}
	
      if (file.is_open())
	open = true;
      else if (file_name.compare("quit") == 0)
	{
	  std::cout << "Exiting" << std::endl;
	  return (0);
	}
      else
	std::cout << "Cannot open the file. Please try again or type  \"quit\" to exit" << std::endl;
    }
  return (0);
}

int view_all_student(std::ifstream &rfile)
{
  std::string file_name{}, line_of_file{};

  get_file_name(file_name);
  if (read_file_opener(rfile, file_name) == 0)
    {
      while (std::getline(rfile, line_of_file))
	{
	  std::cout << line_of_file << std::endl;
	}
      rfile.close();
    }
  else 
    {
      std::cout << "something goes wrong with the read_file_opener. Exiting" << std::endl;
      return (-1);
    }

  return (0);
}

int update_student(std::ifstream &rfile, std::ofstream &file)
{
  std::string file_name{};

  get_file_name(file_name); 
  if (read_file_opener(rfile, file_name) == 0)
    {
      std::string line_of_file{}, student_name{}, replace_student_name{};;
      std::vector<std::string> file_content{};
      int position{}, count_of_element{};;
      bool found{false};

      while (std::getline(rfile, line_of_file))
	{
	  file_content.push_back(line_of_file);
	}
      rfile.close();
      
      if (write_file_opener(file, "overwrite", file_name) == 0)
	{
	  while (found == false)
	    {
	      position = 0;
	      std::cout << "Please enter the name of the student to update" << std::endl;
	      while (!(std::cin >> student_name) && (student_name.empty()))
		{
		  std::cout << "Empty or invalid name. Please try again" << std::endl;
		  std::cin.clear();
		  std::cin.ignore(255, '\n');
		}
	      std::cout << "Name to update : " << student_name << std::endl;
	      for (std::string line : file_content)
		{
		  if (student_name.compare(line) == 0)
		    {
		      found = true;
		      break;
		    }
		  else
		    position++;
		}
	      if (!found)
		std::cout << "Not found ! Try again !" << std::endl;
	    }
	  if ((count_of_element = std::count(file_content.begin(), file_content.end(), student_name)) > 0)
	    {
	      std::cout << "There is " << count_of_element << " element(s) corresponding the given student name. Please enter the new name with which you want to replace this / these occurrence(s): " << std::endl;
	      while (!(std::cin >> replace_student_name) && (replace_student_name.empty()))
		{
		  std::cout << "Empty or invalid name. Please try again" << std::endl;
		  std::cin.clear();
		  std::cin.ignore(255, '\n');
		}
	      std::replace(file_content.begin(), file_content.end(), student_name, replace_student_name);
	    }
	  else
	    {
	      std::cout << "There is no entries corresponding the name \"" << student_name << " in the file you indicated." << std::endl;
	      return (-3);
	    }
	  for (std::string line : file_content)
	    {
	      file << line;
	      file << "\n";
	    }
	  file.close();
	}
      else 
	{
	  std::cout << "something goes wrong with the read_file_opener. Exiting" << std::endl;
	  return (-2);
	} 
    }
 else 
    {
      std::cout << "something goes wrong with the read_file_opener. Exiting" << std::endl;
      return (-1);
    }
  return (0);
}

int delete_student(std::ofstream &file, std::ifstream &rfile)
{
  std::string file_name{};

  get_file_name(file_name); 
  if (read_file_opener(rfile, file_name) == 0)
    {
      std::string line_of_file{};
      std::vector<std::string> file_content{};
      int position{};
      std::string student_name{};
      bool found{false};

      while (std::getline(rfile, line_of_file))
	{
	  file_content.push_back(line_of_file);
	}
      rfile.close();
      
      if (write_file_opener(file, "overwrite", file_name) == 0)
	{
	  while (found == false)
	    {
	      position = 0;
	      std::cout << "Please enter the name of the student to delete" << std::endl;
	      while (!(std::cin >> student_name) && (student_name.empty()))
		{
		  std::cout << "Empty or invalid name. Please try again" << std::endl;
		  std::cin.clear();
		  std::cin.ignore(255, '\n');
		}
	      std::cout << "Name to delete : " << student_name << std::endl;
	      for (std::string line : file_content)
		{
		  if (student_name.compare(line) == 0)
		    {
		      found = true;
		      break;
		    }
		  else
		    position++;
		}
	    }
	  file_content.erase(file_content.begin() + (position));
	  for (std::string line : file_content)
	    {
	      file << line;
	      file << "\n";
	    }
	  file.close();
	}
      else 
	{
	  std::cout << "something goes wrong with the read_file_opener. Exiting" << std::endl;
	  return (-2);
	} 
    }
 else 
    {
      std::cout << "something goes wrong with the read_file_opener. Exiting" << std::endl;
      return (-1);
    }
  return (0);
}

int add_student(std::ofstream &file)
{
  std::string file_name{};

  get_file_name(file_name); 
  if (write_file_opener(file, "append", file_name) == 0)
    {
      std::string student_name{};

      std::cout << "Please enter the name of the student to add" << std::endl;
      while (!(std::cin >> student_name) && (student_name.empty()))
	{
	  std::cout << "Empty or invalid name. Please try again" << std::endl;
	  std::cin.clear();
	  std::cin.ignore(255, '\n');
	}
      std::cout << "Name to record : " << student_name << std::endl;
      file << student_name << std::endl;
    }
  else 
    {
      std::cout << "something goes wrong with the write_file_opener. Exiting" << std::endl;
      return (-1);
    }
  file.close();
  return (0);
}

int choice_selector(int choice)
{
  std::ofstream file{};
  std::ifstream rfile{};

  
  if (choice == 1)
    {
      if (add_student(file) != 0)
	return (-2);
    }
  else if (choice == 2)
    {
      if (delete_student(file, rfile) != 0)
        return (-3);
    }
  else if (choice == 3)
    {
      if (update_student(rfile, file) != 0)
        return (-4);
    }
  else if (choice == 4)
    {
      if (view_all_student(rfile) != 0)
        return (-5);
    }
  else
    {
      std::cout << "Choice " << choice << " is not a valid choice ! " << std::endl;
      return (-1);
    }
  return (0);
}

int main()
{
  int choice{};
  std::cout << "\t\t\tMenu\n1. Add Student\n2. Delete student\n3. Update\n4. View all" << std::endl;
  while (!(std::cin >> choice))
    {
      std::cout << "Wrong choice : NaN" << std::endl;
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
  if (choice_selector(choice) != 0)
    return (-1);
  return (0);
}
