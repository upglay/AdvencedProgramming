#include <iostream>	
#include <stdio.h>

using namespace std;

struct vector2D
{
	int x;
	int y;

	void print()
	{
		printf("%d %d", x, y);
	}
};

std::ostream &operator << (std::ostream &stream, vector2D obj)
{
	stream << obj.x << " " << obj.y << std::endl;

	return stream;
}

void main()
{
	vector2D myVector;
	myVector.x = 1;
	myVector.y = 2;

	std::cout << myVector << std::endl;

}