#include <iostream>
#include <string>

class Point3d
{
private:
  int m_x, m_y, m_z;

public:
  void setValues(int x, int y, int z)
  {
    m_x = x;
    m_y = y;
    m_z = z;
  }

  void print()
  {
    std::cout << "x = " << m_x << "\ny = " << m_y << "\nz = " << m_z << "\n" << std::endl;
  }

  bool isEqual(Point3d const & p)
  {
    if (p.m_x == m_x && p.m_y == m_y && p.m_z == m_z)
      return (true);
    else
      return (false);
  }
};

int main()
{
  Point3d point1;
  Point3d point2;
  Point3d point3;

  point1.setValues(1, 2, 3);
  point2.setValues(1, 2, 3);
  point3.setValues(4, 4, 4);

  point1.print();
  point2.print();
  point3.print();
  
  std::cout << point1.isEqual(point2) << std::endl;
  std::cout << point1.isEqual(point3) << std::endl;
  
  return (0);
}
