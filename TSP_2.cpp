// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{

	// store all vertices except start start vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// minimum path (initially assigned as max int value).
	int min_path = INT_MAX;


    int traversed_path[V+1];
    map<int, string> path_cost_map;
    string path_str="";


	do {
        stringstream ss;
        path_str="";
        cout<<"\n  Traversing for Cities ====>  "<<s+1;
        traversed_path[0] = s;
        ss << s+1;
        path_str += "--->"+ss.str();

        for (int i=0; i<vertex.size(); i++){
            traversed_path[i+1] = vertex[i];
            ss << traversed_path[i+1]+1;
            path_str += ss.str();
            cout<<" ---> "<<traversed_path[i+1]+1;
            if (i==vertex.size()-1) {
                traversed_path[i+2] = vertex[i+1];
                ss << traversed_path[i+2]+1;
                path_str = ss.str();
                cout<<" ---> "<<traversed_path[i+2]+1;
            }
        }

		// store current Path weight(cost)
		int current_pathweight = 0;
		// compute current path weight
		int k = s;

		for (int i = 0; i < vertex.size(); i++) {

			current_pathweight += graph[k][vertex[i]];
			cout<<"\n  Cost ("<<k+1<<" ---> "<<vertex[i]+1<<")  =  " <<graph[k][vertex[i]];
			k = vertex[i];

			if (i==vertex.size()-1) {
                current_pathweight += graph[k][s];
                cout<<"\n  Cost ("<<k+1<<" ---> "<<s+1<<")  =  " <<graph[k][s]<<endl;
			}
		}
		cout<<"  Total Cost for the path = "<<current_pathweight<<endl;
		// update minimum cost
		min_path = min(min_path, current_pathweight);

		path_cost_map.insert(pair<int, string>(current_pathweight, path_str));

	} while (
		next_permutation(vertex.begin(), vertex.end()));
		// keep on traversing for the permutations of the cities

    cout<<"\n\n  Minimum cost Path ====> "<<path_cost_map[min_path][0];
    for(int i=1; i<vertex.size()+2; i++) {
        cout<<" ---> "<<path_cost_map[min_path][i];
    }

	return min_path;
}

// Driver Code
int main()
{
	// matrix representation of graph
	int graph[][V] = { { 0, 10, 15, 20 },
                              { 5, 0, 9, 10 },
                              { 6, 14, 0, 12 },
                              { 8, 8, 20, 0 } };

	int start_vertex = 0;

	int Minimum_Cost = travllingSalesmanProblem(graph, start_vertex);
	cout << "\n\n  The Minimum_Cost for travelling all Cities  ------>  " <<Minimum_Cost << endl<<endl;
	return 0;
}