#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORD_LENGHT 50
#define MAX_WORDS 10
#define COD_LENGHT 26

void compare();

//variables globals

char search_words[MAX_WORDS][WORD_LENGHT+1];
char word[WORD_LENGHT+1];

int codified_words[MAX_WORDS+1][COD_LENGHT]={{}};
int codified_word[COD_LENGHT]={};


void read_search(){

	char letter,letter_prev = ' ';
	
	int i=0;
	int j=0;
	
	scanf("%c",&letter);
	
	while(letter != '.' and i<=MAX_WORDS and j<WORD_LENGHT){ 
		if(isalpha(letter)){ 			//if the char is a letter add into the the array
			search_words[i][j] = letter;	//
			j++;				//increment letter position
		}else if(!isalpha(letter) and isalpha(letter_prev)){ //if the next char is not a letter switch to new word.
			search_words[i][j+1]= '\0';
			i++;
			j=0;
		}
		letter_prev = letter;
		scanf("%c",&letter);	
	}
	//debug only show arrays
	
	//for(int i=0;i<MAX_WORDS;i++){
	//	if(search_words[i]!=" "){
	//		printf("%s\n",search_words[i]);
	//	}
	//}
}

void read_word(){

	char letter,letter_prev = ' ';
	
	int i=0;
	
	scanf("%c",&letter);
	
	while(letter != '.' and i<WORD_LENGHT){ 
		if(isalpha(letter)){ 		
			word[i] = letter;
			i++;			
		}else if(!isalpha(letter) and isalpha(letter_prev)){
			word[i+1]= '\0';
			compare();
			
		}
		letter_prev = letter;
		scanf("%c",&letter);
	}
	compare();
	
	
}

int codify(char arr[WORD_LENGHT+1]){

	int pos = 0;
	
	for(int j=0;j<=WORD_LENGHT;j++){
	
		if(tolower(arr[j])>='a' and tolower(arr[j])<='z'){
			pos = 'z'-tolower(arr[j]);
			codified_word[pos]++;	
		}
	}
	printf("%s",arr);

	return 1;
}

void store_search(){

	//store search words codified
	
	for(int i=0;i<MAX_WORDS;i++){
		codify(search_words[i]);
		for(int j=0;j<COD_LENGHT;j++){
			codified_words[i][j] = codified_word[j];
		}
		memset(codified_word,0,sizeof(codified_word)); //reset list
		
	}
	
	//for(int i = 0;i<MAX_WORDS;i++){
	//	for(int j = 0; j<COD_LENGHT;j++){
	//		printf("%i",codified_words[i][j]);
	//	}
	//	printf("\n");
	//}
	
}

int store(int arr[WORD_LENGHT+1]){

	//store word codified

	for(int i=0;i<WORD_LENGHT;i++){
		codified_words[10][i] = arr[i];
	}
	
	return 0;

}

void compare(){

	int j;
	int c=0;
	
	codify(word);
	
	for(int i=0;i<MAX_WORDS;i++){
		
		for(j=0;j<COD_LENGHT;j++){
        	if(codified_word[j]==codified_words[i][j]){
				c++;
			}
		}
		
		if(c==j){
			printf("Anagrama de la paraula \"%s\" trobat: \"%s\".\n",search_words[i],word);
		}
		c=0;	
	}
	memset(word,0,sizeof(word));
	memset(codified_word,0,sizeof(codified_word));
	
	
}

int main(){

	read_search();
	
	store_search();
	
	read_word();
		
}
