#include "Solution.h"
#include "SolutionQueen.h"

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void display(const char str[]) {
  cout << endl
       << str << endl;
}

int main(int, char *[]) {
  const int size = 16;
  srand(time(0));

  vector<SolutionQueen *> init = initVector<SolutionQueen>(size);

  int resIndex = getBestSol(init);
  cout << "Best score of the initial set of solution = "
       << init[resIndex]->evaluate() << endl;

  iterate(init, 1000);

  resIndex = getBestSol(init);
  cout << "Best score of the final set of solution = "
       << init[resIndex]->evaluate() << endl;
  init[resIndex]->display();

  destroyVector(init);
}