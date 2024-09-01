class DSU 
{
    public:
    vector<int> parent;
    vector<int> rank;
    int n;

    DSU(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)  parent[i] = i;
    }

    // find the parent node
    int findParent(int i)
    {
        if(i==parent[i]) return i;
        return parent[i] = findParent(parent[i]);
    }

    // check if two nodes are connected
    bool isConnected(int i,int j)
    {
        return findParent(i) == findParent(j);
    }

    // unite two components
    bool unite(int i,int j)
    {
        i = findParent(i);
        j = findParent(j);

        if(i==j) return false;

        if(rank[i]>rank[j])
        {
            parent[j] = i;
            rank[i] += rank[j];
        }
        else
        {
            parent[i] = j;
            rank[j] += rank[i];
        }
        return true;
    }

    // return number of distinct components
    int countComponents()
    {
        int count = 0;
        for(int i=0;i<n;i++) count += (parent[i]==i);
        return count;
    }

    //returns size of components
    int sizeOf(int i)
    {
        return rank[findParent(i)];
    }
};
