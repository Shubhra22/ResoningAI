//
//  main.cpp
//  ResoningAI
//
//  Created by Shuvro Sarker on 11/1/15.
//  Copyright (c) 2015 Shuvro Sarker. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

vector<string> rulesVector[5];
queue<string> treeVector;
map<int,string> mapLine;
string s;
static int indexOfs;

string doNeg(string s)
{
    if(s[0] == '!')
    {
        s = s[1];
        return s;
    }
    else return "!"+s;
}
bool exists(string s)

{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < rulesVector[i].size() ; j++)
        {
            //cout<<vs[i]<<"*";
            if(rulesVector[i][j] == s)
            {
                indexOfs = i;
                return true;
            }
        }
    }
    return false;
}


void pushWithout(string s, vector<string> v)
{
    for (int j = 0; j < v.size(); j++)
    {
        if (v[j] != s)
        {
            treeVector.push(v[j]);
        }
        
    }
}
void doCalc()
{
    s = treeVector.front();
    string s1 = treeVector.back();
    cout<<s<<" ";
    s= doNeg(s);
    if(treeVector.empty()) return;

    if (!exists(s))
    {
        treeVector.pop();
        //return;
    }
    else
    {
        pushWithout(s, rulesVector[indexOfs]);
        treeVector.pop();
        cout<<mapLine[indexOfs]<<endl;
    }
    
    doCalc();
}
int main(int argc, const char * argv[])
{
    
    ifstream file("in.txt");
    string line;
    int i =0;
    while (getline(file, line))
    {
        stringstream lineStrm(line);
        string data;
        while(getline(lineStrm, data, '/'))
        {
            
            rulesVector[i].push_back(data);
        }
        mapLine[i] = line;
        i++;
    }
    treeVector.push("!R");
     
    doCalc();
    if(treeVector.empty())
    {
        cout<<"Correct Logic"<<endl;
    }
    else
        cout<<"Vul"<<endl;
    return 0;
}
