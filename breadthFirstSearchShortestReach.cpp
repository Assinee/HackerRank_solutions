#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    int i, weight = 6;
    int visited[n];
    int sv, ev;
    vector<int> distance(n); // Store the distances to all nodes from start node, including start node
    queue<int> q; q.push(s);
    
    for (i = 0; i < n; ++i) {
        visited[i] = distance[i] = 0;
    }
    
    while (!q.empty()) {
        int w = q.front(); q.pop();
        if (!visited[w-1]) visited[w-1] = 1;

        // Search for edges that connect current node
        for (i = 0; i < edges.size(); ++i) {
            sv = edges[i][0];
            ev = edges[i][1];
            // The distance to the other node from start node is the distance to the current node from start node  +  weight
            if (sv == w) {
                if (!visited[ev-1]) {
                    visited[ev-1] = 1;
                    q.push(ev);
                    distance[ev-1] += distance[sv-1] + weight;
                } 
            } else if (ev == w) {
                if (!visited[sv-1]) {
                    visited[sv-1] = 1;
                    q.push(sv);
                    distance[sv-1] += distance[ev-1] + weight;
                } 
            }
        }
    }

    // Delete the start node from distance table
    distance.erase(distance.begin() + (s - 1));
    
    // If the distance from start node to a node is 0, then there is no connection between the two.  
    for (int n = 0; n < distance.size(); ++n) {
        if (distance[n] == 0)
            distance[n] = -1;
    }
    
    return distance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
