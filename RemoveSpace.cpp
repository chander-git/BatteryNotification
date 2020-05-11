#include<bits/stdc++.h>
using namespace std;
string RemoveSpaces(char *str)
{
	// To keep track of non-space character count
	int count = 0;
	if(str==NULL)
	{
		cout<<"ERROR::Null point received"<<endl;
		return NULL;
	}
	// Traverse the given string. If current character
	// is not space, then place it at index 'count++'
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i]; // here count is
	// incremented
	str[count] = '\0';
//	cout<<__func__<<str<<endl;
	return str;

}
