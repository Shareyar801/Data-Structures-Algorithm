#include <iostream>
using namespace std;

#define infinity 99999999;
const int V = 5, E = 5;

//using adjacent matrix for this matter.
//the edges length is being saved in matrix rather than keeping value of matrix 1 or 0.
//like traditional method.
int G[V][E] = { {0, 9, 75, 0, 0},
				{9, 0, 95, 19, 42},
				{75, 95, 0, 51, 66},
				{0, 19, 51, 0, 31},
				{0, 42, 66, 31, 0} };

int Prims_Algorithm()
{
	//it will keep tabs on how many edges have linked in solution graph.
	int no_edges_linked = 0;
	
	//creating a array for visited vertics and setting it false for time being.
	bool selected[V] = {false};

	//Step 1: of algorithm: Initialize the minimum spanning tree with a vertex chosen at random.
	//so selecting 0th position and setting it true.
	selected[0] = true;

	cout << "Printing Minimum Spanning Tree A/c to Prims Algorithm.\n";
	cout << "Edge  \t  Vertex \n";

	//this condition is making sure that all vertex are connected.
	//Step 2: Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree.
	//Step 3: Keep repeating step 2 until we get a minimum spanning tree
	while (no_edges_linked != (V - 1))
	{
		int min = infinity;
		//supposing that minimum distance for now is = to infinity.
		
		int row = 0, column = 0;

		for (size_t i = 0; i < V; i++)
		{
			if (selected[i])
			{
				for (size_t j = 0; j < V; j++)
				{
					if (!selected[j] && G[i][j])
					{
						if (min > G[i][j])
						{
							//if there is new minimum path to other vertex than min value will change.
							min = G[i][j];
							//the value of row & col will also be updated so the path can be displayed.
							row = i;
							column = j;
						}
					}
				}
			}
		}
		//simply printing prims method output.
		cout << row << " - " << column << "\t" << G[row][column] << "\n";
		selected[column] = true;
		no_edges_linked++;
	}

	return 0;
}

void display()
{
	cout << "Printing adjacent matrix.\n";
	cout << "    0\t1\t2\t3\t4\n";
	for (int i = 0; i < V; i++)
	{
		cout << i << ".  ";
		for (int j = 0; j < E; j++)
		{
			cout << G[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "END\n\n";
}


int main() 
{
	display();
	Prims_Algorithm();
}

