#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Size of the cylinder*/
#define size_cylinder 8
/*Maximum size disk*/
#define max_size_cylinder 4999


//Create a int array for testing
int cylinder[size_cylinder] = {98,183,37,122,14,124,65,67};

//Generates a queue cylinder randomly
void generate_cylinder(){
    int numero,i;
    for(i = 0; i<size_cylinder; i++)
    {
        numero = rand()%size_cylinder;
        cylinder[i] = numero;
        printf("%d ", numero);
    }
}


void FCFS(){
    int n,cabeza,i,j,k,seek=0,diferencia;
    float promedio;

    printf("\t FCFS Algoritmo\n");

    printf("Ingrese la posicion inicial de la cabeza\n");
    scanf("%d", &cabeza);
    cylinder[-1] = cabeza;
    printf("\n");

    for(j = -1; j < size_cylinder-1; j++)
    {
        diferencia = abs(cylinder[j+1]-cylinder[j]);
        seek += diferencia;
        printf("%d ", cylinder[j]);
    }
    printf("\n Tiempo total del seek es %d\t", seek);
    promedio = seek/(float)size_cylinder;
    printf("\n El promedio de tiempo seek es %f\t\n", promedio);
}

void SSTF(){
    int t[size_cylinder],cabeza,seek=0,n,i,j,temp;
    float promedio;

    printf("Ingrese la posicion inicial de la cabeza\n");
    scanf("%d", &cabeza);

    for(i = 1; i < size_cylinder; i++)
    {
        t[i] = abs(cabeza - cylinder[i]);
    }

    for(i = 0; i < size_cylinder; i++)
    {
        for(j = i+1; j < size_cylinder; j++)
        {
            if(t[i] > t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;

                temp = cylinder[i];
                cylinder[i] = cylinder[j];
                cylinder[j] = temp;
            }
        }
    }
    for(i = 1; i < size_cylinder-1; i++)
    {
        seek = seek + abs(cabeza - cylinder[i]);
        cabeza = cylinder[i];
    }

    for(i = 0; i < size_cylinder; i++)
    {
        printf("%d ", cylinder[i]);
    }

    printf("\n Tiempo total del seek es %d\t", seek);
    promedio = seek/(float)size_cylinder;
    printf("\n El promedio de tiempo seek es %f\t\n", promedio);
}

void scan(){

    int i,j,seek = 0,n= size_cylinder;
    int cabeza,diferencia1=0,diferencia2=0,diferencia3=0;
    int temp,max;
    int dloc;   //loc of disk in array
    float promedio;

    printf("Ingrese la posicion inicial de la cabeza\n");
    scanf("%d",&cabeza);

    cylinder[n] = cabeza;
    n = n + 1;

    // sorting the queue
    for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
      {
        if(cylinder[i] > cylinder[j])
        {
            temp = cylinder[i];
            cylinder[i] = cylinder[j];
            cylinder[j] = temp;
        }
      }
     }

    max = cylinder[n];

    for(i = 0; i < n;i++)
    {
        if(cabeza == cylinder[i])
        {
            dloc = i; break;
        }
    }

    for(i = dloc ; i >= 0; i--)
    {
        printf("%d ",cylinder[i]);
        diferencia1 = diferencia1 + abs(cylinder[i]-cylinder[i-1]);

    }
    diferencia3 = diferencia1;

    printf("0 ");
    for(i = dloc + 1; i < n; i++)
    {
        printf("%d ",cylinder[i]);
        diferencia1 = diferencia2 + abs(cylinder[i]-cylinder[i+1]);
    }

    seek = diferencia3 + diferencia1;
    printf("\n Tiempo total del seek es %d\t", seek);
    promedio = seek/(float)n;
    printf("\n El promedio de tiempo seek es %f\t\n", promedio);

}

void menu() {
    int opcion = 0;

    while (opcion != 4) {
        printf("\n\n\n");
        printf("Elija la opción: \n");
        printf("1 - FCFS\n");
        printf("2 - SSTF\n");
        printf("3 - SCAN\n");
        printf("4 - SALIR\n");

        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                system("clear");
                FCFS();
                break;
            case 2:
                system("clear");
                SSTF();
                break;
            case 3:
                system("clear");
                scan();
                break;
            case 4:
                break;
            default :
                printf("Opción no válida");
                break;
        }
    }
}


void main() {
    menu();
}





