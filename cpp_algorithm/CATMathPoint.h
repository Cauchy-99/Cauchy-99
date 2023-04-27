#pragma once
#include <iostream>

class CATMathPoint {
public:
  CATMathPoint();

  CATMathPoint(int iX, int iY, int iZ);

  public:
  inline int GetX() const{
    return m_X;
  };

  inline int GetY() const{
    return m_Y;
  };

  inline int GetZ() const{
    return m_Z;
  };

  private:
  int m_X;
  int m_Y;
  int m_Z;
};

std::ostream &operator<<(std::ostream &out, CATMathPoint &A) {
  out << "(" << A.GetX() << "," << A.GetY() << "," << A.GetZ() << ")";
  return out;
}
