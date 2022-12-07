#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORD_LENGHT 50
#define MAX_WORDS 10
#define COD_LENGHT 26

//Define variable number anagrams

int angr = 0;

//define functions

char codify(char arr[WORD_LENGHT+1],int i);
char compare(char arr[WORD_LENGHT+1]);
void read_search();
void read();
void process();

char words[MAX_WORDS][WORD_LENGHT];
int codified_words[MAX_WORDS][COD_LENGHT]={{}};

//Read and store serach words into words array with a maximum of 10 words.

void read_search(){
	
	char letter;
	
	int i=0,j=0;
	
	
	printf("Anagrames a buscar: \n");
	scanf("%c",&letter);
		
	while(letter!='.' and i<MAX_WORDS and j<WORD_LENGHT){ //store each letter in the correspondig array postion
		if(isalpha(letter)){
			words[i+1][j]=letter;
			j++;
		}else if(!isalpha(letter)){
			words[i+1][j+1]='\0';
			if(isalpha(words[i+1][0])){ //if the previous string is not empty use next row(used to ignore non letter chars)
				i++;
			}
			j=0; //reset array pos
		}			
		scanf("%c",&letter);
	}
}

//Read and store one word from the given text.

void read(){

	char letter_text;

	int j=0;
	
	scanf("%c",&letter_text);
	
	while(letter_text!='.' and j<WORD_LENGHT){
		if(isalpha(letter_text)){
			words[10][j]=letter_text;
			j++;
		}else if(!isalpha(letter_text)){
			words[10][j+1]='\0';
			j=0;
			
			if(isalpha(words[10][0])){	//when the next char is not a letter means the word has ended so 
				compare(words[10]);		//it calls the function compare to process it
			}
			
		}	
		scanf("%c",&letter_text);
	
	}
	if(isalpha(words[10][0])){ //used if the last word is the anagram of the search one.
		compare(words[10]);
	}
}

//codify given character array into an integer string stored in codified_words.

char codify(char arr[WORD_LENGHT+1],int i){

	int pos = 0;
	
	//EMPTY LIST
	
	memset(codified_words[i],0,sizeof(codified_words[i]));
	
	for(int j=0;j<COD_LENGHT;j++){
		pos = 'z'-tolower(arr[j]);
		codified_words[i][pos]++;
	}
		
	return 1;
}

//function to compare each word of the text

char compare(char arr[WORD_LENGHT+1]){

	codify(arr,10);

	int c=0;
	
	int i=0,j=0;

	for(i=0;i<MAX_WORDS;i++){
		
		for(j=0;j<COD_LENGHT;j++){
        	if(codified_words[i][j]==codified_words[10][j]){
				c++;
			}
		}
		if(c==j){
			printf("Anagrama de la paraula \"%s\" trobat: \"%s\".\n",words[i],arr);
			angr++;
		}
		c=0;	
	}
	
	memset(words[10],0,sizeof(words[10])); //reset word
	
	return 1;
}

//
void process(){

	read_search();
	
	for(int i=0;i<MAX_WORDS;i++){
		codify(words[i],i);
	}
	
	read();
	
	printf("S'han trobat %i anagrames\n",angr);
}




int main(){

	process();
		
}
