#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */
bool isMagic(vector<int>v){
    // for 3x3 magic number is equal to 15
    // checking value of raw 
    bool b=true;
    for(int i =0 ;i<3;++i){
        int a =0;
        for(int j=0;j<3;++j){
            a=a+v[3*i+j];
        }
        b=b&&(a==15);
    }
    // checking value of collum
    for(int i =0 ;i<3;++i){
        int a =0;
        for(int j=0;j<3;++j){
            a=a+v[3*j+i];
        }
        b=b&&(a==15);
    };
    b=b&&(v[0]+v[4]+v[8]==15);
    b=b&&(v[6]+v[4]+v[2]==15);
    return b;
}
int cost(vector<int>v,vector<int>w){
    int a =0;
    for(int i =0;i<v.size();++i){
        a=a+abs(v[i]-w[i]);
    }
    return a;
}
int formingMagicSquare(vector<vector<int>> s) {
    int mincost=INT_MAX;
    vector<int> flatten;
    for(int i=0;i<s.size();++i){
        for(int j=0;j<s[i].size();++j){
            flatten.push_back(s[i][j]);
        }
    };
    vector<int> p={1,2,3,4,5,6,7,8,9};
    while(next_permutation(p.begin(),p.end())){
        if(isMagic(p)){
            mincost=min(cost(flatten,p),mincost);
        }
    }
    return mincost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

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
