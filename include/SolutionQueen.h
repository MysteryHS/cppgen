#include "Solution.h"

#include <iostream>
#include <iterator>
#include <set>
#include <stdlib.h>

#ifndef __SOLUTIONQUEEN__
#define __SOLUTIONQUEEN__

class SolutionQueen : public Solution {
public:
  int *_array;
  int _size;

  SolutionQueen(int size = 8);
  SolutionQueen(const SolutionQueen &sol);
  ~SolutionQueen();
  void display() const;

  SolutionQueen operator=(const SolutionQueen &other);
  SolutionQueen operator=(SolutionQueen &&other);
  SolutionQueen *cross(const Solution &other) const override;
  SolutionQueen *mutate() const override;
  int evaluate() const override;
};

#endif