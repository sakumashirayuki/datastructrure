#ifndef VECTOROUTPUT_H
#define VECTOROUTPUT_H
#include<iostream>
#include<vector>
using namespace std;

//һ��vector
template <typename T>
void printVector1D(const vector<T> &Vec)
{
	for (auto iter = Vec.begin(); iter != Vec.end(); ++iter)
	{
		cout << *iter<<" ";
	}
	cout << endl;
}

//����vector
template <typename T>
void printVector2D(const vector<vector<T>> &Vec)
{
	for (auto iter = Vec.begin(); iter != Vec.end(); ++iter)
	{
		printVector1D(*iter);
	}
}

#endif // !VECTOROUTPUT_H
