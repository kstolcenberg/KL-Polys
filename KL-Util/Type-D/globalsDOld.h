#ifndef GLOBALTVAR_H
#define GLOBALTVAR_H

//RANK should be the only thing that needs to be changed.
#define RANK 7

#define STRINGIFY(X) #X
#define TOSTRING(X) STRINGIFY(X)
#define GRAPH_FILE "graph-" TOSTRING(RANK) "," TOSTRING(RANK) "-D-Big.film" 
//Change back from BIG after running for large 7,8 cases

#if RANK==4
#define MAX_WEIGHT {2,2,2}
#define ALPHAT {1,0,1}
#include "globals-4D.h"
#elif RANK==5
#define MAX_WEIGHT {4,3,4,4}
#define ALPHAT {0,1,0,0}
#include "globals-5D.h"
#elif RANK==6
#define MAX_WEIGHT {14,14,14,14,14}//(p-2)rho - alpha0
#define ALPHAT {0,1,0,0,0}
#include "globals-6D.h"
#elif RANK==7
#define MAX_WEIGHT {18,18,18,18,18,18} //(4p-2)rho  Previously:(p-2)-alpha0
#define ALPHAT {0,1,0,0,0,0}
#include "globals-7D.h"
#elif RANK==8
#define MAX_WEIGHT {46,46,46,46,46,46,46}
#define ALPHAT {0,1,0,0,0,0,0}
#include "globals-8D.h"
#elif RANK==9
#define MAX_WEIGHT {6,7,7,7,7,7,7,6}
#define ALPHAT {0,1,0,0,0,0,0,0}
#include "globals-9D.h"
#endif

#define PRIME (2*RANK)-4

#endif
