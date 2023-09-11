#include <iostream>
#include <vector>
using namespace std;

bool isAlphabet(char a){
	return isalpha(a); //isalpha is bool function to check if a char is an alphabet.
}

bool isPuncOrNum(char a){
	return ispunct(a)||isdigit(a); //ispunct/digit is a bool function to check if a char is a punctuation mark/digit.
}


string firstLetterUpperCase(string &s){

	if(s.length()>1){
	string sub=s.substr(1);
	char first = toupper(s[0]);
	s=first+sub;
	return s;
	}
	//example: "hello"--> sub = "ello" & first='h' , answer = first + sub;


	else{
		char x=toupper(s[0]);
		string letter="";
		letter+=x;
		return letter;
	}
	/*this else statement is when the desired string is a single character like "c",
		 then it just converts it to "C" without additional operations.*/
}

string getSubstring(int begin,int end,string x){
	string sub="";
	for(int i=begin;i<end;i++){
		sub+=x[i];
	}
	return sub;

	/*the reason I used a specific function for substring and not just use .substr is 
	just because .substr output unexpected results,so I did one myself.*/
}


void sentenceCase(){
	 
string Words;
getline(cin,Words);



vector<pair<int,char>> punctuationIndex;
pair<int,char> temporary;



for(int i=0;i<Words.length();i++){

	if(isPuncOrNum(Words[i])){

		temporary.first=i;

		temporary.second=Words[i];

		punctuationIndex.push_back(temporary);
	}

	
}



vector<string> seperateWords;
 //a vector that stores each word in the string seperately.

int temp=0; 
/* a variable to store the index of the last encountered letter 
so we can continue iterating and storing more words inside our vector.*/


for(int i=0;i<Words.length();i++){
	
		
	if(isAlphabet(Words[i])==false){
		
		
	seperateWords.push_back(getSubstring(temp,i,Words));
	
		temp=i+1;
		
	}
  }

seperateWords.push_back(getSubstring(temp,Words.length(),Words)); 
/*this is to add the last word to our vector because the 
iteration goes over it.*/
  
  
  string convertedString="";
  
  for(auto word:seperateWords){
  	firstLetterUpperCase(word);
  	convertedString+=(word+' ');
  }
  

for(auto element:punctuationIndex){
	convertedString[element.first]=element.second;
}

  cout<<convertedString<<endl;
  
}	 

int main() {
	 
	sentenceCase();
}
