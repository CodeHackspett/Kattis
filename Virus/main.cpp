#include <iostream>
#include <string>

using namespace std;

int main()
{
	string DNA_normal, DNA_virus; //declare strings

	cin >> DNA_normal >> DNA_virus; //input strings


	int start, end; // declare indexes
	int DNA_normal_len = DNA_normal.length(); //extract length of string DNA_normal
	int DNA_virus_len = DNA_virus.length();  // extract length of string DNA_virus
	int offset =  DNA_virus_len - DNA_normal_len; // diff between strings

//incrementally iterate from the beginning of the string to the end of the shortest string
	for(start=0; start < min(DNA_normal_len, DNA_virus_len); start++)
		if ( DNA_normal[start]!=DNA_virus[start] ) //break if the letters are different
			break;
//decrementally iterate from the end of DNA_virus string for the length of the shortest string
	for(end=DNA_virus_len-1; end>=max(0,offset); end--)  // the first element has subscript 0 (-1 to avoid off-by-one error)
		if ( DNA_normal[end-offset]!=DNA_virus[end] ) //break if the letters are different
			break;
// length of the smallest inserted sequence
	int min_len = max(end-start+1, max(0, offset));

	cout << min_len << endl;

	return 0;
}
