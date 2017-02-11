#include <fstream>
#include <string>
#include "weight.h"
#include "weylstr.h"
#include "globlals.h"

//Change RANK in globals.h

int main() {

  const Weight rho(alpharootarray[0]); //the constant rho
  const Weight& weightY = Weight(); //this is our "goal" weight
  const WeylStr stringX = ; //initialize our string in the C- alcove


  for(int i=1; i<=RANK; i++){
    
    const Weight weightX = stringX.DotOn((-2)*rho);
    stringX.Append_S(i);
    const Weight weightNewX = stringX.DotOn((-2)*rho);

    bool tfinished = TRUE;
    
    for(int j=0; j<=((RANK-1)*(RANK-2)); j++) { //bounds valid only for type A!!!

      const Weight alpha(allroots[j*(RANK-1)]);
      
      int m = innerprod(weightY, rho, alpha) - innerprod(weightX, rho, alpha);
      int n = innerprod(weightY, rho, alpha) - innerprod(weightNewX, rho, alpha);

      int r = m % PRIME;
      int q = n % PRIME;

      if( ((m-r) / PRIME) >> ((n-q) / PRIME)){
	stringX.ChopOffLastiElements(1);
	tfinished = FALSE;
	break;
      }
      
      else if( ((m-r) / PRIME) == ((n-q) / PRIME)) tfinished = FALSE;


    }

    if(tfinished == TRUE) break; 


  }


}


int innerprod(weight A, weight B, weight Root){
  
  Weight C = A + B;
  int sum = 0;

  for(int i=0; i <= (RANK-1); i++){

    sum += C[i] * Root[i];

  }


}
