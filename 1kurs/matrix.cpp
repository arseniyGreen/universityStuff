#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void drawMatrix(int matrix[][2] ,int i, int j)
{
    int x = 0, y = 0;
    while (x < j, y < i)
    {
        while (x <= i) //drawing line(x)
        {
        cout << matrix[x][y] << "\t";
        x++;
        }
        cout << endl;
        y++;
    }
}


int main()
{
    srand(time(0));
    int matr1[2][2];
   // int matr2[][];
    int i1, j1, i2, j2; //i - rows j - colums
    matr1[0][0] = rand() % 9;
    matr1[0][1] = rand() % 9;
    matr1[0][2] = rand() % 9;
    matr1[1][0] = rand() % 9;
    matr1[1][1] = rand() % 9;
    matr1[1][2] = rand() % 9;
    matr1[2][0] = rand() % 9;
    matr1[2][1] = rand() % 9;
    matr1[2][2] = rand() % 9;

    drawMatrix(matr1, 2, 2);

    return 0;
}