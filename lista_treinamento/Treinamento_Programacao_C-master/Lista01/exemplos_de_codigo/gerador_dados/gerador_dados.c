#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LINHAS1		10			// numero de linhas do arquivo 1
#define LINHAS2		483			// numero de linhas do arquivo 2

#define MAX_NUM		10000		// define o valor maximo para os numeros geradoss
int main(){
	// Declaracao de variaveis
	FILE* dados1;
	FILE* dados2;
	FILE* dados3;
	
	uint8_t byte;
	int i, j;
	
	// Abertura de arquivos
	dados1 = fopen("dados1.csv", "wt");
	dados2 = fopen("dados2.csv", "wt");
	dados3 = fopen("dados3.bin", "wb");
	
	// Verifica se os arquivos abriram corretamente
	if(dados1 == NULL || dados2 == NULL){
		printf("Erro na abertura dos arquivos.\n");
		return -1;
	}
	
	// Inicializacao da funcao pseudo-aleatoria com a semente(valor inicial) 2116
	srand(2116);
	
	// Geracao dos dados do arquivo "dados1.csv"
	for(i = 0; i < LINHAS1; i++){
		fprintf(dados1, "%d, %d, %d\n", rand()%MAX_NUM, rand()%MAX_NUM, rand()%MAX_NUM);
	}
	
	// Geracao dos dados do arquivo "dados2.csv"
	for(i = 0; i < LINHAS2; i++){
		fprintf(dados2, "%d, %d, %d\n", rand()%MAX_NUM, rand()%MAX_NUM, rand()%MAX_NUM);
	}
	
	// Geracao dos dados do arquivo "dados3.bin"
	for(i = 0; i < 3; i++){
		byte = (uint8_t)(rand()%MAX_NUM);
		fwrite(&byte, sizeof(uint8_t), 1, dados3);
	}
	
	// Fechamento dos arquivos
	fclose(dados1);
	fclose(dados2);
	fclose(dados3);
	
	return 0;
}