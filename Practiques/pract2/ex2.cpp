#include <stdio.h>

float matrix_4x4[4][4];
float matrix_3x3[3][3];


//scan and store the matrix

void scan_store(){

	printf("Introdueix la matriu 4x4: \n");
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%f",&matrix_4x4[i][j]);
		}
	}
}

//calculate the determinant of the matrix

float calculate_4x4(){

	float det=1;
	
	for(int k=0;k<4;k++){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(i!=0 and j!=k){
					matrix_3x3[i][j]=matrix_4x4[i][j];
					printf("%g",matrix_3x3[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return det;
}

float calculate_3x3(mat[3][3]){

	float det;
	
	
	
	
	

	
	return det;
}

//show final results

float show_results(float det){

	printf("La matriu introduïda és: \n");
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%g ",matrix_4x4[i][j]);
		}
		printf("\n");
	}
	printf("El determinant és %g.\n",det);
	
	return 0;
}


int main(){

	scan_store();
	
	show_results(calculate_4x4());
}
