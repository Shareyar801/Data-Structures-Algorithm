#include <iostream>
#include <vector>
using namespace std;
class graph_adj_matrix
{
	int graph_matrix[5][5] = {0};
	int size = 5;

public:
	void add_edge_undirectional(int point_A, int point_B)
	{
		//for adding edge in graph.
		graph_matrix[point_A][point_B] = 1;
		graph_matrix[point_B][point_A] = 1;
	}
	void add_edge_directional(int point_A, int point_B)
	{
		//for adding edge in graph.
		graph_matrix[point_A][point_B] = 1;
	}
	void remove_edge_undirectional(int point_A, int point_B)
	{
		//for removing edge in graph.
		graph_matrix[point_A][point_B] = 0;
		graph_matrix[point_B][point_A] = 0;
	}
	void remove_edge_directional(int point_A, int point_B)
	{
		//for removing edge in graph.
		graph_matrix[point_A][point_B] = 0;
	}
	void display()
	{
		cout << "    0\t1\t2\t3\t4\n";
		for (int i = 0; i < size; i++)
		{
			cout << i << ".  ";
			for (int j = 0; j < size; j++)
			{
				cout << graph_matrix[i][j] << "\t";
			}
			cout << "END\n";
		}
	}
};
class graph_adj_list
{
public:
	int size = 5;
	vector<int> graph_list[5];
	void add_edge_undirectional(int point_A, int point_B)
	{
		//for adding edge in graph.
		graph_list[point_A].push_back(point_B);
		graph_list[point_B].push_back(point_A);
	}
	void add_edge_directional(int point_A, int point_B)
	{
		//for adding edge in graph.
		graph_list[point_A].push_back(point_B);
	}
	void remove_edge_undirectional(int point_A, int point_B)
	{
		//for removing edge in graph.
		for (int i = 0; i < graph_list[point_A].size(); i++)
		{
			if (graph_list[point_A][i] == point_B)
			{
				graph_list[point_A].erase(graph_list[point_A].begin() + i);
				break;
			}
		}
		for (int i = 0; i < graph_list[point_B].size(); i++)
		{
			if (graph_list[point_B][i] == point_A)
			{
				graph_list[point_B].erase(graph_list[point_B].begin() + i);
				break;
			}
		}
	}
	void remove_edge_directional(int point_A, int point_B)
	{
		//for removing edge in graph.
		for (int i = 0; i < graph_list[point_A].size(); i++)
		{
			if (graph_list[point_A][i] == i)
			{
				graph_list[point_A].erase(graph_list[point_A].begin() + i);
				break;
			}
		}
	}
	void display()
	{
		cout << "head";
		for (int i = 0; i < size; i++)
		{
			cout << "\n" << i << "->   ";

			for (auto j : graph_list[i])
			{
				cout << j << "-> ";
			}
		}
		cout << "\n";
	}
};
int main()
{
	int ch1, ch2, ch3, num; bool loop_end1 = 0, loop_end2 = 0;
	graph_adj_list ad_list; graph_adj_matrix ad_matrix;
	cout << "===GRAPH IMPLEMENTAION===\n";
	cout << "01.Adjacent Matrix.\n02.Adjacent List.\nChoice: ";
	cin >> ch1;
	switch (ch1)
	{
	case 01:
	{
		do
		{
			cout << "\n=>Adjacent Matrix (undirectional)";
			cout << "\nNOTE: LENGTH Of GRAPH IS 5.";
			cout << "\n01.Add edge\n02.remove edge\n03.Display\n04.Exit\nChoice: ";
			cin >> ch2;

			switch (ch2)
			{
			case 01:
				int PA, PB;
				cout << "\nEnter number of edges u want to enter: ";
				cin >> num;
				for (size_t i = 1; i <= num; i++)
				{
					cout << i << ".Point A: ";
					cin >> PA;
					cout << "  Point B: ";
					cin >> PB;
					ad_matrix.add_edge_undirectional(PA, PB);
				}
				break;
			case 02: 
				cout << "\nRemoving edge: ";
				cout << "\nPoint A: ";
				cin >> PA;
				cout << "Point B: ";
				cin >> PB;
				ad_matrix.remove_edge_undirectional(PA, PB);
				break;
			
			case 03:
				cout << "\ndisplaying graph:\n";
				ad_matrix.display();
				break;

			case 04:
				loop_end1 = 1;
				break;

			default:
				cout << "\nNote: Invalid choice try again.\n"; break;
			}
		} while (!loop_end1);
	}break;
	case 02: {
		do {
			cout << "\n=>Adjacent List (undirectional)";
			cout << "\nNOTE: LENGTH Of GRAPH IS 5.";
			cout << "\n01.Add edge\n02.remove edge\n03.Display\n04.Exit\nChoice: ";			cin >> ch3;
			switch (ch3) {
			case 01:
				int PA, PB;
				cout << "\nEnter number of edges u want to enter: ";
				cin >> num;
				for (size_t i = 1; i <= num; i++)
				{
					cout << i << ".Point A: ";
					cin >> PA;
					cout << "  Point B: ";
					cin >> PB;
					ad_list.add_edge_undirectional(PA, PB);
				}
				break;
			case 02:
				cout << "\nRemoving edge: ";
				cout << "\nPoint A: ";
				cin >> PA;
				cout << "Point B: ";
				cin >> PB;
				ad_list.remove_edge_undirectional(PA, PB);
				break;

			case 03:
				cout << "\ndisplaying graph:\n";
				ad_list.display();
				break;

			case 04:
				loop_end2 = 1;
				break;

			default:
				cout << "\nNote: Invalid choice try again.\n"; break;
			}
		} while (!loop_end2);
	}break;

	default: cout << "\nNote: Invalid choice try again.\n"; break;
	}
}
