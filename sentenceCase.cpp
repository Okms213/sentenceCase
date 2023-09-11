#include "sCasefunctions.h"

void sentenceCase(){
	 
string Words;
getline(cin,Words);



vector<pair<int,char>> punctuationIndex;
pair<int,char> temporary;



for(int i=0;i<Words.length();i++){

	if(isPuncOrDigit(Words[i])){

		temporary.first=i;

		temporary.second=Words[i];

		punctuationIndex.push_back(temporary);
	}

	
}



vector<string> seperateWords;
 //a vector that stores each word in the string seperately.

int temp=0; 
/* a var to store the index of the last encountered letter 
so we can continue iterating and storing more words inside our vector.*/


for(int i=0;i<Words.length();i++){
	
		
	if(isAlphabet(Words[i])==0){
		
		
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
