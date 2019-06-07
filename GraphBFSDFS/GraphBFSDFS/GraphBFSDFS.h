#include "pch.h"
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>



struct Node {
	std::string m_name;
	std::unordered_set<std::string> m_children;

public:
	Node(std::string name = "") : m_name(name)
	{}
	

	bool isSuccessor(const Node& p) {
		
		return m_children.find(p.m_name) != m_children.end();
	}
	void addChild(Node p) {
		m_children.emplace(p.m_name);
	}

};


class Graph {
public:

	bool nodeExists(std::string name)
	{
		return nodes.find(name) != nodes.end();
	}

	void addVertex(std::string name)
	{
		nodes.emplace(name, Node(name));
	}

	void addChild(std::string vertex,std::string child);
	void BFS(std::string vertex);
	void DFS(std::string vertex);
	void Print();
private:
	

	std::unordered_map<std::string, Node> nodes;
};


/*
void Graph::addChild(std::string vertex, std::string child) {
	if (nodeExists(vertex) && nodeExists(child)) {
		nodes[vertex].addChild(nodes[child]);
	}

}
*/







