#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
    struct List {
        vector<int> list;
        int in_degree;

        void push(int value)
        {
            list.push_back(value);
        }
    };

    struct AdjList {
        AdjList(int size) : adj_list(size)
        {
        }

        vector<List> adj_list;

        void addAt(int value, size_t index)
        {
            adj_list[index].push(value);
            ++adj_list[value].in_degree;
        }
    };

    struct Graph {
        AdjList graph;
        stack<int, vector<int>> cur_sources;
        size_t non_source_num;

        Graph(int size, const vector<vector<int>>& prereqs)
            : graph(size), non_source_num(size)
        {
            for (const auto& pre : prereqs) {
                graph.addAt(pre[1], pre[0]);
            }

            int i = 0;
            for (const auto& l : graph.adj_list) {
                if (l.in_degree == 0) {
                    --non_source_num;
                    cur_sources.push(i);
                }
                ++i;
            }
        }

        int getSource()
        {
            if (cur_sources.empty()) {
                return -1;
            }

            if (non_source_num <= 0) {
                return -2;
            }

            int src = cur_sources.top();
            cur_sources.pop();
            return src;
        }

        void updateNeighbors(int idx)
        {
            const vector<int>& q = graph.adj_list[idx].list;
            for (int vertex : q) {
                --graph.adj_list[vertex].in_degree;
                if (!graph.adj_list[vertex].in_degree) {
                    --non_source_num;
                    cur_sources.push(vertex);
                }
            }
        }
    };

  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        Graph g(numCourses, prerequisites);

        while (!g.cur_sources.empty()) {
            int src = g.getSource();
            if (src < 0) {
                return src == -1 ? false : true;
            }

            g.updateNeighbors(src);
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pre{{1, 0}};
    cout << s.canFinish(2, pre) << endl;

    return 0;
}
