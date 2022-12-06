#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define WORD_LENGHT 50
#define COD_LENGHT 26
#define WORDS_MAX 11

int WORDS_COUNT = 1;
char words[WORDS_MAX][WORD_LENGHT+1];
int codified_words[WORDS_MAX][COD_LENGHT]={{0}};

//Funció per llegir i enmagatzemar les paraules de búsqueda del text.

void store_search(){

	char c,c_prev;
	
	int i=0,p=0;
	
	scanf("%c",&c);
		
	while(c != '.' and p != WORD_LENGHT){
		if(c == ' ' and isalpha(c_prev)){
			words[i][p] = '\0';
			WORDS_COUNT++;
			i++;
			p = 0;
		}else if(c!=' '){
			
			words[i][p] = c;
			p++;
		}
		c_prev = c;
		scanf("%c",&c);
	}
	//debug only
	for(int i=0;i<WORDS_COUNT;i++){
		printf("%s\n",words[i]);
	}	
}

//Codificar les paraules d'entrada

char codify(char word[WORDS_MAX][WORD_LENGHT+1]){

	for(int i=0;i<WORDS_COUNT;i++){
	
		for(int j=0;j<WORD_LENGHT;j++){
			
			codified_words[i][('z'-tolower(word[i][j]))]++;
		
		}
	
	}
	
	for(int i=0;i<WORDS_COUNT;i++){
		for(int j=0;j<COD_LENGHT+1;j++){
			printf("%i",codified_words[i][j]);
		}
		printf("\n");
	
	}


	return 0;

}


int main(){

	store_search();

	
	codify(words);
	
	
	

}
