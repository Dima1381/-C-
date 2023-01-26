#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calPoints(vector<string>& operations) 
{
	vector<int> temp;
	temp.reserve(operations.size());

	int len = operations.size();

	for (int i = 0; i < len; i++)
	{
		if (operations[i] == "C")
		{
			if (temp.size() != 0)
				temp.pop_back();
		}
		else if (operations[i] == "D")
		{
			if(temp.size() != 0)
			    temp.push_back(temp.back() * 2);
		}
		else if (operations[i] == "+")
		{
			if (temp.size() >= 2)
				temp.push_back(temp[temp.size() - 1] + temp[temp.size() - 2]);
		}
		else
		{
			temp.push_back(stoi(operations[i]));
		}
	}

	int sum = 0;
	int len_temp = temp.size();

	for (int i = 0; i < len_temp; i++)
	{
		sum += temp[i];
	}
	return sum;
}

int main()
{
	vector<string> ops = { "5","2","C","D","+" };

	int res = calPoints(ops);

	return 0;
}