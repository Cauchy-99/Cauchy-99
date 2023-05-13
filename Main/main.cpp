#include "MyService.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>

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

  system("pause");
  return 0;
};