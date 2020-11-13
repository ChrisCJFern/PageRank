#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

class AdjacencyList { // Most if this is from Stepik Graphs section!! 
private:
    map<int, vector<pair<double, double>>> graph;
    
public:
    void insertEdge(int from, int to, int weight); // FIXME: Change data types
    bool isEdge(int from, int to);
    int getWeight(int from, int to);
    vector<int> getAdjacent(int vertex);
    void printGraph();
    void PageRank(int n);
};
void AdjacencyList::PageRank(int n) { 
    // prints the PageRank of all pages after p powerIterations in ascending alphabetical order 
    // of webpagesand rounding rank to two decimal places This class and method are optional. 
    // To accept the input, you can use this method:

} 
void AdjacencyList::insertEdge(int from, int to, int weight) { // from lecture
    graph[from].push_back(make_pair(to, weight));
    if (graph.find(to) == graph.end())
        graph[to] = {};
}
bool AdjacencyList::isEdge(int from, int to) {
    if (graph.find(from) == graph.end() || graph.find(to) == graph.end()) // Check if vertices exist
        return false;
    for (int i = 0; i < graph[from].size(); i++) {
        if (graph[from].at(i).first == to)
            return true;
    }
    return false;
}
int AdjacencyList::getWeight(int from, int to) {
    if (graph.find(from) == graph.end() || graph.find(to) == graph.end()) // Check if vertices exist
        return 0;
    for (int i = 0; i < graph[from].size(); i++) {
        if (graph[from].at(i).first == to)
            return graph[from].at(i).second;
    }
    return 0;
}
vector<int> AdjacencyList::getAdjacent(int vertex) {
    vector<int> adjacents = {};
    if (graph.find(vertex) == graph.end()) // does vertex exist?
        return adjacents;
    for (int i = 0; i < graph[vertex].size(); i++) {
        adjacents.push_back(graph[vertex].at(i).first);
    }
    return adjacents;
}
void AdjacencyList::printGraph() {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        cout << it->first;
        if (it->second.size() != 0)
            cout << " ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second.at(i).first;
            if (i != it->second.size() - 1) // get rid of whitespace at end
                cout << " ";

        }
        cout << endl;
    }
}

int main()
{
    int no_of_lines, power_iterations;
    std::string from, to;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    for (int i = 0; i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        // Do Something
    }
    //Create a graph object
    //Created_Graph.PageRank(power_iterations);
}