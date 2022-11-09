#include "Stack.h"
#include <fstream>
using namespace std;

void fileReading(int**&, int&);
void regrowRow(int*&, int&, const int&);
int* copier(const int*, const int&);
void regrowColumn(int**&, int&, const int*, const int&);
void findingWayInMaze(Stack<char>&, int** const, const int&);
void updatingMaze(Stack<char>&, int** const, const int&);
void outputFileGenerator(int** const, const int&);
void consoleOutput(int** const, const int&);

int main()
{
	int** maze = nullptr;
	int sizeOfMaze = 0;

	fileReading(maze, sizeOfMaze);	//READING DATA FROM FILE TO 2D ARRAY

	Stack<char> mazeSolution(sizeOfMaze * sizeOfMaze);	//CREATING STACK OF SIZE N*N

	findingWayInMaze(mazeSolution, maze, sizeOfMaze);	//FINDING THE SOLUTION FOR GIVEN MAZE, AND STORING IT IN STACK

	updatingMaze(mazeSolution, maze, sizeOfMaze);	//UPDATING MAZE ARRAY WITH 2's AND 0's FOR OUTPUT

	outputFileGenerator(maze, sizeOfMaze);	//PRINTING FINAL OUTPUT IN FILE

	consoleOutput(maze, sizeOfMaze);	//PRINTING FINAL OUTPUT ON SCREEN

	//DELETING DYNAMIC MEMORY
	for (int i = 0; i < sizeOfMaze; i++) {
		delete[]maze[i];
	}

	delete[]maze;
	maze = nullptr;

	return 0;
}

void fileReading(int**& maze, int& sizeOfMaze)
{
	ifstream fin;
	fin.open("input.txt");

	int num = 0;	//READING DATA/NUMBER FROM FILE
	char ch = 0;	//FOR READING SPACE AND END LINE CHARACTER

	int** arr = nullptr;
	int sizeA = 0;

	int* ptr = nullptr;
	int sizeP = 0;

	if (!fin.is_open()) {
		cout << "File not found!" << endl;
	}
	else {

		while (fin >> num) {

			regrowRow(ptr, sizeP, num);
			fin.get(ch);
			if (ch == '\n') {
				regrowColumn(arr, sizeA, ptr, sizeP);
				delete[]ptr;
				ptr = nullptr;
				sizeP = 0;
			}

		}

	}

	maze = arr;
	sizeOfMaze = sizeA;

	fin.close();
}

void regrowRow(int*& row, int& rowLength, const int& value)
{
	int* temp = new int[rowLength + 1]{};
	for (int i = 0; i < rowLength; i++) {
		temp[i] = row[i];
	}
	temp[rowLength] = value;
	++rowLength;

	if (row != nullptr) {
		delete[]row;
		row = nullptr;
	}
	row = temp;
}

int* copier(const int* row, const int& rowLength)
{
	int* temp = new int[rowLength] {};
	for (int i = 0; i < rowLength; i++) {
		temp[i] = row[i];
	}

	return temp;
}

void regrowColumn(int**& col, int& colLength, const int* row, const int& rowLength)
{
	int** temp = new int* [colLength + 1]{};
	for (int i = 0; i < colLength; i++) {
		temp[i] = copier(col[i], rowLength);
	}
	temp[colLength] = copier(row, rowLength);

	if (col != nullptr) {
		for (int i = 0; i < colLength; i++) {
			delete[]col[i];
		}
		delete[]col;
		col = nullptr;
	}

	++colLength;
	col = temp;
}

