#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	
	int i,j;
	bool gameover = false;
	char lista[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
	while(!gameover){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%c",lista[i][j]);
			if (j < 2) printf("|");
		}
		if (i < 2) printf("\n------\n");
	}
	gameover = true;
	}
	printf("\n\n");
	return 0;
}
