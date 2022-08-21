//video: https://www.youtube.com/watch?v=f8luGFRtshY&t=194s&ab_channel=GateSmashers
//website: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=lbp
//visualization: https://www.cs.usfca.edu/~galles/visualization/DFS.html
//done from adjacent list.

#include <map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

map<int, bool> visited;
map<int, list<int> > adj;

void addEdge(int from, int to)
{
	adj[from].push_back(to); // Add w to v’s list.
}

void DFS(int starting_point)
{
	// Mark the current node as visited and print it.
	visited[starting_point] = true;
	cout << starting_point << " ";

	//Recursive for all the vertices adjacent to this vertex.
	list<int>::iterator i;
	for (i = adj[starting_point].begin(); i != adj[starting_point].end(); ++i)
	{
		if (!visited[*i])
		{
			DFS(*i);
		}
	}
}

int main()
{
	addEdge(0, 1);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(1, 6);
	addEdge(1, 3);
	addEdge(2, 0);
	addEdge(3, 1);
	addEdge(4, 7);
	addEdge(5, 1);
	addEdge(6, 7);
	addEdge(7, 5);

	cout << "Following is Depth First Traversal" << " (starting from vertex 0) \n";
	DFS(0);

	return 0;
}
