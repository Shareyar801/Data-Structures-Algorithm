//video explanation: https://www.youtube.com/watch?v=pgNE06YbDZ8&ab_channel=GateSmashers
//thoery + source code: https://www.programiz.com/dsa/floyd-warshall-algorithm
//visualization: https://www.cs.usfca.edu/~galles/JavascriptVisual/Floyd.html

#include <iostream>
using namespace std;

const int S = 4;
const int infinity = 9999;
int working_matrix[S][S];
int graph[S][S] = { {0, 3, infinity, 5},
                   {2, 0, infinity, 4},
                   {infinity, 1, 0, infinity},
                   {infinity, infinity, 2, 0} };

void display(int which_one)
{
    if (which_one == 1)
    {
        for (int i = 0; i < S; i++)
        {
            cout << i << ".  ";
            for (int j = 0; j < S; j++)
            {
                if (graph[i][j] == infinity)
                    cout << infinity << "    ";
                else
                    cout << graph[i][j] << "       ";
            }
            cout << "\n";
        }
    }
    else if (which_one == 2)
    {
        for (int i = 0; i < S; i++)
        {
            cout << i << ".  ";
            for (int j = 0; j < S; j++)
            {
                if (working_matrix[i][j] == infinity)
                    cout << infinity << "    ";
                else
                    cout << working_matrix[i][j] << "       ";
            }
            cout << "\n";
        }
    }
}

void floyd_Warshall_Algo()
{
    //copy graph into working matrix for calculation.
    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
            working_matrix[i][j] = graph[i][j];

    //working starts:
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {   //the i j loops will be used to traverse the matrix.
            for (int k = 0; k < S; k++)
            {  
            //while this will check alternate routes by help of kth edge. To have best alternate/short 
            //route the process will be in iteration for S times.

            //new position value by help of kth vertix < old position value of graph.
            //if this condition is satisfied then new position value will be saved in working vertex.
                if (working_matrix[j][i] + working_matrix[i][k] < working_matrix[j][k])
                    working_matrix[j][k] = working_matrix[j][i] + working_matrix[i][k];
            }
        }
    }

}

void main() {
    // Write C++ code here
    cout << "==>FLOYD WARSHALL ALGORITHM:\n";
    cout << "\nGRAPH:\n";
    display(1);
    floyd_Warshall_Algo();
    cout << "\nRESULT:\n";
    display(2);
}
