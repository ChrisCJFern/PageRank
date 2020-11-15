#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

class AdjacencyList { // Most if this is from Stepik Graphs section!! 
private:
    map<string, int> index; // key: website name, value: index 
    map<int, vector<string>> graph;
    int j = 0; // index counter
    
public:
    void insertEdge(string from, string to);
    bool isEdge(string from, string to);
    int getOutDegree(string from);
    vector<string> getAdjacent(string vertex);
    void printGraph();
    void PageRank(int n);
};
void AdjacencyList::PageRank(int n) { 
    // prints the PageRank of all pages after p powerIterations in ascending alphabetical order 
    // of webpages and rounding rank to two decimal places. This class and method are optional. 
    if (j != 0) {
        vector<double> rVec(j, 1.0 / j);
        vector<double> real(j, 0.0);
        for (auto it = index.begin(); it != index.end(); it++) {
            double sum = 0;
            cout << it->first << " ";
            //cout << getOutDegree(it->first);
            if (graph[it->second].size() != 0)
                cout << " ";
            for (int i = 0; i < graph[it->second].size(); i++) {
                sum += rVec.at(index[graph[it->second].at(i)]) * (1.0 / getOutDegree(graph[it->second].at(i)));
                //cout << rVec.at(index[graph[it->second].at(i)]) << " " << (1.0 / getOutDegree(graph[it->second].at(i))) << endl;
                //cout << sum << endl;
                //cout << graph[it->second].at(i);
                if (i != graph[it->second].size() - 1) // get rid of whitespace at end
                    cout << " ";
            }
            real.at(it->second) = sum;
            cout << sum;
            cout << endl;
        }
    }
}

void AdjacencyList::insertEdge(string from, string to) { // from lecture
    if (index.find(from) == index.end())
        index[from] = j++;
    if (index.find(to) == index.end())
        index[to] = j++;
    graph[index[from]].push_back(to);
    if (graph.find(index[to]) == graph.end())
        graph[index[to]] = {};
}

bool AdjacencyList::isEdge(string from, string to) {
    if (graph.find(index[from]) == graph.end() || graph.find(index[to]) == graph.end()) // Check if vertices exist
        return false;
    for (int i = 0; i < graph[index[from]].size(); i++) {
        if (graph[index[from]].at(i) == to)
            return true;
    }
    return false;
}
int AdjacencyList::getOutDegree(string from) {
    if (graph.find(index[from]) == graph.end()) // Check if vertices exist
        return 0;
    else
        return graph[index[from]].size();
    return 0;
}
vector<string> AdjacencyList::getAdjacent(string vertex) {
    vector<string> adjacents = {};
    if (graph.find(index[vertex]) == graph.end()) // does vertex exist?
        return adjacents;
    for (int i = 0; i < graph[index[vertex]].size(); i++) {
        adjacents.push_back(graph[index[vertex]].at(i));
    }
    return adjacents;
}
void AdjacencyList::printGraph() {
    for (auto it = index.begin(); it != index.end(); it++) {
        cout << it->first << " ";
        cout << getOutDegree(it->first);
        if (graph[it->second].size() != 0)
            cout << " ";
        for (int i = 0; i < graph[it->second].size(); i++) {
            cout << graph[it->second].at(i);
            if (i != graph[it->second].size() - 1) // get rid of whitespace at end
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int no_of_lines, power_iterations;
    std::string from, to;
    AdjacencyList pageRank;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    for (int i = 0; i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        pageRank.insertEdge(from, to);
        // Do Something
    }
    cout << endl;
    pageRank.printGraph();
    //pageRank.PageRank(4);

    //Create a graph object
    //Created_Graph.PageRank(power_iterations);
}