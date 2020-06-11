#include <iostream>
#include <stdlib.h>
using namespace std;

void interface()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "+-+-+-+-+-+-+-+-+-+" << endl;
			cout << "| | | | | | | | | |" << endl;
		}
	}
	cout << "+-+-+-+-+-+-+-+-+-+" << endl;
}

int main()
{
	system("Color 2");
	interface();
}

