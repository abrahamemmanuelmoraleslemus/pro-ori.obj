#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void sumaMatrix();
void restaMatrix();
void multiMatrix();
void dicho(char c);

int main(){
    int s,option;
    do{
        system("cls");
        printf("\n\t\tOPERACIONES DE MATRICES");
        printf("\n\n\tSeleccione:\n\t1 para Sumar matrices\n\t2 para Restar matrices\n\t3 para Multiplicar las matrices\n\t4 para salir del programa");
        printf("\n\n\tEscribe el numero de la opcion: "); scanf("%d",&option);
        switch(option){
            case 1: system("cls"); sumaMatrix(); break;
            case 2: system("cls"); restaMatrix(); break;
            case 3: system("cls"); multiMatrix(); break;
        }
        getchar();
    }
    while(option != 4);
}
// --------------------------- ( separador )
void sumaMatrix(){
    int f,c,a,cont,i,j;
    int matrizA[10][10],matrizB[10][10],matrizC[10][10];

    printf("\n\t\tSUMA DE MATRICES");
    printf("\n\tEl tamano de la matriz debe ser menor a 9\n\n");

    printf("\tCuantas filas requiere: "); scanf("%d",&f);
    printf("\tCuantas columnas requiere: "); scanf("%d",&c);

    dicho('X');

    for(i = 1 ; i <= f ; i++){
        for(j = 1 ; j <= c ; j++){
            printf("\tPosicion (%i,%i): ",i,j); scanf("%i",&a);
            matrizA[i][j] = a;
        }
        printf("\n");
    }

    dicho('Y');

    for(i = 1 ; i <= f ; i++){
        for(j = 1 ; j <= c ; j++){
            printf("\tPosicion (%i,%i): ",i,j); scanf("%i",&a);
            matrizB[i][j] = a;
        }
        printf("\n");
    }

    printf("\n\tLa suma de la matriz es:\n\n");

    for(i = 1 ; i <= f ; i++){
        for(j = 1 ; j <= c ; j++){
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
            printf("\t%i",matrizC[i][j]);
        }
        printf("\n");
    }
    getch();
}
void restaMatrix(){
    int f,c,a,r,i,j;
    int matrizD[10][10], matrizE[10][10], matrizF[10][10];

    printf("\n\t\tRESTA DE MATRICES");
    printf("\n\tEl tamano de la matriz debe ser menor a 9\n\n");

    printf("\tCuantas filas requiere: "); scanf("%d",&f);
    printf("\tCuantas columnas requiere: "); scanf("%d",&c);

    dicho('X');

    for(i = 1 ; i <= f ; i++){
        for(j = 1 ; j <= c ; j++){
            printf("\tPosicion (%i,%i):",i,j); scanf("%i",&a);
            matrizD[i][j] = a;
        }
        printf("\n");
    }

    dicho('Y');

    for(i = 1 ; i <= f ; i++){
        for(j = 1 ; j <= c ; j++){
            printf("\tPosicion (%i,%i):",i,j); scanf("%i",&a);
            matrizE[i][j] = a;
        }
        printf("\n");
    }

    printf("\n\tComo desea restar las matrices\t1: X - Y | 2: Y - X: "); scanf("%d",&r);
    printf("\n\n\tLa suma de la matriz es:\n\n");

    for(i = 1 ; i <= f ; i++){
        for(j = 1 ; j <= c ; j++){
            switch(r){
                case 1: matrizF[i][j] = matrizD[i][j] - matrizE[i][j]; break;
                case 2: matrizF[i][j] = matrizE[i][j] - matrizD[i][j]; break;
            }
            printf("\t%i",matrizF[i][j]);
        }
        printf("\n");
    }
    getch();
}
void multiMatrix(){
    int m,n,o,p,i,j,k,x,a;
    int matrizX[10][10], matrizY[10][10], matrizZ[10][10];

    printf("\n\t\tMULTIPLICACION DE MATRICES");
    printf("\n\tEl tamano de la matriz debe ser menor a 9\n\n");

    printf("\t\tMATRIZ X\n");
    printf("\tCuantas filas requiere: "); scanf("%d",&m);
    printf("\tCuantas columnas requiere: "); scanf("%d",&n);

    printf("\n\t\tMATRIZ Y\n");
    printf("\n\tCuantas filas requiere: "); scanf("%d",&o);
    printf("\tCuantas columnas requiere: "); scanf("%d",&p);

    if (m == p && n == o){ // <--- aqui le puse || para que no se produzca un bug (si salen errores cambia && por ||)

        // --- Asiganciones

        dicho('X');
        for(i = 1 ; i <= m ; i++){
            for(j = 1 ; j <= n ; j++){
                printf("\tPosicion (%i,%i):",i,j); scanf("%i",&a);
                matrizX[i][j] = a;
            }
            printf("\n");
        }

        dicho('Y');
        for(i = 1 ; i <= o ; i++){
            for(j = 1 ; j <= p ; j++){
                printf("\tPosicion (%i,%i):",i,j); scanf("%i",&a);
                matrizY[i][j] = a;
            }
            printf("\n");
        }

        // --- Calculo
        for (i=1 ; i <= m ; i++){
            for (j=1 ; j <= p ; j++){
                matrizZ[i][j] = 0;
                for(k=1 ; k <= n ; k++){
                    matrizZ[i][j] = matrizZ[i][j] + matrizX[i][k] * matrizY[k][j];
                }
            }
        }

        printf("\n\n\tLa multiplicacion de la matriz es:\n\n");

        // --- Resultado
        for (i = 1 ; i <= m ; i++){
            printf("\n");
            for(j = 1 ; j <= p ; j++){
                printf("\t%i",matrizZ[i][j]);
            }
        }
    }
    else{
        printf("\tNo se pueden multiplicar las matices :(");
    }
    getch();
}

void dicho(char c){
    printf("\n\n\t<:=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=:>");
    printf("\n\tVALORES DE LA MATRIZ %c",c);
    printf("\n\n");
}