#include<iostream>
#include"global.h"
#include<string>
#include<vector>
using namespace std;

class Parser
{
public:
	static string GetName(string sourceLine);
	static vector<int> GetRate(string sourceLine);
};