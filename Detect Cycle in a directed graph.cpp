bool isCyclicUtil(int u, bool visited[], bool rec_stack[], list<int> *adj) {
    // mark the current node as visited
    // as well as put it in the recursion stack
    visited[u] = true;
    rec_stack[u] = true;

    // explore all the adjacent nodes of the current node
    for(auto v : adj[u]) {
        // if an adjacent node is unvisited, visit it and return true if a cycle is found from it or it's descendants
        if(!visited[v]) {
            if(isCyclicUtil(v, visited, rec_stack, adj))
                return true;
        }

        // if the node is already visited
        // and also in the recursion stack
        // then return true because a cycle exist in the graph
        else if(rec_stack[v])
            return true;
    }

    // remove u from the recursion stack as all of it's descendants have been explored
    rec_stack[u] = false;
    // if all descendants explored and no cycle found then return false
    // as no cycle exist atleast from this node and all of it's descendants
    return false;
}

// A utility function that returns true if there is a cycle in a graph
bool Graph :: isCyclic() {
    // initially mark all the nodes as un-visited and not in the recursion stack
    bool visited[V] = {false}, rec_stack[] = {false};

    for(int i = 0; i < V; ++i) {
        // apply DFS from an unvisited node
        if(!visited[i]) {
            // if cycle is found here, no need to continue further
            if(isCyclicUtil(i, visited, rec_stack, adj))
                return true;
        }
    }

    return false;
}
