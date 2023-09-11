#include <iostream>
#include <string>

#include <vector>
#include <map>		 


using namespace std;
char alphabets[52]={'A','B','C','D','E','F','G','H','I','J','K','L',
'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
,'q','r','s','t','u','v','w','x','y','z'};

char puncsAndNumbers[]={
	'0','1','2','3','4','5','6','7','8','9', ':' , '?' , '!' , '@' ,'#' , '$' , '%' ,
	'^' , '&' , '*' , '(' , ')' , '[' , ']' , '{' , '}' , '>' , '<' , '~' , '+' , '-' , '_' ,
	 '=' , '.', ',' , '/' , '\"','\\',char(39)}; /* 
	 									 ^
	 char 39 is the single quotation mark ( ' ), I used this to avoid escape sequence errors during iterations.*/


bool isAlphabet(char a){
	
	for(int i=0;i<52;i++){
		if(a==alphabets[i])return 1;
	}
	return 0;
}

bool isPuncOrNum(char a){
    for(int i=0;i<39;i++){
        if(a==puncsAndNumbers[i])return 1;
    }
    return 0;
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