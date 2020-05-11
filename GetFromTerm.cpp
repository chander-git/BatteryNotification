//============================================================================
// Name        : GetFrom Term.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================
#include "GetFromTerm.h"
void PrintVector(vector <string> const &a) {
	cout << "The vector elements are : "<<endl;;

	for(unsigned int i=0; i < a.size(); i++)
		cout << a.at(i);
}
vector<string> GetFromTerm(string cmd){
	vector<string>line;
	FILE *output;
	char temp[1024]={0};

	if(cmd=="")
	{
		cout<<"Please Enter CMD"<<endl;
		return line;
	}
	output = popen (cmd.c_str(), "r");
	if (!output){
		fprintf (stderr,"incorrect parameters or too many files.\n");
		return line;
	}

	while ( fgets(temp,sizeof(temp),output )){
		line.push_back(temp);
		memset(temp,0,sizeof(temp));
	}
	if (pclose (output) != 0)
	{
		fprintf (stderr,
				"Could not run more or other error.\n");
	}


	return line;
}





/*int main(int argc , char ** argv) {

  GetFromTerm("ps -ef");
  return EXIT_SUCCESS;
  }
  */
