#include <iostream>
#include <vector>
	 


using namespace std;
char alphabets[52]={'A','B','C','D','E','F','G','H','I','J','K','L',
'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
,'q','r','s','t','u','v','w','x','y','z'};

char puncsAndDigits[]={
	'0','1','2','3','4','5','6','7','8','9', ':' , '?' , '!' , '@' ,'#' , '$' , '%' ,
	'^' , '&' , '*' , '(' , ')' , '[' , ']' , '{' , '}' , '>' , '<' , '~' , '+' , '-' , '_' ,
	 '=' , '.', ',' , '/' , '\"','\\',char(39),'|'}; /* 
	 				     ^
	 char 39 is the single quotation mark ( ' ), I used this to avoid escape sequence errors during iterations.*/


bool isAlphabet(char a){
	
	for(int i=0;i<52;i++){
		if(a==alphabets[i])return 1;
	}
	return 0;
}

bool isPuncOrDigit(char a){
    for(int i=0;i<40;i++){
        if(a==puncsAndDigits[i])return 1;
    }
    return 0;
}
string firstLetterUpperCase(string &s){

	if(s.length()>0){
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

