#pragma once
#include <fstream>
#include <cstdlib> 
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> 
#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <thread>
using namespace std;

void writeTo(const std::string& filepath, const  vector<char>& data)
{

	ofstream filestream("vektora.txt", ios::app);
	copy(data.begin(), data.end(), std::ostream_iterator<char>(filestream, ""));
	filestream << "\n";
	filestream.close();

}
void writeTo1(const std::string& filepath, const  vector<char>& data)
{

	ofstream filestream("vektora1.txt", ios::app);
	copy(data.begin(), data.end(), std::ostream_iterator<char>(filestream, ""));
	filestream << "\n";
	filestream.close();

}