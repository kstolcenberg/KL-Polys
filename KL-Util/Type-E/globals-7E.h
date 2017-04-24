#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#define RANK 7
const int MAX_WEYL_S_STR = 100; //Guess

const int w0Length = 36;//Note that there is no uniform rule for type E
const int w0array[MAX_WEYL_S_STR] =
  {1,2,3,1,4,2,3,1,4,3,5,4,2,3,1,4,3,5,4,2,6,5,4,2,3,1,4,3,5,4,2,6,5,4,3,1}; //Found using sage

const int alpharootarray[RANK][RANK-1] = { //Straightforward to change.
{1,1,1,1,1,1}, //Used for rho (half sum of all roots).
{2,0,-1,0,0,0},
{0,2,0,-1,0,0},
{-1,0,2,-1,0,0},
{0,-1,-1,2,-1,0},
{0,0,0,-1,2,-1},
{0,0,0,0,-1,2}}; 

const int InverseMatrixForWeightToRootConversion[RANK-1][RANK-1] = { //Straightforward to change.
  {8,6,10,12,8,4},
  {6,12,12,18,12,6},
  {10,12,20,24,16,8},
  {12,18,24,36,18,12},
  {8,12,16,24,20,8},
  {4,6,8,12,10,8}};

#endif