void findingWayInMaze(Stack<char>& myStack, int** const maze, const int& sizeOfMaze)
{
	int posX = 0;
	int posY = 0;

	while (1) {

		if (posY != sizeOfMaze && maze[posX][posY + 1] == 1) {	//MOVE RIGHT

			char tempVal = myStack.pop();
			if (tempVal == 'L') {	//OPPOSITE OF RIGHT IS LEFT, BACKTRACK
				maze[posX][posY] = -1;
			}
			else {

				if (tempVal == 'R' || tempVal == 'D' || tempVal == 'U' || tempVal == 'L') {
					myStack.push(tempVal);
				}

				myStack.push('R');

			}

			posY += 1;

		}
		else if (posX != sizeOfMaze && maze[posX + 1][posY] == 1) {	//MOVE DOWN

			char tempVal = myStack.pop();
			if (tempVal == 'U') {	//OPPOSITE OF DOWN IS UP, BACKTRACK
				maze[posX][posY] = -1;
			}
			else {

				if (tempVal == 'R' || tempVal == 'D' || tempVal == 'U' || tempVal == 'L') {
					myStack.push(tempVal);
				}

				myStack.push('D');

			}

			posX += 1;

		}
		else if (posX != 0 && maze[posX - 1][posY] == 1) {	//MOVE UP

			char tempVal = myStack.pop();
			if (tempVal == 'D') {	//OPPOSITE OF UP IS DOWN, BACKTRACK
				maze[posX][posY] = -1;
			}
			else {

				if (tempVal == 'R' || tempVal == 'D' || tempVal == 'U' || tempVal == 'L') {
					myStack.push(tempVal);
				}

				myStack.push('U');

			}

			posX -= 1;

		}
		else if (posY != 0 && maze[posX][posY - 1] == 1) {	//MOVE LEFT

			char tempVal = myStack.pop();
			if (tempVal == 'R') {	//OPPOSITE OF LEFT IS RIGHT, BACKTRACK
				maze[posX][posY] = -1;
			}
			else {

				if (tempVal == 'R' || tempVal == 'D' || tempVal == 'U' || tempVal == 'L') {
					myStack.push(tempVal);
				}

				myStack.push('L');

			}

			posY -= 1;

		}

		if (posX == sizeOfMaze - 1 && posY == sizeOfMaze - 1) {
			break;
		}

	}

}

void updatingMaze(Stack<char>& myStack, int** const maze, const int& sizeOfMaze)
{
	/*NOW WE WILL READ MAZE IN REVERSE ORDER (i.e. start == N-1) CAUSE STACK WILL POP IT'S SOLUTION IN REVERSE
	  ORDER AND EVERYTHING HERE MEANS REVERSE*/

	int posX = sizeOfMaze - 1;
	int posY = sizeOfMaze - 1;

	while (1) {

		char temp = myStack.pop();
		maze[posX][posY] = 2;
		if (temp == 'R') {	//OPPOSITE OF RIGHT IS LEFT
			posY -= 1;
		}
		else if (temp == 'D') {	//OPPOSITE OF DOWN IS UP
			posX -= 1;
		}
		else if (temp == 'U') {	//OPPOSITE OF UP IS DOWN
			posX += 1;
		}
		else if (temp == 'L') {	//OPPOSITE OF LEFT IS RIGHT
			posY += 1;
		}
		else {
			break;
		}

	}
	//REPLACING EVERY NUMBER OTHER THAN 2 WITH 0
	for (int i = 0; i < sizeOfMaze; i++) {
		for (int j = 0; j < sizeOfMaze; j++) {
			if (maze[i][j] != 2) {
				maze[i][j] = 0;
			}
		}
	}

}

void outputFileGenerator(int** const maze, const int& sizeOfMaze)
{
	ofstream fout;
	fout.open("output.txt");

	for (int i = 0; i < sizeOfMaze; i++) {
		for (int j = 0; j < sizeOfMaze; j++) {
			fout << maze[i][j] << " ";
		}
		fout << endl;
	}

	fout.close();
}

void consoleOutput(int** const maze, const int& sizeOfMaze)
{
	for (int i = 0; i < sizeOfMaze; i++) {
		for (int j = 0; j < sizeOfMaze; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}