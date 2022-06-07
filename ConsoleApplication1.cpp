#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

int task17(int n);
void stringDelimiter();
void task41();

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	task41();

	return 0;
}

int factorial(int n)
{
	if (n < 0) return 0;
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

string task1()
{
	int x, y;
	cout << "Enter x & y: ";
	cin >> x >> y;

	if (x > -1 && x < 3 && y <4 && y > -2)
	{
		return "Include";
	}
	return "Not include";	
}
string task2() 
{
	int x1 = -2, y1 = -3;
	int x2 = 2, y2 = -3;
	int x3 = 0, y3 = 2;
	int x0, y0;
	cout << "Enter x & y: ";
	cin >> x0 >> y0;
	int A1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
	int A2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
	int A3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
	if (A1 >= 0 && A2 >= 0 && A3 >= 0)
	{
		return "Include";
	}
	return "Not include";	
}
string task3()
{
	int x, y;
	cout << "Enter x & y: ";
	cin >> x >> y;

	if (x > -3 && x < 5 && y <4 && y > -1)
	{
		return "Include";
	}
	return "Not include";
}

void task12()
{
	int a, b, h;
	double y;
	cout << "\nEnter a";
	cin >> a;
	cout << "\nEnter b";
	cin >> b;
	cout << "\nEnter h";
	cin >> h;

	for (int i = a; i < b; i+=h)
	{
		y = (3.8 * pow(i, 3) - 1) / (1 / 16 * pow(i, 2) + 2);
		cout << setw(4) << i << setw(4) << y;
	}
}
double task14()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	int fact = factorial(n);
	int summ = 0;
	for (int i = 1; i < n; i++)
	{
		summ += i;
	}
	return fact / summ;
}
int task17(int n)
{
	int result = 1;
	for (int i = 1; i < n; i++)
	{
		if (i % 3 == 0)
			result *= i;
	}
	return result;
}
void stringDelimiter()
{
	char str[100];
	cout << "Enter string: ";
	gets_s(str);
	char* next_token = nullptr;
	cout << "Разделение строки " << str << " на лексемы:" << endl;
	char* pch = strtok_s(str, " ", &next_token);
	while (pch != nullptr)
	{
		cout << pch << endl;
		pch = strtok_s(next_token, " ,.-", &next_token);
	}
}

void task41()
{
	char str[100], seek[100];
	char endChar;
	int polindrom = 0, wordEndCount = 0;
	cout << "Enter string: ";
	gets_s(str);
	cout << "Enter word to seek: ";
	gets_s(seek);
	cout << "Enter a char: ";
	cin >> endChar;
	char* nextToken = nullptr;	
	char* subString = strtok_s(str, " ", &nextToken);
	char* maxToken = _strdup(subString);
	while (subString != nullptr)
	{
		if (strcmp(subString, maxToken) == 1)
		{
			maxToken = _strdup(subString);
		}
		if (subString[strlen(subString) - 1] == endChar) wordEndCount++;
		// Palindrom check
		int beginWord = 0;
		int endWord = strlen(subString) - 1;
		bool isPalindrom = true;
		while (beginWord <= endWord)
		{
			if (subString[beginWord] != subString[endWord])
			{
				isPalindrom = false;
				break;
			}
			beginWord++;
			endWord--;
		}
		if (isPalindrom) polindrom++;
		// end palindrom check

		if (strlen(subString) % 2 == 1)
		{			
			for (int i = 0; i < strlen(subString); i++)
			{
				if(i != strlen(subString) / 2)
					cout << subString[i];
			}
			cout << endl;
		}
		else if (strcmp(seek, subString) == 0) 
		{
			cout << "Got it" << endl;
			for (int i = 1; i < strlen(subString); i++)
			{
				cout << subString[i];
			}
			int wer = 1;
			cout << subString[0] << endl;
		}
		else
		{
			cout << subString << endl;
		}
		
		subString = strtok_s(nextToken, " ", &nextToken);
	}

	cout << "Polindrom count = " << polindrom << endl;
	cout << "Word end count = " << wordEndCount << endl;
	cout << "Max word: " << maxToken << endl;
}