class DSU
{
public:
    vector<int> parent;
    vector<int> sz;

    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (sz[pu] < sz[pv])
        {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        }
        else
        {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mail2idx;
        unordered_map<int, string> idx2name;
        unordered_map<int, string> idx2mail;

        int idx = 0;
        for (vector<string> &acc : accounts)
        {
            string name = acc[0];
            int n = acc.size();
            for (int i = 1; i < n; ++i)
            {
                string mail = acc[i];

                if (mail2idx.count(mail) == 0)
                {
                    mail2idx[mail] = idx;
                    idx2mail[idx] = mail;
                    idx2name[idx] = name;
                    idx++;
                }
            }
        }

        // debug(mail2idx);
        // debug(idx2name);
        // debug(idx2mail);

        DSU d(idx);
        unordered_map<int, set<string>> temp;

        for (vector<string> &acc : accounts)
        {

            int n = acc.size();
            for (int i = 1; i + 1 < n; ++i)
            {
                int mail1 = mail2idx[acc[i]];
                int mail2 = mail2idx[acc[i + 1]];

                d.Union(mail1, mail2);
            }
        }

        for (int i = 0; i < idx; ++i)
        {
            int p = d.findParent(i);
            string mail = idx2mail[i];

            temp[p].insert(mail);
        }

        // debug(temp);

        vector<vector<string>> ans;
        for (auto i : temp)
        {
            vector<string> t;
            t.push_back(idx2name[i.first]);
            for (auto mail : i.second)
            {
                t.push_back(mail);
            }
            ans.push_back(t);
        }

        return ans;
    }
};