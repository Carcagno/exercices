#include <iostream>
#include <string>
#include <array>
#include <cassert>

class Stack
{
private:
  std::array<int, 10> m_stack;
  int m_length;

public:
  void print()
  {
    std::cout << "( ";
    for (int i = 0; i < m_length; ++i)
      {
	std::cout << m_stack[i] << " ";
      }
    std::cout << ")" << std::endl;
  }

  void reset()
  {
    for (int i = 0; i < m_length; ++i)
      {
	m_stack[i] = 0;
      }
    m_length = 0;
  }

  bool push(int n)
  {
    if (m_length < 10)
      {
	m_stack[m_length] = n;
	m_length++;
	return (true);
      } 
    else
      return (false);
  }
  
  int pop()
  {
    int temp{};

    assert(m_length > 0 && "Error : Cannot pop from an empty stack");
    if (m_length > 0)
      {
	m_length--;
	temp = m_stack[m_length];
	m_stack[m_length] = 0;
	return (temp);
      }
    else
      {
	std::cout << "error" << std::endl;
	return (-1);
      }
    
  }

};

int main()
{
  Stack stack;

  stack.reset(); //set to 0 the lenght of the stack and all member of the stack
  stack.print(); //print all setted member of the stack

  stack.push(5); //push a number in the stack
  stack.push(3); 
  stack.push(8); 
  stack.print();

  stack.pop(); //pop the last value of the stack
  stack.print();

  stack.pop();
  stack.pop();
  stack.print();
  
  return (0);
}
