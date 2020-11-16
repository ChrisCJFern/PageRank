#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

class AdjacencyList { // Most if this is from Stepik Graphs section!! 
private:
	map<string, int> index; // key: website name, value: index 
	unordered_map<int, vector<string>> graph;
	int j = 0; // index counter

public:
	void insertEdge(string from, string to);
	vector<int> getOutDegreeVec();
	//void printGraph(); FOR DEBUGGING
	void PageRank(int n);
};
void AdjacencyList::PageRank(int n) {
	// prints the PageRank of all pages after p powerIterations in ascending alphabetical order 
	// of webpages and rounding rank to two decimal places. This class and method are optional. 

	// Note that there will always be at least 1 vertex and 1 power iteration!
	vector<int> outDegree = getOutDegreeVec();
	vector<double> rVec(j, 1.0 / j);
	vector<double> rankVec(j, 0.0); // FIXME : Make n == 0
	if (n == 1) {
		for (auto it = index.begin(); it != index.end(); it++) {
			cout << it->first << " ";
			cout << fixed << showpoint;
			cout << setprecision(2);
			cout << (1.0 / j) << endl;
		}
	}
	else {
		for (int j = 1; j < n; j++) {
			if (j != 1)
				rVec = rankVec;
			for (auto it = index.begin(); it != index.end(); it++) {
				double sum = 0;
				if (j == n - 1)
					cout << it->first << " ";
				for (int i = 0; i < graph[it->second].size(); i++) {
					sum += (rVec.at(index[graph[it->second].at(i)]) * (1.0 / outDegree.at(index[graph[it->second].at(i)])));
					double one = rVec.at(index[graph[it->second].at(i)]);
					double two = (1.0 / outDegree.at(index[graph[it->second].at(i)]));
				}
				rankVec.at(it->second) = sum;
				if (j == n - 1) {
					cout << fixed << showpoint;
					cout << setprecision(2);
					cout << sum << endl;
				}
			}
		}
	}
}

void AdjacencyList::insertEdge(string from, string to) { // from lecture
	if (index.find(from) == index.end())
		index[from] = j++;
	if (index.find(to) == index.end())
		index[to] = j++;
	graph[index[to]].push_back(from);
	if (graph.find(index[from]) == graph.end())
		graph[index[from]] = {};
}


vector<int> AdjacencyList::getOutDegreeVec() {
	vector<int> outDegree(j, 0);
	for (auto it = index.begin(); it != index.end(); it++) {
		for (int i = 0; i < graph[it->second].size(); i++) {
			outDegree.at(index[graph[it->second].at(i)])++;
		}
	}
	return outDegree;
}

/* FOR DEBUGGING! 
void AdjacencyList::printGraph() {
	for (auto it = index.begin(); it != index.end(); it++) {
		cout << it->first << " ";
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
*/

int main()
{
	//while (true) { // For testing! :)
	int no_of_lines, power_iterations;
	std::string from, to;
	AdjacencyList webGraph;
	std::cin >> no_of_lines;
	std::cin >> power_iterations;
	for (int i = 0; i < no_of_lines; i++) {
		std::cin >> from;
		std::cin >> to;
		webGraph.insertEdge(from, to);
	}
	webGraph.PageRank(power_iterations);
	//}
}