#include "SolutionQueen.h"
#include "Solution.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void display(const char str[]) {
  cout << endl << str << endl;
}

int main(int, char *[]) {
  const int size = 16;
  srand(time(0));

  vector<SolutionQueen> init(size);


  int resIndex = getBestSol(&init);
  cout << "Score of result = " << init[resIndex].evaluate() << endl;

  displayVector(&init);
  for (int i = 0; i < 20; i++) {
    iterate(&init);
    displayVector(&init);
  }

  resIndex = getBestSol(&init);
  cout << "Score of result = " << init[resIndex].evaluate() << endl;
  init[resIndex].display();
}