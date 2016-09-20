//typingSpeedChecker
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <conio.h>

void main()
{
	
	using namespace std;

	string input;

	ifstream inputFile("type.txt");

	stringstream strStream;
	strStream << inputFile.rdbuf();
	input = strStream.str();

	cout << input << endl;

	string typed;

	auto begin = chrono::high_resolution_clock::now();


	char a;
	for (int i = 0; i < input.size(); i++)
	{
		a = _getch();
		
		if (a == '\n')
			break;

		if (input.at(i) != a)
		{
			i--;
			continue;
		}

		_putch(a);
		typed.push_back(a);
	}

	auto end = chrono::high_resolution_clock::now();

	cout<< "compare: " << typed.compare(input) << "\ntyping time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() / 1000.0 << "s" << endl;
	

}