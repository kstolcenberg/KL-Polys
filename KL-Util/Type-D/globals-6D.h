#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#define RANK 6

const int MAX_WEYL_S_STR = 1000; //huge estimate, really no clue

const  int w0Length = (RANK-1)*(RANK-2);
const int w0array[MAX_WEYL_S_STR] = 
  {1,2,1,3,2,1,4,3,2,1,5,3,2,1,4,3,2,5,3,4};

const int alpharootarray[RANK][RANK-1] = {
  {1,1,1,1,1},
  {2,-1,0,0,0},
  {-1,2,-1,0,0},
  {0,-1,2,-1,-1},
  {0,0,-1,2,0},
  {0,0,-1,0,2}};

const int InverseMatrixForWeightToRootConversion[RANK-1][RANK-1] = {
  {4,4,4,2,2},
  {4,8,8,4,4},
  {4,8,12,6,6},
  {2,4,6,5,3},
  {2,4,6,3,5}}; //multiplied by scalar 4 to ensure integer entries

#endif
