#include "BST.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
//#include "CLQueue.h"

using namespace std;

BST csvtoBST(string csvfile) { //convert a csv file to a list structure
    BST outBST;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {    
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        int dayholder=0;
		while(getline(ss, curvalue,',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: dayholder = stoi(curvalue); break;
            	case 1: break;
            	case 2: break;
            	case 3: break;
            	case 4: break;
            	case 5: break;
            	case 6: outBST.PutItem(dayholder, stoi(curvalue)); break;
			}
            fielditer++;
        }
    }
    return outBST;
}

int main() {
  BST myBST = csvtoBST("Louisville 2021-01-01 to 2021-12-31.csv");
  
  //  NOTE FOR GRADER: PutItem calls insert values based on the windspeed. The first value of the returned key of the key : value pair is the day number and the value is the windspeed.
  //  The tree is printed in order
  
  cout<<"My Tree: ";
  myBST.PrintTree();
}
