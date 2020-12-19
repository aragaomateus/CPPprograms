/*
	Name: UHUHUH
	Copyright: 
	Author: Mateus Silva-Aragao
	Date: 16/12/20 16:47
	Description: 
*/

#include<iostream>
#include<vector>
#include <fstream>
using namespace std;
const int ARRAY_SIZE = 3000;

void fileReader(int numbers[], const int size, int& newSize);
void numbersCounter(int newSize, int numbers[]);

int main(){
	int numbers[ARRAY_SIZE]; 
	int newSize = 0; 
	bool option = true;
	char op = 'y';
	
	while(option == true){
	fileReader(numbers, ARRAY_SIZE, newSize);
	numbersCounter(newSize, numbers);
	cout << "type 'y' to continue 'n' to leave" << endl;
	cin >> op;
	if (op=='y')
		option = true;
	else 
		option = false;
	}
}

void fileReader(int numbers[], const int size, int& newSize)
{	
	string filename;
	ifstream inputFile;
	int count = 0;
	cout << "Enter the filename: ";
	cin >> filename;
	inputFile.open(filename.c_str());
	if (inputFile)
	{
		
		// Parsing the numerical data from .txt file to array.
		while(count < size && inputFile >> numbers[count])
		{
			cout << numbers[count] << " ";
			count++;
		}
		inputFile.close();
	}
	else 
	{
		cout << "Error opening the file.\n"; 
	}
	newSize = count;
}

void numbersCounter(int newSize, int numbers[]){
	int winners[newSize];
	int count = 0, range = 0, frequency = 0;
	int n=0;
	float games;
	cout << "what is the range:" << endl;
	cin >> range;
	cout << "frequency:" << endl;
	cin >> frequency;
	cout << "how many games:" << endl;
	cin >> games;
	cout << newSize << endl;
	do{
		count =0;
		for (int i = 0; i < newSize; i++){
			if (numbers[i] == n)
				count++;
			
		}
	winners[n] = count;	
	n++;
	}while(n < newSize);
	cout << endl;
	for (int i = 0; i< range ; i++){
		if (winners[i] > frequency){
			cout << i << ":" << winners[i] << " precentage: " << (float)(winners[i]/games)*100.0 << endl;
			count++;
		}
	}
	cout << count <<endl;	
}