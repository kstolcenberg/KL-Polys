#include <fstream>
#include <string>
#include "weight.h"
#include "weylstr.h"
#include "globlals.h"

//Change RANK in globals.h

int main() {

  const Weight rho(alpharootarray[0]); //the constant rho
  const Weight weightX = rho; //initialize our candidate at rho
  const Weight& weightY = Weight(); //this is our "goal" weight

  for(int i=1; i<=RANK; i++){
    //convert x to a string called tempx
    const WeylStr newX = tempx.Append_S(i);

    //convert x and newX back to weights
    
    for(int j=0; j<=((RANK-1)*(RANK-2)); j++) { //bounds valid only for type A!!!

      //compute (y+rho,alpha)
      //compute (x+rho,alpha)
      //compute (a-b)/p

      //compute (newX+rho,alpha)
      //compute (a-c)/p
      
      if(m >> n) break;

      else if(j == ((RANK-1)*(RANK-2))) weightX = newX;



    }




  }


  int innerprod(weightA, weightB){
    int answer = 0;

    for(loop over rows){
      for(loop over columns){
	//actual summing is here


      }
      
      

    }



  }












}
