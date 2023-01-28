#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */


int flippingMatrix(vector<vector<int>> matrix) {
    //int rows = matrix.size();
    //int columns = matrix[0].size();
    int n = matrix.size()/2; //as this matrix is 2n x 2n.
    int largestSum = 0;
    
    // A B B A          A B C C B A
    // C D D C    [OR]  D F H H F D                 [So On...]
    // C D D C          E G I I G E
    // A B B A          E G I I G E
    //  2nx2n           D F H H F D
    // 2(2)x2(2)        A B C C B A
    //   4x4            2nx2n => 2(3)x2(3) => 6x6
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            largestSum += max(matrix[i][j], max(matrix[i][matrix.size()-j-1], max(matrix[matrix.size()-i-1][j], matrix[matrix.size()-i-1][matrix.size()-j-1])));
        }
    }
    return largestSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
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
