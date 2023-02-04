#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) 
{
	// the data is sorted
	// sort(letters.begin(), letters.end()); 
	
	int leftBorder = 0;
	int rightBorder = letters.size() - 1;

	while (leftBorder < rightBorder)
	{
		int middel = (leftBorder + rightBorder) / 2;

		if (target >= letters[middel])
			leftBorder = middel + 1;

		else 
			rightBorder = middel ;
	
	}
	return target < letters[leftBorder] ? letters[leftBorder] : letters[0];
}

int main() 
{
	vector<char> letters = { 'c', 'f', 'f', 'j'};

	char res = nextGreatestLetter(letters, 'c');
	return 0;
}
