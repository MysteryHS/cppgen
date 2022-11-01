#include "Solution.h"
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <set>

#ifndef __SOLUTIONQUEEN__
#define __SOLUTIONQUEEN__

class SolutionQueen : public Solution{
 public:
  int *_array;
  int _size;

  SolutionQueen(int size = 5);
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