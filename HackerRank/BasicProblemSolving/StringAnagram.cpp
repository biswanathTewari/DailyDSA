#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'stringAnagram' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY dictionary
 *  2. STRING_ARRAY query
 */

bool Anagram(string a,string b){

    if(a.length() != b.length())
        return false;

    int fa[26];
    int fb[26];

    fill(fa,fa+26,0);
    fill(fb,fb+26,0);

    for(int i=0;i<a.length();i++)
        fa[a[i]-'a']++;

    for(int i=0;i<b.length();i++)
        fb[b[i]-'a']++;

    for(int i=0;i<26;i++)
        if(fb[i] != fa[i])
            return  false;


    return true;

}

vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {

    vector<int> result;

    for(auto i :query){
        int count = 0;
        for(auto j:dictionary){

          //cout<<i<<" "<<j<<endl;
          //cout<<Anagram(i,j)<<endl;

          ltrim(i);
          rtrim(i);
          ltrim(j);
          rtrim(j);


            if(Anagram(i,j) == true)
                count++;

        }
        //cout<<count<<endl;
        result.push_back(count);
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string dictionary_count_temp;
    getline(cin, dictionary_count_temp);

    int dictionary_count = stoi(ltrim(rtrim(dictionary_count_temp)));

    vector<string> dictionary(dictionary_count);

    for (int i = 0; i < dictionary_count; i++) {
        string dictionary_item;
        getline(cin, dictionary_item);

        dictionary[i] = dictionary_item;
    }

    string query_count_temp;
    getline(cin, query_count_temp);

    int query_count = stoi(ltrim(rtrim(query_count_temp)));

    vector<string> query(query_count);

    for (int i = 0; i < query_count; i++) {
        string query_item;
        getline(cin, query_item);

        query[i] = query_item;
    }

    vector<int> result = stringAnagram(dictionary, query);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
