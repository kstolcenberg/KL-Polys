#include <list>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include "weylstrD.h"
#include "weightD.h"
#include "globalsD.h"

//Change RANK in globalsD.h

const int mMax[] = MAX_WEIGHT;
const int MaxLengthPlusOne = MAX_LENGTH_PLUS_ONE;
const Weight& mMaxWeight = Weight(mMax);
const Weight& mMaxRoot = ConvertToRootNotation(mMaxWeight);
const Weight mZero;

class Entry
{
public:
	Entry(const WeylStr aWeylStr, const Weight aWeight, int aIndex) : mWeylStr(aWeylStr), mWeight(aWeight) 
	{
		mIndex = aIndex;
		for(int i = 0; i < RANK; i++)
			mEdges[i] = 0;
	}
	WeylStr mWeylStr;
	Weight mWeight;
	int mEdges[RANK];
	int mIndex;
};

/*
bool isDominantAndLimited(const Weight& aTest) // should technically use weights for this, but roots SHOULD work
{
	return (mZero <= aTest && aTest <= mMaxRoot);	
}
*/

bool isDominantAndLimited(const Weight& aTest) //Only checking dominant, but retaining function name
{ 
  return (mZero <= aTest);
}



Entry* init()
{
	WeylStr tStartString(w0array);
	Entry* tStart = new Entry(tStartString,tStartString.DotOn((-2)*Weight(alpharootarray[0])),1);
	for(int j = 0; j < RANK; j++)
		tStart->mEdges[j] = 1;
	return tStart;
}

