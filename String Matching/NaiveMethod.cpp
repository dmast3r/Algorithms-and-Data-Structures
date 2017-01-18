// This the naive method to find a pattern within a text. The time complexity of this algorithm is O(m * n)
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string text, pattern;
	cout<<"Enter text: ";
	cin>>text;
	cout<<"Enter pattern: ";
	cin>>pattern;
	size_t len_pattern = pattern.length(), len_text = text.length();
	cout<<"Searching for the pattern in the text............\n";
	for(size_t i = 0; i <= len_text - len_pattern; ++i)
	{
		size_t start = i, j = 0;
		for(;j < len_pattern; ++j)
		{
			if(text[start] != pattern[j])
				break;
			++start;
		}
		if(j == len_pattern)
		{
			cout<<"Match Found.....!\nMatch found at the index "<<i+1<<endl;
			return 0;
		}
	}
	cout<<"Entire text searched but no match found!"<<endl;
	return 0;
}