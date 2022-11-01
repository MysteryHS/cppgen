#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#ifndef __SOLUTION__
#define __SOLUTION__

class Solution {
 public:
  virtual Solution *cross(const Solution &other) const = 0;
  virtual Solution *mutate() const = 0;
  virtual int evaluate() const = 0;
};

template<typename T>
void removeList(std::vector<T> *vect, std::set<int> indexSet){
  std::set<int>::reverse_iterator rit;
  // for(rit=indexSet.rbegin(); rit!=indexSet.rend(); rit++){
  //   std::cout << *rit << std::endl;
  // }
  for(rit=indexSet.rbegin(); rit!=indexSet.rend(); rit++){
    vect->erase(vect->begin() + *rit);
  }
}

template<typename T>
void displayVector(std::vector<T> *list){
  for(T & element : *list){
    std::cout << element.evaluate() << ", ";
  }
  std::cout << std::endl;
}

template<typename T>
void tournament(std::vector<T>* listSolutions){
  int size = listSolutions->size();
  std::set<int> indexSet;
  while ((int)indexSet.size() < size/2){
    int firstIndex = rand() % size;
    int secondIndex = rand() % size;
    while (secondIndex == firstIndex) {
      secondIndex = rand() % size;
    }
    int indexRemoved = (listSolutions->at(firstIndex).evaluate() < listSolutions->at(secondIndex).evaluate() ? secondIndex : firstIndex);
    indexSet.insert(indexRemoved);
  }
  removeList(listSolutions, indexSet);
}

template<typename T>
void iterate(std::vector<T> *currentSol) {
  tournament(currentSol);
  int newSize = currentSol->size();
  for (int i = 0; i < newSize; i++) {
    if (rand() % 100 > 16) {
      int firstIndex = rand() % newSize;
      int secondIndex = rand() % newSize;
      T first = currentSol->at(firstIndex);
      T second = currentSol->at(secondIndex);
      currentSol->push_back(*first.cross(second));
    } else {
      currentSol->push_back(*currentSol->at(rand() % newSize).mutate());
    }
  }
}

template<typename T>
int getBestSol(const std::vector<T> *currentSol) {
  int bestIndex = 0;
  int bestEvaluation = currentSol->at(0).evaluate();
  int size = currentSol->size();
  for (int i = 1; i < size; i++) {
    int currentEval = currentSol->at(i).evaluate();
    if (currentEval < bestEvaluation) {
      bestEvaluation = currentEval;
      bestIndex = i;
    }
  }
  return bestIndex;
}



#endif