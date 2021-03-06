#include "pch.h"
#include "GraphBFSDFS.h"
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>



void Graph::addChild(std::string vertex, std::string child) {
	if (nodeExists(vertex) && nodeExists(child)) {
		nodes[vertex].addChild(nodes[child]);
	}

}

void Graph::Print() {
	for (auto it = nodes.begin();it != nodes.end();++it) {
		std::cout << "Node :" << it->first << " has children :" << std::endl;
		for (auto childIt = it->second.m_children.begin();childIt != it->second.m_children.end();++childIt) {
			std::cout << *childIt << " ";
		}
		std::cout << std::endl;
	}
}


void Graph::BFS(std::string vertex) {

	std::queue<std::string> forwardQueue;
	std::unordered_set<std::string> visited;
	forwardQueue.push(vertex);
	while (!forwardQueue.empty()) {
		std::string currentNode = forwardQueue.front();
		forwardQueue.pop();
		visited.emplace(currentNode);
		for (auto it = nodes[currentNode].m_children.begin();it != nodes[currentNode].m_children.end();++it) {
			std::string child = *it;
			if (visited.find(child) == visited.end()) {
				forwardQueue.push(child);
			}

		}
		std::cout << currentNode << " ";
	}
}



void Graph::DFS(std::string vertex) {
	std::stack<std::string> forwardStack;
	std::unordered_set<std::string> visited;
	forwardStack.push(vertex);
	while (!forwardStack.empty()) {
		std::string currentNode = forwardStack.top();
		forwardStack.pop();
		for (auto it = nodes[currentNode].m_children.begin();it != nodes[currentNode].m_children.end();++it) {
			std::string child = *it;
			if (visited.find(child) == visited.end()) {
				forwardStack.push(child);
			}
		}
		visited.emplace(currentNode);
		std::cout << currentNode << " ";
	}
}




