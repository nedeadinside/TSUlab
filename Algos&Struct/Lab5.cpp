#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <fstream>


using namespace std;

struct Point {
    double x, y;
};

struct Edge {
    int u, v;
    double weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

vector<int> parent;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& cluster) {
    visited[v] = true;
    cluster.push_back(v);
    for (int u = 0; u < adj[v].size(); ++u) {
        if (adj[v][u] && !visited[u]) {
            dfs(u, adj, visited, cluster);
        }
    }
}

bool is_point_in_cluster(const vector<Point>& points, const vector<int>& cluster, Point& p) {
    for (int v : cluster) {
        if (points[v].x == p.x && points[v].y == p.y) {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N = 50;
    int K = 5;

    srand(6666);

    vector<Point> points(N);
    for (Point& p : points) {
        p.x = rand() % 100 + 1;
        p.y = rand() % 100 + 1;
    }

    vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            edges.push_back({i, j, distance(points[i], points[j])});
        }
    }
    
    sort(edges.begin(), edges.end());
    parent.resize(N);
    for (int i = 0; i < N; ++i)
        parent[i] = i;


    vector<Edge> mst;
    for (Edge& e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            mst.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    vector<vector<int>> adj(N, vector<int>(N, 0));
    for (int i = 0; i < N - K; ++i) {
        adj[mst[i].u][mst[i].v] = 1;
        adj[mst[i].v][mst[i].u] = 1;
    }

    vector<vector<int>> clusters;
    vector<bool> visited(N, false);

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            vector<int> cluster;
            dfs(i, adj, visited, cluster);
            clusters.push_back(cluster);
        }
    }

    for (const vector<int>& cluster : clusters) {
        double minX = 1e9, minY = 1e9, maxX = -1e9, maxY = -1e9, sumX = 0, sumY = 0;
        for (int v : cluster) {
            minX = min(minX, points[v].x);
            minY = min(minY, points[v].y);
            maxX = max(maxX, points[v].x);
            maxY = max(maxY, points[v].y);
        }

        double x_centered = (minX + maxX) / 2;
        double y_centered = (minY + maxY) / 2;

        double min_dist = 1e9;
        Point ClosestPoint;

        for(Point p : points) {
            double dist = distance(p, {x_centered, y_centered});
            if ((dist < min_dist) && (is_point_in_cluster(points, cluster, p))) {
                min_dist = dist;
                ClosestPoint = p;
            }
        }   

        cout << "Количество вершин: " << cluster.size() << "\n";
        cout << "Минимальные координаты: (" << minX << ", " << minY << ")\n";
        cout << "Максимальные координаты: (" << maxX << ", " << maxY << ")\n";
        cout << "Центроид: (" << ClosestPoint.x << ", " << ClosestPoint.y << ")\n";
    }
    return 0;
}