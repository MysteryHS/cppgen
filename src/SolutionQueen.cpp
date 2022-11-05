#include "SolutionQueen.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

SolutionQueen::SolutionQueen(int size) {
  _size = size;
  _array = nullptr;
  if (size != 0) {
    _array = new int[size];

    for (int i = 0; i < size; i++) {
      _array[i] = rand() % size;
    }
  }
}

SolutionQueen::~SolutionQueen() {
  delete[] _array;
}

SolutionQueen::SolutionQueen(const SolutionQueen &sol) {
  _size = sol._size;
  _array = new int[_size];
  memcpy(_array, sol._array, sizeof(int) * _size);
}

SolutionQueen SolutionQueen::operator=(const SolutionQueen &sol) {
  delete[] _array;
  _size = sol._size;
  _array = new int[_size];
  memcpy(_array, sol._array, sizeof(int) * _size);
  return *this;
}

SolutionQueen SolutionQueen::operator=(SolutionQueen &&other) {
  delete[] _array;
  _size = other._size;
  _array = other._array;
  other._array = nullptr;
  return *this;
}

void SolutionQueen::display() const {
  for (int i = 0; i < _size * 2 + 1; i++) {
    cout << "-";
  }
  cout << endl;
  for (int j = 0; j < _size * 2; j++) {
    for (int i = 0; i < _size * 2; i++) {
      if (i == 0) {
        if (j % 2) {
          cout << "-";
        } else {
          cout << "|";
        }
      }
      if (j % 2) {
        cout << "-";
      } else if (i % 2 == 1) {
        cout << "|";
      } else if (_array[j / 2] == i / 2) {
        cout << "Q";
      } else {
        cout << " ";
      }
      if (i == _size * 2 - 1) {
        cout << endl;
      }
    }
  }
}

bool sameDiag(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) == abs(y1 - y2);
}

int SolutionQueen::evaluate() const {
  int result = 0;
  // check same column
  set<int> set1(_array, _array + _size);
  result += (_size - set1.size()) * 10;

  // check same diag
  for (int i = 0; i < _size; i++) {
    for (int j = 1; j < _size; j++) {
      if (i - j >= 0) {
        if (sameDiag(i, _array[i], i - j, _array[i - j])) {
          result += 10;
        }
      }
    }
  }

  return result;
}

SolutionQueen *SolutionQueen::cross(const Solution &other) const {
  const SolutionQueen *sol = dynamic_cast<const SolutionQueen *>(&other);
  if (sol == nullptr || sol->_size != _size) {
    throw "Argument is not valid (either wrong class or wrong array size)";
  }
  SolutionQueen *crossed = new SolutionQueen(_size);
  for (int i = 0; i < _size / 2; i++) {
    crossed->_array[i] = _array[i];
  }
  for (int i = 0; i < _size / 2; i++) {
    crossed->_array[i + _size / 2] = sol->_array[i];
  }
  return crossed;
}

SolutionQueen *SolutionQueen::mutate() const {
  SolutionQueen *res = new SolutionQueen(_size);
  memcpy(res->_array, _array, sizeof(int) * _size);
  int index = rand() % _size;
  res->_array[index] = ((res->_array[index]) + (rand() % 2 ? 1 : -1) + _size) % _size;
  return res;
}