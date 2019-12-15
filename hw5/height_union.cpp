#include<iostream>
#include<vector>
#include<string>

using namespace std;

void heightUnion(vector<int> &, vector<int> &, int, int);
int collapsingFind(vector<int> &, vector<int> &, int);
int findIdxOfNode(vector<int>, int);

int main(){
    int nOfTrees;
    vector<int> node;
    vector<int> heightOrParent;
    int n, h;
    int totalNOfNodes = 0;

    string command;

    
    cin >> nOfTrees;
    while(nOfTrees--){
        int nOfNodes;
        cin >> nOfNodes;
        totalNOfNodes += nOfNodes;
        while(nOfNodes--){
            cin >> n >> h;
            node.push_back(n);
            heightOrParent.push_back(h);
        }
    }
    
    int arg1, arg2;
    int opCount;
    while(1){
       cin >> command;
       if (command == "STOP")
           break;
       else if (command == "UNION"){
           cin >> arg1 >> arg2;
           heightUnion(node, heightOrParent, arg1, arg2);
       }
       else if (command == "FIND"){
           cin >> arg1;
           opCount = collapsingFind(node, heightOrParent, arg1);
           cout << opCount << endl;
       }
    }

    return 0;
}


void heightUnion(vector<int> &node, vector<int> &heightOrParent, int first, int second)
{
    int idx1, idx2;
    idx1 = findIdxOfNode(node, first);
    idx2 = findIdxOfNode(node, second);
    // compare the height
    if (heightOrParent[idx1]>heightOrParent[idx2]){
        // second is the parent of first
        heightOrParent[idx1] = second;
    }
    else{
        // first is the parent of second
        heightOrParent[idx2] = first;
    }
}


int collapsingFind(vector<int> &node, vector<int> &heightOrParent, int findingNode)
{
    int opCount = 0;
    int idx;
    idx = findIdxOfNode(node, findingNode);
    if (heightOrParent[idx]<0)  // findingNode is root of tree, no link traversed and link reset
        return 0;

    int tempP = idx;
    while(heightOrParent[tempP]>=0){
        opCount++;  // for link traversed
        tempP = findIdxOfNode(node, heightOrParent[tempP]);
    }
    heightOrParent[idx] = node[tempP];

    if (opCount <= 1)
        return opCount;
    else{   // link reset
        if (-heightOrParent[tempP]-1 == opCount)
            heightOrParent[tempP]++;
        opCount++;
    }

    return opCount;
}

int findIdxOfNode(vector<int> node, int findingNode)
{
    for (int i = 0; i<node.size(); i++){
        if (node[i] == findingNode)
            return i;
    }
    return -1;
}






