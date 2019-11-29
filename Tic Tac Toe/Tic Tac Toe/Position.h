#ifndef Position_H_
#define Position_H_
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int POSITION_LENGTH = 2;
const int MAX_ARRAY_SIZE = 100;
const int MIN_POS = 0;
const int MAX_POS = 3;

struct Position {
private:
	int x;
	int y;
public:
	void readXandY();
	int getX()const { return x; }
	int getY()const { return y; }
	void setX(int x);
	void setY(int y);
	Position(int x = 0, int y = 0);
	void savePositionInFile(ofstream& ofs) const;
};
#endif // !Position_H_

