#include <iostream>
#include <vector>
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
   // int matr2[][];
    int i1, j1, i2, j2; //i - rows j - columns
    i1 = 3; //rows
    j1 = 3; //cols

    vector<vector<int>> matrix1;
    for (int i = 0; i < i1; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i1; j++)
        {
            temp.push_back(rand() % 9);
        }

        matrix1.push_back(temp);

    }

    for (int i = 0; i < matrix1.size(); i++)
    {
        for(int j = 0; j < matrix1[i].size(); j++){
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}