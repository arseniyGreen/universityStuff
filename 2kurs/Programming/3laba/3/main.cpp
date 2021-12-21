#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;

void print_matrix(vector<std::vector<int> > &matrix) {
    std::for_each(matrix.begin(), matrix.end(), [](std::vector<int> &ivec) {
        std::for_each(ivec.begin(), ivec.end(), [](int i) {
            std::cout << std::left << std::setw(5) << i;
        });
        std::cout << std::endl;
    });
}

template <class T>
vector<vector<T>> Minm(vector<vector<T>>& matrix)
{
    vector<vector<T>> minm = matrix;
    vector<bool> v;

    for(size_t i = 0; i < minm.size(); i++)
    {
        v.push_back(0);
        for(size_t j = 0; j < minm.size(); j++) minm[i][j] = 0;
    }
    v[0] = 1;
    bool found = false; T max = 0;
    for(size_t i = 0; i < matrix.size(); i++){
        for(size_t j = 0; j < matrix.size(); j++)
            if(matrix[i][j] > max) max = matrix[i][j];
    }
    while(!found)
    {
        T min = max + 1;
        int jn; int in; in = jn = 0;
        for(size_t i = 0; i < v.size(); i++)
            if(v[i] == 1)
                for(size_t j = 0; j < v.size(); j++)
                    if(v[j] == 0)
                        if((min > matrix[i][j]) && (matrix[i][j] != 0))
                        {
                            min = matrix[i][j];
                            jn = j; in = i;
                        }
        minm[in][jn] = min; minm[jn][in] = min;
        v[jn] = 1;
        found = true;

        for(size_t i = 0; i < v.size(); i++)
            if(v[i] == 0) found = false;
    }
    return minm;
}

template <class T>
vector<T> MinimalWay(vector<vector<T>>& matrix, int start)
{
    vector<T> vers;
    vector<int> usedVers;
    for(size_t i = 0; i < matrix.size(); i++)
    {
        vers.push_back(2147483647);
        usedVers.push_back(0);
    }
    vers[start] = 0;
    usedVers[start] = 1;
    bool found = false;
    while(!found)
    {
        for(size_t j = 0; j < matrix.size(); j++)
        {
            if(usedVers[j] == 1)
            {
                for(size_t i = 0; i < matrix.size(); i++)
                    if((vers[i] > matrix[j][i] + vers[j]) && (matrix[j][i] != 0))
                    {
                        vers[i] = matrix[j][i] + vers[j];
                        usedVers[i] = 1;
                    }
            }
            usedVers[j] = 2;
        }
        found = 1;
        for(size_t i = 0; i < matrix.size(); i++)
        {
            if(usedVers[i] != 2) found = 0;
        }
    }
    return vers;
}

int main() {
    vector<vector<int> > mat =
            {
                    {0, 5, 3, 6, 8, 9, 7, 8, 1, 7, 0, 0, 4, 8},
                    {5, 0, 0, 3, 6, 9, 6, 5, 0, 8, 0, 0, 5, 6},
                    {3, 0, 0, 2, 8, 1, 3, 0, 8, 8, 5, 5, 8, 4},
                    {6, 3, 2, 0, 4, 6, 6, 4, 6, 8, 8, 6, 9, 4},
                    {8, 6, 8, 4, 0, 2, 8, 0, 9, 0, 8, 2, 0, 5},
                    {9, 9, 1, 6, 2, 0, 8, 5, 5, 9, 8, 8, 9, 8},
                    {7, 6, 3, 6, 8, 8, 0, 3, 6, 6, 8, 1, 5, 6},
                    {8, 5, 0, 4, 0, 5, 3, 0, 7, 1, 4, 7, 8, 5},
                    {1, 0, 8, 6, 9, 5, 6, 7, 0, 1, 2, 5, 2, 2},
                    {7, 8, 8, 8, 0, 9, 6, 1, 1, 0, 6, 2, 4, 8},
                    {0, 0, 5, 8, 8, 8, 8, 4, 2, 6, 0, 8, 4, 3},
                    {0, 0, 5, 6, 2, 8, 1, 7, 5, 2, 8, 0, 5, 5},
                    {4, 5, 8, 9, 0, 9, 5, 8, 2, 4, 4, 5, 0, 3},
                    {8, 6, 4, 4, 5, 8, 6, 5, 2, 8, 3, 5, 3, 0},
            };

    vector<vector<int>> m = Minm(mat);
    vector<int> v3 = MinimalWay(m, 0);

    for(size_t j = 0; j < mat.size(); j++) std::cout << v3[j] << '\t';
    std::cout << '\n';

    return 0;
}