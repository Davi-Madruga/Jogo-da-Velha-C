#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	
	int l, c, linha = 0, coluna = 0;
	char marca = 'O';
	bool gameover = false;
	char lista[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
	
	while(!gameover){
		

	
	//Printar tabuleiro
	for(l=0;l<3;l++){
		for(c=0;c<3;c++){
			printf("%c",lista[l][c]);
			if (c < 2) printf("|");
		}
		if (l < 2) printf("\n------\n");
	}
	
	//Celula Marcada
	if (marca == 'X') marca = 'O';
	else marca = 'X';
	printf("\n\nVez do jogador %c",marca);
	
	while(1){
	printf("\nLinha: ");
	scanf("%d",&linha);
	
	printf("Coluna: ");
	scanf("%d",&coluna);
	printf("\n");
	if(lista[linha][coluna] == ' '){
		lista[linha][coluna] = marca;
		break;
	}else if (lista[linha][coluna] == 'O' || lista[linha][coluna] == 'X'){
		printf("Celula preenchida\n");
		continue;
	} else{
		printf("Inválido");
	}
	}
	
	//verificar vencedor
	for(l=0;l<3;l++){
		if(lista[l][0] != ' ' && lista[l][0] == lista[l][1] && lista[l][0] == lista[l][2]) gameover = true;
		}
	for(c=0;c<3;c++){
		if(lista[0][c] != ' ' && lista[0][c] == lista[1][c] && lista[0][c] == lista[2][c]) gameover = true;
		}
	if (lista[0][0] == lista[1][1] && lista[0][0] == lista[2][2] && lista[0][0] != ' ' || 
	lista[0][2] == lista[1][1] && lista[0][2] == lista[2][0] && lista[0][2] != ' ') gameover = true;
	}
	
	printf("\n\n");
	return 0;
}
