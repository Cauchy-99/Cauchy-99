#include "CATMathPoint.h"
#include <cstdlib>
CATMathPoint::CATMathPoint()
    : m_X(rand() % 100 + 1), m_Y(rand() % 100 + 1),
      m_Z(rand() % 100 + 1) {
}


CATMathPoint::CATMathPoint(int iX, int iY, int iZ)
    : m_X(iX), m_Y(iY), m_Z(iZ){
}
