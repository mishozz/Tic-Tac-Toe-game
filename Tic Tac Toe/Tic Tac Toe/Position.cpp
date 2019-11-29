#include "Position.h"

void Position::setX(int x)
{
	this->x = x;
}

void Position::setY(int y)
{
	this->y = y;
}

Position::Position(int x, int y)
{
	setX(x);
	setY(y);
}

//inputs X and Y and checks if X and Y are valid;


void Position::savePositionInFile(ofstream & ofs)const
{
	ofs << x << " " << y << endl;
}

//reads X and Y;

void Position::readXandY()
{
	int n;
	char num[MAX_ARRAY_SIZE];
	do
	{
		cin >> num;
		if (strlen(num) > POSITION_LENGTH) {
		    cout << "This position is invalid or already taken. Try again!" << endl;
			cout << "Position: ";
		}	
	} while (strlen(num) > POSITION_LENGTH);
	n = atoi(num);
	y = n % 10;
	x = n / 10;
}


