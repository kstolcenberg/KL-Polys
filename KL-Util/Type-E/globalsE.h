#ifndef GLOBALTVAR_H
#define GLOBALTVAR_H

//RANK should be the only thing that needs to be changed.
#define RANK 7 //This is the only rank that works currently!

#define STRINGIFY(X) #X
#define TOSTRING(X) STRINGIFY(X)
#define GRAPH_FILE "graph-" TOSTRING(RANK) "," TOSTRING(RANK) "-E.film" 

//Note that all Max Lengths are placeholders from type D EXCEPT RANK==7 (E6)

#if RANK==4
#define MAX_WEIGHT {2,2,2}
#define ALPHAT {1,0,1}
#define MAX_LENGTH_PLUS_ONE 20;//placeholder
#include "globals-4D.h"
#elif RANK==5
#define MAX_WEIGHT {4,3,4,4}
#define ALPHAT {0,1,0,0}
#define MAX_LENGTH_PLUS_ONE 40;//placeholder
#include "globals-5D.h"
#elif RANK==6
#define MAX_WEIGHT {14,14,14,14,14}//(p-2)rho - alpha0
#define ALPHAT {0,1,0,0,0}
#define MAX_LENGTH_PLUS_ONE 50;//placeholder
#include "globals-6D.h"
#elif RANK==7
#define MAX_WEIGHT {18,18,18,18,18,18} //(4p-2)rho  Previously:(p-2)-alpha0
#define ALPHAT {0,1,0,0,0,0}
#define MAX_LENGTH_PLUS_ONE 120;//does not include length of w0, (rank-1)*(rank-2)
#include "globals-7D.h"
#elif RANK==8
#define MAX_WEIGHT {46,46,46,46,46,46,46}
#define ALPHAT {0,1,0,0,0,0,0}
#define MAEX_LENGTH_PLUS_ONE 141;//placeholder
#include "globals-8D.h"
#elif RANK==9
#define MAX_WEIGHT {6,7,7,7,7,7,7,6}
#define ALPHAT {0,1,0,0,0,0,0,0}
#define MAX_LENGTH_PLUS_ONE 200;//placeholder
#include "globals-9D.h"
#endif

#define PRIME 12 // Only works for RANK 7 (see Bourbaki). Otherwise (2*RANK)-4 for now

#endif
