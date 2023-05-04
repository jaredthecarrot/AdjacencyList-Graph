#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

using std::cout, std:: cin, std::ifstream, std::ofstream, std::fstream, std::vector, std::queue;

void addEdge(vector<int> graph[], int o, int d){

    graph[o].push_back(d); // creates edge with origin and destination

    graph[d].push_back(o); // vice versa

}

void print(vector<int> graph[], int numV){
    for (int i = 0; i < numV; i++){ // iterate through the number of vertices

        cout << "Adjacent vertices of vertex " << i << " are: " << graph[i].size() << "\n";

        for (int j : graph[i]){ // within range of the number of vertices, iterate through the graph

            cout << "Edge between " << i << " and " << j << "\n";

        }

        cout << "\n";
    }

    cout << "\n";
}

void BFS(vector<int> graph[], int s, int vertices){

    queue<int> q;

    bool discovered[vertices];

    q.push(s);

    discovered[s] = true; 

    while (!q.empty()){

        int c = q.front();

        q.pop();

        cout << c << " ";

        for (int i : graph[c]){

            if (!discovered[i]){

                q.push(i);

                discovered[i] = true;

            }
        }
    }
}

int main(){

    int vertices, edges; // leaving out weight for now
    ifstream inFile;

    inFile.open("graph.txt");

    inFile >> vertices >> edges; // read in the number of vertices and edges

    vector<int> graph[vertices];

    for (int i = 0; i < edges; i++){

        int o, d, weights;

        inFile >> o >> d >> weights;

        addEdge(graph, o, d);
    }

    cout << "\nIn the order visited: \n\n";

    //print(graph, vertices); UNCOMMENT TO SEE ALL RELATIONS BETWEEN VERTICES

    BFS(graph, 0, vertices);

    inFile.close();

    return 0;
}