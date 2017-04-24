#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#define RANK 7
const int MAX_WEYL_S_STR = 100; //Guess

const int w0Length = (RANK-1)*(RANK-2); 
const int w0array[MAX_WEYL_S_STR] =
{1,2,1,3,2,1,4,3,2,1,
5,4,3,2,1,6,4,3,2,
 1,5,4,3,2,6,4,3,5,4,6}; 

const int alpharootarray[RANK][RANK-1] = { //Straightforward to change.
{1,1,1,1,1,1}, //Used for rho (half sum of all roots).
{2,-1,0,0,0,0},
{-1,2,-1,0,0,0},
{0,-1,2,-1,0,0},
{0,0,-1,2,-1,-1},
{0,0,0,-1,2,0},
{0,0,0,-1,0,2}}; 

const int InverseMatrixForWeightToRootConversion[RANK-1][RANK-1] = { //Straightforward to change.
  {4,4,4,4,2,2},
  {4,8,8,8,4,4},
  {4,8,12,12,6,6},
  {4,8,12,16,8,8},
  {2,4,6,8,6,4},
  {2,4,6,8,4,6}};

#endif
