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

int main(int argc, char *argv[]) {
  if (argc < 4) {
    cout << "Not enough arguments given" << endl;
    cout << "Use : $" << argv[0] << " sizeOfSet nbOfIterations ratioMutate" << endl;
    exit(EXIT_FAILURE);
  }

  const int sizeofSet = stoi(argv[1]);
  const int nbOfIterations = stoi(argv[2]);
  const int ratioMutate = stoi(argv[3]);
  srand(time(0));

  vector<SolutionQueen *> init = initVector<SolutionQueen>(sizeofSet);

  int resIndex = getBestSol(init);
  cout << "Best score of the initial set of solution = "
       << init[resIndex]->evaluate() << endl;

  iterate(init, nbOfIterations, ratioMutate);

  resIndex = getBestSol(init);
  cout << "Best score of the final set of solution = "
       << init[resIndex]->evaluate() << endl;
  init[resIndex]->display();

  destroyVector(init);
}