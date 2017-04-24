#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#define RANK 4
const int MAX_WEYL_S_STR = 30; // Should be 39, but 41 works.

const int w0Length = RANK*(RANK-1)/2; //(RANK*(RANK-1))/2
const int w0array[MAX_WEYL_S_STR] =
{1,2,1,3,2,1}; 

const int alpharootarray[RANK][RANK-1] = { 
{1,1,1}, //Used for rho (half sum of all roots).
{2,-1,0},
{-1,2,-1},
{0,-1,2}};

const int InverseMatrixForWeightToRootConversion[RANK-1][RANK-1] = { 
{3,2,1},
{2,4,2},
{1,2,3}};

const int allroots[(RANK-1)*(RANK-2)][RANK-1] = { //explicit roots in root notation
{1,0,0},
{0,1,0},
{0,0,1},
{1,1,0},
{0,1,1},
{1,1,1}};



#endif
