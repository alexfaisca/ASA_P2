#include <iostream>
#include <vector>

using namespace std;

int mark_parent_nodes(vector< vector<int> > *graph_transpose, vector<int> *node_markings, int node, int mark, int max_mark, int new_edges){
    // Avoid loops
    if(new_edges < 0) return -1;

    if((*node_markings)[node - 1] == mark)
        (*node_markings)[node - 1] = max_mark;
    for(int parent : (*graph_transpose)[node-1]){
        if(mark_parent_nodes(graph_transpose, node_markings, parent, mark, max_mark, new_edges - 1) == -1)
            return -1;
    }
    return 0;
}


bool is_cyclic_aux(vector<vector<int>> *graph_transpose, int v, bool visited[], bool stack[])
{
    if(visited[v-1] == false) {
        visited[v-1] = true;
        stack[v-1] = true;
        for(int parent : (*graph_transpose)[v-1]) {
            if ( !visited[parent-1] && is_cyclic_aux(graph_transpose, parent, visited, stack))
                return true;
            else if (stack[parent-1])
                return true;
        }
    }
    stack[v-1] = false;
    return false;
}


bool check_for_cycles(vector<vector<int>> *graph_transpose, int v)
{
    bool *visited = new bool[v];
    bool *stack = new bool[v];

    for(int i = 0; i < v; i++) {
        visited[i] = false;
        stack[i] = false;
    }

    for(int i = 1; i <= v; i++)
        if (is_cyclic_aux(graph_transpose, i, visited, stack))
            return true;
    return false;
}

int main() {
    int target1, target2, vertices, expected_edges, edges, v1, v2;
    scanf("%d %d", &target1, &target2);
    scanf("%d %d", &vertices, &expected_edges);
    vector< vector<int> > graph_transpose(vertices);
    vector<int> node_markings(vertices,0);
    bool output = false, valid_graph = true;

    for(edges = 0; scanf("%d %d", &v1, &v2) != EOF;) {
        graph_transpose[v2-1].push_back(v1);
        edges++;
        if(graph_transpose[v2-1].size() > 2 || edges > expected_edges) {
            valid_graph = false;
            break;
        }
    }
    if(edges < expected_edges) valid_graph = false;
    if(valid_graph)
        valid_graph = !check_for_cycles(&graph_transpose, vertices);

    if(!valid_graph || mark_parent_nodes(&graph_transpose, &node_markings, target1, 0, 1, expected_edges) == -1 ||
       mark_parent_nodes(&graph_transpose, &node_markings, target2, 1, 2, expected_edges) == -1) {
        cout << "0" << endl;
        return 0;
    }

    for(int i = 0; i < vertices; i++)
        if(node_markings[i] == 2)
            for(int parent : graph_transpose[i])
                mark_parent_nodes(&graph_transpose, &node_markings, parent, 2, 1, expected_edges);

    for(int i = 0; i < vertices; i++) {
        if(node_markings[i] == 2) {
            cout << i+1 << " ";
            output = true;
        }
    }

    if(!output) cout << "-";
    cout << endl;
    return 0;
}