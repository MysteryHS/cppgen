#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

#ifndef __SOLUTION__
#define __SOLUTION__

class Solution {
public:
  virtual Solution *cross(const Solution &other) const = 0;
  virtual Solution *mutate() const = 0;
  virtual int evaluate() const = 0;
  virtual ~Solution(){};
};

template <typename T>
concept Sol = requires(T t) {
  dynamic_cast<Solution *>(t);
};

template <Sol T>
void removeList(std::vector<T> &vect, std::set<int> indexSet) {
  std::set<int>::reverse_iterator rit;
  for (rit = indexSet.rbegin(); rit != indexSet.rend(); rit++) {
    delete vect.at(*rit);
    vect.erase(vect.begin() + *rit);
  }
}

template <Sol T>
void displayVector(std::vector<T> *list) {
  for (T &element : *list) {
    std::cout << element->evaluate() << ", ";
  }
  std::cout << std::endl;
}

template <Sol T>
void tournament(std::vector<T> &listSolutions) {
  int size = listSolutions.size();
  std::set<int> indexSet;
  while ((int)indexSet.size() < size / 2) {
    int firstIndex = rand() % size;
    int secondIndex = rand() % size;
    while (secondIndex == firstIndex) {
      secondIndex = rand() % size;
    }
    int indexRemoved = (listSolutions.at(firstIndex)->evaluate() < listSolutions.at(secondIndex)->evaluate() ? secondIndex : firstIndex);
    indexSet.insert(indexRemoved);
  }
  removeList(listSolutions, indexSet);
}

template <Sol T>
void iterate(std::vector<T> &currentSol, const int nbOfIterations, int mutatePercentage) {
  for (int ite = 0; ite < nbOfIterations; ite++) {
    tournament(currentSol);
    int newSize = currentSol.size();
    for (int i = 0; i < newSize; i++) {
      if (rand() % 100 > mutatePercentage) {
        int firstIndex = rand() % newSize;
        int secondIndex = rand() % newSize;
        T first = currentSol.at(firstIndex);
        T second = currentSol.at(secondIndex);
        currentSol.push_back(first->cross(*second));
      } else {
        currentSol.push_back(currentSol.at(rand() % newSize)->mutate());
      }
    }
  }
}

template <Sol T>
int getBestSol(const std::vector<T> &currentSol) {
  int bestIndex = 0;
  int bestEvaluation = currentSol.at(0)->evaluate();
  int size = currentSol.size();
  for (int i = 1; i < size; i++) {
    int currentEval = currentSol.at(i)->evaluate();
    if (currentEval < bestEvaluation) {
      bestEvaluation = currentEval;
      bestIndex = i;
    }
  }
  return bestIndex;
}

template <typename T>
std::vector<T *> initVector(const int size) {
  std::vector<T *> vect(size);
  for (int i = 0; i < (int)vect.size(); i++) {
    vect.at(i) = new T();
  }
  return vect;
}

template <Sol T>
void destroyVector(std::vector<T> &vect) {
  for (int i = 0; i < (int)vect.size(); i++) {
    delete vect.at(i);
  }
}

#endif