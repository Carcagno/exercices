#include <iostream>
#include <string>

class IntPair
{
public:
  int m_int1, m_int2;

  void set(int int1, int int2)
  {
    m_int1 = int1;
    m_int2 = int2;
  }
  void print()
  {
    std::cout << m_int1 << " " << m_int2 << std::endl;
  }
};

int main()
{
  IntPair p1;
  IntPair p2;

  p1.set(1, 1);
  p2.set(2, 2);

  p1.print();
  p2.print();
  return (0);
}
