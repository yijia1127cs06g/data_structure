#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;


vector<vector<string>> powerset(vector<string>::iterator start, vector<string>::iterator end){
    vector<vector<string>> psTemp;
    
    vector<vector<string>> ps;
    vector<string> temp;
    if (start == end){
        temp.emplace_back("");
        ps.emplace_back(temp);
    }
    else{
        psTemp = powerset(start+1, end);
        ps.reserve(psTemp.size()*2);
        ps.insert(ps.end(), psTemp.begin(), psTemp.end());
        ps.insert(ps.end(), psTemp.begin(), psTemp.end());
        for (int i=0; i<ps.size()/2; i++)
            ps[i].insert(ps[i].begin(), *start);
    }
    psTemp.clear();

    return ps;
}


int main(){
    string rawString;
    string element;
    vector<vector<string>> res;
    vector<string> set;
    while(getline(cin, rawString)){
        istringstream iss(rawString);
        set.clear();
        res.clear();
        while( getline(iss, element, ' '))
            set.emplace_back(element);
        res = powerset(set.begin(), set.end());
        for (int i =0; i<res.size(); i++){
            cout << "{";
            for (int j = 0; j<res[i].size(); j++){
                if (!res[i][j].empty()){
                    if(j>0)
                        cout << " " << res[i][j];
                    else
                        cout << res[i][j];
                }
            }
            cout << "} ";
        }
        cout << endl;
    }

}
