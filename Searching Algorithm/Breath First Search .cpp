//source code: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/?ref=lbp
//video explanation: https://www.youtube.com/watch?v=qul0f79gxGs&t=184s&ab_channel=GateSmashers
//the bfs is also referred as level order search.

#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int V = 6;
vector<list<int>> adj;

void addEdge(int from, int to)
{
	adj[from].push_back(to); 
}

void BFS(int current_value)
{
	// vector for visited vertex.
	vector<bool> visited;
	visited.resize(V, false);

	//Create a queue for BFS. It will hold sequence of search algorithm.
	list<int> queue;

	//marking first vertex true as it is being visited in next line.
	visited[current_value] = true;
	queue.push_back(current_value);
	//saving 1st vertex in queue.

	while (!queue.empty()) //will run till all nodes visited.
	{
		//Dequeue a vertex from queue and print it
		current_value = queue.front();
		cout << current_value << " ";
		queue.pop_front();

		//Get all adjacent vertices of the dequeued
		//vertex s. If a adjacent has not been visited,
		//then mark it visited and enqueue it
		for (auto adjecent : adj[current_value]) 
		{	
			//will check all points in graph and check which one is connected to current one.
			//if it is connect to current one and not visited yet then in that case we will mark it true.
			//And push that vertex to node to queue.
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
	// Create a graph given in the above diagram
	//Graph g(4);
	adj.resize(V);
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(2, 0);
	addEdge(2, 3);
	addEdge(3, 3);
	addEdge(0, 4);
	addEdge(3, 5);
	addEdge(1, 5);

	cout << "Following is Breadth First Traversal " << "(starting from vertex 0) \n";
	BFS(0);

	return 0;
}
