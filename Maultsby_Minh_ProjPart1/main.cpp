#include "AUList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

AUList csvtoAUList(string csvfile) { //convert a csv file to a list structure
    AUList retLouWeatherList;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {    
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        LouWeather2021 newrec;
		while(getline(ss, curvalue,',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.temperature=stod(curvalue); break;
            	case 1: newrec.feelslike=stod(curvalue); break;
            	case 2: newrec.dewpoint=stod(curvalue); break;
            	case 3: newrec.humidity=stod(curvalue); break;
            	case 4: newrec.precipitation=stod(curvalue); break;
            	case 5: newrec.windspeed=stod(curvalue); break;
			}
            fielditer++;
        }
        retLouWeatherList.PutItem(newrec);
    }
    return retLouWeatherList;
}

int main(int argc, char** argv) {
	AUList LouWeatherData=csvtoAUList("Louisville 2021-01-01 to 2021-12-31.csv");
	LouWeatherData.GetNextItem();
	LouWeather2021 Item1 = LouWeatherData.GetNextItem();
	std::cout << "Length: " << LouWeatherData.GetLength() << endl;
	std::cout << Item1.dewpoint << Item1.humidity << Item1.temperature << Item1.feelslike << Item1.precipitation << Item1.windspeed << endl;
	LouWeatherData.PrintList(); //Print the data record-by-record
}
    
