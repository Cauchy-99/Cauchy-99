#include "MyService.h"
#include "CATMathPoint.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::all_of
#include <array>        // std::array
#include <vector>
#include <ctime>
#include <cstdlib>

#include <numeric>

#include <chrono>

#include <iomanip>

using namespace std;

ostream &operator<<(ostream &out, CATMathPoint &A) {
  out << "(" << A.GetX() << "," << A.GetY() << "," << A.GetZ() << ")";
  return out;
}

bool compare(const CATMathPoint &lhs, const CATMathPoint &rhs) {
  if (lhs.GetX() + 0.001 < rhs.GetX())
    return true;
  else if (abs(lhs.GetX() - rhs.GetX()) < 0.001) {
    if (lhs.GetY() + 0.001 < rhs.GetY())
      return true;
    else if (abs(lhs.GetY() - rhs.GetY()) < 0.001) {
      if (lhs.GetZ() + 0.001 < rhs.GetZ())
        return true;
    }
  }
  return false;
}

class Point3dCompare {
public:
  bool operator()(const CATMathPoint &lhs, const CATMathPoint &rhs) const {
    return compare(lhs, rhs);
  }
};

class uniquePoint3d {
public:
  bool operator()(const CATMathPoint &lhs, const CATMathPoint &rhs) const {
    return (lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() && lhs.GetZ() == rhs.GetZ());
  }
};

int main ()
{
  auto start = std::chrono::system_clock::now();
  vector<CATMathPoint> vecPoint;
  vecPoint.reserve(10000);
  for (int i = 0; i < 10000; i++)
  {
    vecPoint.push_back(CATMathPoint());
  }

  cout << "#before:***********************************************************" << endl;
  int i = 1;
  //for (auto it = vecPoint.begin(); it!=vecPoint.end(); it++){
  //  cout << *it << "\t";
  //  if (i%5 == 0)
  //  {
  //    cout << endl;
  //  }
  //  i++;
  //}

  cout << "#after sort:***********************************************************" << endl;
  i = 1;
  sort(vecPoint.begin(), vecPoint.end(), compare);
  for (auto it = vecPoint.begin(); it != vecPoint.end(); it++) {
    cout << *it << "\t";

    if (i % 5 == 0) {
      cout << endl;
    }
    i++;
  }

  cout << "#after unique:***********************************************************"<< endl;
  i = 1;
  vecPoint.erase(unique(vecPoint.begin(), vecPoint.end(), uniquePoint3d()),vecPoint.end());
  for (auto it = vecPoint.begin(); it != vecPoint.end(); it++) {
    cout << *it << "\t";

    if (i % 5 == 0) {
      cout << endl;
    }
    i++;
  }

  auto end = std::chrono::system_clock::now();

  auto duration =
  std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << " total time:" << duration.count() << " ms\n";

  std::cin.get();
  return 0;
};