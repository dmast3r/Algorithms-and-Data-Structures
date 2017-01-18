#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define get_index(c) (int(tolower(c)-'a'))
using namespace std;
struct TrieNode
{
	vector<TrieNode *>children = vector<TrieNode *>(26,nullptr);
	bool isend;
};
TrieNode *get_node()
{
	TrieNode *new_node = new TrieNode;
	new_node->isend = false;
	return new_node;
}
void insert(TrieNode *root, const string &test)
{
	size_t size = test.length();
	TrieNode *crawl = root;
	for(size_t i = 0; i < size; ++i)
	{
		auto index = get_index(test[i]);
		if(!crawl->children[index])
			crawl->children[index] = get_node();
		crawl = crawl->children[index];
	}
	crawl->isend = true;
}
bool prefix_search(TrieNode *root, const string &sample)
{
	size_t size = sample.length();
	TrieNode *crawl = root;
	for(size_t i = 0; i < size; ++i)
	{
		auto index = get_index(sample[i]);
		if(!crawl->children[index])
			return false;
		crawl = crawl->children[index];
	}
	return true;
}
bool word_search(TrieNode *root, const string &sample)
{
	size_t size = sample.length();
	TrieNode *crawl = root;
	for(size_t i = 0; i < size; ++i)
	{
		auto index = get_index(sample[i]);
		if(!crawl->children[index])
			return false;
		crawl = crawl->children[index];
	}
	return crawl->isend;
}
string output(bool test)
{
	if(test)
		return "is present in the Dictionary";
	return "is not present in the Dictionary";
}
int main()
{
	vector<string>string_list;
	string temp;
	unsigned long long int i;
	cout<<"Enter number of strings to be entered: ";
    cin>>i;
    cout<<"Enter strings: ";
    while(i--)
    {
        cin>>temp;
        string_list.push_back(temp);
    }
	TrieNode *root = get_node();
	for(auto i = string_list.begin(); i != string_list.end(); ++i)
		insert(root,*i);
    cout<<"Enter string to be searched: ";
    cin>>temp;
	cout<<"String "+temp+" "<<output(word_search(root,temp));
}
