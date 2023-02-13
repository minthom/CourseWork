#define MAXSIZE 366
struct LouWeather2021 {
	double temperature;
	double feelslike;
	double dewpoint;
	double humidity;
	double precipitation;
	double windspeed;
};

class AUList 
{
public:
	AUList();	
	
	void MakeEmpty();
		
	bool IsFull() const;
		
	int GetLength() const;
		
	void PutItem(LouWeather2021);
		
	void ResetList();
		
	LouWeather2021 GetNextItem();
		
	bool HasNextItem();
		
	void PrintList();
		
private:
	int length;
	LouWeather2021 ListItems[MAXSIZE];
	int currentPos;
};

