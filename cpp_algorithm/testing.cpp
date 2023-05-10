#include "MyService.h"
#include "CATMathPoint.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>

#include "HowToUnique3DPoint.h"
#include "HowToReadText.h"

using namespace std;





int main ()
{
  auto start = std::chrono::system_clock::now();
 
  HowToReadText test = HowToReadText();
  test.Run();

  auto end = std::chrono::system_clock::now();

  auto duration =
  std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << " total time:" << duration.count() << " ms\n";

  std::cin.get();
  return 0;
};