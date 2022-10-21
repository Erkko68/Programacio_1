//Pràctica ruleta//
//definir llibreries standard

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//inicialització generacio de nombres aleatoris.

int random_numb(int n){

	srand(time(NULL));
	n = rand() % 36 + 1;
	
	return(n);
}

//Funció mostrar enunciats

void welcome_print(){ 

	printf("Benvingut al joc de la ruleta!\n");

}

//Funció calcular capital

int capital_cal(int mode, bool result,int aposta){

	int capital_inicial=1000;
	int capital_calc = capital_inicial;

	//Mode endevinar numero

	if(mode==1){ 
		if(result==1){	//Guanyar implica multiplicar la aposta per 36 restant la propia aposta.
		
			capital_calc=(capital_calc)+(aposta*36-aposta);
			
			return(capital_calc);
		
		}else if(result==0){ //perdre es restar la aposta al capital
		
			capital_calc=capital_calc-aposta;
			
			return(capital_calc);
		
		}
		
	//Mode endevinar parell o imparell	

	}else if(mode==2){
	
		if(result==1){ //guanyar suma el valor de la aposta al capital en aquell moment
		
			capital_calc=capital_calc+aposta;
			
			return(capital_calc);
		
		}else if(result==0){	//perdre resta el valor de la aposta al capital en aquell moment
		
			capital_calc=capital_calc-aposta;
			
			return(capital_calc);
		
		}
	
	}

	return 0;

}

void mostrar_capital(int capital_final){

	printf("Tens un capital de %i Euros.",capital_final);


}
void mode_1(){

	


}

int main(){

	int n = random_numb(n); //definir el nombre aleatori
	int capital_final;	//definir variable on guardar el capital final
	
	capital_final = capital_cal(1,1,200);
	
	welcome_print();
	mostrar_capital(capital_final);
	
}
