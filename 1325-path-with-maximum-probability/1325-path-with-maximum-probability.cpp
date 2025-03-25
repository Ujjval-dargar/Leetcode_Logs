class Solution {
public:
    double minFailureProb(vector<vector<pair<int, double>>>& adjlist, int s,
                          int t) {
        int n = adjlist.size();
        
        vector<double> distance(n, 1.0); // failure probabilities

        // Min-priority queue based on failure probability.
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>>
            q;

        distance[s] = 0.0;
        q.push({0.0, s}); // Push starting node

        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            double w = p.first;
            int u = p.second;

            for (auto edge : adjlist[u]) {
                int v = edge.first;
                double w_ = edge.second;

                double cand = 1 - (1 - w) * (1 - w_);
                if (cand < distance[v]) {
                    distance[v] = cand;
                    q.push({cand, v});
                }
            }
        }
        return distance[t];
    }

    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        int e = edges.size();
        vector<vector<pair<int, double>>> adjlist(n);
        for (int i = 0; i < e; ++i) {
            double failure = 1.0 - succProb[i];
            int u = edges[i][0], v = edges[i][1];
            adjlist[u].push_back({v, failure});
            adjlist[v].push_back({u, failure});
        }

        return 1.0 - minFailureProb(adjlist, start_node, end_node);
    }
};