int main() 
{
	vector<Entry*> *tNMinus = new vector<Entry*>();
	vector<Entry*> *tN = new vector<Entry*>();
	vector<Entry*> *tNPlus = new vector<Entry*>();
	ofstream mFile(GRAPH_FILE);
	ofstream oWeights("Weights.tmp");
	ofstream oLengths("Lengths.tmp");
	ofstream oEdges("Edges.tmp");
	ofstream mDebug("Debug.txt");

	const Weight rho(alpharootarray[0]); //The constant rho.
	

	//Need to initialize computation with the zero weight.
	tN->push_back(init());

	bool tFinish = false;
	bool tLastOne = false;
	int tCount = 0;
	while(!tFinish)
	{
	  mDebug << "entering loop" << tCount << "\n"; 
	  //    mDebug << tFinish << "tFinish 1\n";
	  if(tLastOne){
		  mDebug << "ending";
			tFinish = true;
	  }
	/*  else if(tN->size()==0){
	    mDebug << "size 0, ending";
	    tFinish = true;
	  }
	*/
		for(unsigned int k = 0; k < tN->size(); k++)
		{
		  //	        mDebug << tFinish << "tFinish 1.25\n";
			//Get the current weight information.
			const WeylStr& tString = tN->at(k)->mWeylStr;
			const Weight& tCurrentWeight = tN->at(k)->mWeight;
			const Weight& tCurrentRoot = ConvertToRootNotation(tCurrentWeight);

			mDebug << tFinish << "tFinish 1.5\n";

			for(int i = 0; i < RANK; i++)
			{
			  mDebug <<"Calculating new weight\n";
			  //mDebug << tFinish << "tFinish 2\n";
				//Calculate new weight based off the current with s_i.
				WeylStr tNew(tString);
				tNew.Append_S(i+1);
				const Weight& tNewWeight = tNew.DotOn((-2)*rho);
				const Weight& tNewRoot = ConvertToRootNotation(tNewWeight);

				if (isDominantAndLimited(tNewRoot)) //Check that the properties hold.
				{
				  mDebug << "Checking that properties hold\n";
				  //	  mDebug << tFinish << "tFinish 3\n";
					if(tCurrentRoot == tNewRoot)
					  {
					        mDebug << "adding weight to file\n";
						//	mDebug << tFinish << "tFinish 4\n";
						tN->at(k)->mEdges[i] = tN->at(k)->mIndex; 

					  }	
					else if(tNewRoot < tCurrentRoot)
					{
					  mDebug << "looking for repeated root\n";
					  //	  mDebug << tFinish << "tFinish 5\n";
						//Look through the list to find where we have computed this weight already.
						for(unsigned int j = 0; j < tNMinus->size(); j++)
							if(tNMinus->at(j)->mWeight == tNewWeight)
							{
								tN->at(k)->mEdges[i] = tNMinus->at(j)->mIndex;
								break;
							}
						if(tN->at(k)->mEdges[i] == 0) //Note that if we didn't find it we were actually looking for  ourselves.
							tN->at(k)->mEdges[i] = tN->at(k)->mIndex; 
					}
					else if ((tCurrentRoot < tNewRoot) && !tFinish)
					{
					  mDebug << "tCount else if loop\n";
					  // mDebug << tFinish << "tFinish 6\n";
						//Look through the list to find where we have computed this weight already.
						bool tFound = false;
						for(unsigned int j = 0; j < tNPlus->size(); j++)
							if(tNPlus->at(j)->mWeight == tNewWeight)
							{
							        mDebug << "Break Condition Met\n"; 
								//			mDebug << tFinish << "tFinish 7\n";
								tN->at(k)->mEdges[i] = tNPlus->at(j)->mIndex;
								tFound = true;
								break;
							}
						if(!tFound) //Note that if we didn't find it then we can add it
						{
							tCount++;
							mDebug << "tCount ="<< tCount << "\t";
							//mDebug << tFinish << "tFinish 8\n";
							tN->at(k)->mEdges[i] = tCount; //Note not off by one since edges are not zero-valued;
							Entry* tEntry = new Entry(tNew, tNewWeight, tCount);
							tNPlus->push_back(tEntry);
							int currentLength = tNew.GetLength();
							mDebug << "currentLength =" << currentLength << "\n";
							//mDebug << tFinish << "tFinish 9\n";
							int tmp = MaxLengthPlusOne + w0Length;
							if(currentLength == tmp)
							//if(tNewWeight == mMaxWeight)
								tLastOne = true;
						}
					}
					/*	else if ((tCurrentRoot < tNewRoot) && tFinish)
					  {
					    mDebug << "error: tCurrentRoot < tNewRoot && tFinish\n";
					    mDebug << "tCurrentRoot=" << tCurrentRoot << "\n";
					    mDebug << "tNewRoot=" << tNewRoot << "\n";
					    //mDebug << tFinish << "tFinish 10\n";
					    if (!tFinish)
					      mDebug << "tFinish is false\n";
					    if (tLastOne)
					      mDebug << "tLastOne is true\n";
					    else 
					      mDebug << "tLastOne is false\n";
					    mDebug << "tCount=" << tCount << "\n";


					    }
					*/    
				}
			}
		}

		for(unsigned int i = 0; i < tNMinus->size(); i++)
		{
			oWeights << tNMinus->at(i)->mWeight << '\n';
			oLengths << tNMinus->at(i)->mWeylStr.GetLength() << '\n';
			oEdges << tNMinus->at(i)->mEdges[0];
			for(int j = 1; j < RANK; j++)
				oEdges << ' ' << tNMinus->at(i)->mEdges[j];
			oEdges << endl;
		}

		delete tNMinus;
		tNMinus = tN;
		tN = tNPlus;
		tNPlus = new vector<Entry*>();
	}

	for(unsigned int i = 0; i < tNMinus->size(); i++)
	{
		oWeights << tNMinus->at(i)->mWeight << '\n';
		oLengths << tNMinus->at(i)->mWeylStr.GetLength() << '\n';
		oEdges << tNMinus->at(i)->mEdges[0];
		for(int j = 1; j < RANK; j++)
			oEdges << ' ' << tNMinus->at(i)->mEdges[j];
		oEdges << endl;
	}

	oWeights.close();
	oLengths.close();
	oEdges.close();

	ifstream iWeights("Weights.tmp");
	ifstream iLengths("Lengths.tmp");
	ifstream iEdges("Edges.tmp");

	std::string tLine;
	while(std::getline(iWeights,tLine))
		mFile << tLine << '\n';
	while(std::getline(iLengths,tLine))
		mFile << tLine << '\n';
	while(std::getline(iEdges,tLine))
		mFile << tLine << '\n';

	iWeights.close();
	iLengths.close();
	iEdges.close();

	remove("Weights.tmp");
	remove("Lengths.tmp");
	remove("Edges.tmp");

	mDebug.close();
	mFile.close();
}
