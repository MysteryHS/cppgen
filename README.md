# Implementation of genetic algorithm using C++

This repo was created to learn some C++, mainly OOP using C++.

The goal is was to make a general class that you could extend to create your own
solutions using genetic algorithm. You simply need to extend the class Solution
and to implements the methods cross, mutate and evaluate.

An example was made with the class SolutionQueen, resolving the queen problem
where on a chess board, you need to find a placement for N queens so that they
cannot take each other.

## Usage

Compile : ```$make```  
Run : ```$./main```  
Clean : ```$make clean```  

## TODO

Add the possibility to pass argument to the constructor with the initVector function.
Add the possibility to changes the frequency of mutate / cross.
Add arguments to the program to pilot it without needing to recompile.