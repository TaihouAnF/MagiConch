#pragma once

// AStar.h
#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <algorithm>

class Astar {
public:
    Astar(const std::vector<std::vector<int>>& board) : board_(board) {}
    std::vector<std::pair<int, int>> FindPath(std::pair<int, int> start, std::pair<int, int> goal);

private:
    std::vector<std::vector<int>> board_;

    bool Is_valid(int x, int y);
    float Heuristic (int x1, int y1, int x2, int y2);
    std::vector<std::pair<int, int>> GetNeighbor(int x, int y);
};

struct Node {
    int x, y;
    float g_cost, h_cost;
    Node* parent;

    Node(int x, int y, float g_cost = 0, float h_cost = 0, Node* parent = nullptr)
        : x(x), y(y), g_cost(g_cost), h_cost(h_cost), parent(parent) {}
    
    inline float f_cost() const { return g_cost + h_cost; }
    inline bool operator>(const Node& other) const { return f_cost() > other.f_cost(); }
}

#endif // ASTAR_H