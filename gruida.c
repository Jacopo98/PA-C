/*
 ============================================================================
 Name        : Allenamento-1.c
 Author      : @JacopoBoffelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h> //libreria necessaria per la stampa in output (getchar, getchar, printf e scanf)
#include <stdlib.h>
#include <string.h>
#include <malloc.h> //utilizzare le funzioni di allocazione e deallocazione della memoria

// create struct with person1 variable
struct Person {
	char name[50];
	int citNo;
	float salary;
};

struct Person person1;

int main(void) {
	printf("!!!Hello !!!"); /* prints !!!Hello World!!! */

	double x = 7.0;
	double y = 5;
	double z = x + y;
	printf("Ciaooo %f \n", z);

	
	 int i;
	 scanf("%d", &i); 	//quando richiedo l'input devo passare l'indirizzo di i
	 printf("%d \n", i);


	 char stringa[100];
	 scanf("%s", stringa); // non devo passare l'indirizzo di stringa perché il nome dell'array corrisponde all'indirizzo di partenza dell'array stesso.
	 printf("%s \n", stringa);
	 

	//condizione if
	if (y > x) {
		printf("X è maggiore di Y");
	}

	//blocco iterativo While
	int j = 0;
	while (j != 100) {
		j++;
		printf("Valore attuale di j: %d \n", j);
	}

	//blocco iterativo For
	int i;
	for (i = 0; i <= 100; i++)
		printf("%d \n \n", i);

	//Array
	creaArray(10);

	int risultato = elevaPotenza(2, 5);
	printf("Potenza: %d", risultato);

	// struct (definito fuori dal main)
	// assign value to name of person1
	strcpy(person1.name, "George Orwell");

	// assign values to other person1 variables
	person1.citNo = 1984;
	person1.salary = 2500;

	// print struct variables
	printf("Name: %s\n", person1.name);
	printf("Citizenship No.: %d\n", person1.citNo);
	printf("Salary: %.2f \n", person1.salary);

	printf("*********************************** \n");

	//Casting
	// Casting da float ad int
	int num;
	float reale;
	reale = 47.89;
	num = (int) reale; // vale 47
	printf("numero: %d \n", num);

	// Casting da int a float
	int numero1;
	float reale1;
	numero1 = 18;
	reale1 = (float) numero1;
	printf("numero: %f \n", reale1);

	// Casting da char ad int
	int numero2;
	int lettera;
	lettera = 'A';
	numero2 = (int) lettera; // vale 65, il valore ASCII di A
	printf("numero: %d \n", numero2);

	printf("*********************************** \n");
	// puntatori
	int alfa = 4;
	int beta = 7;
	int *pointer;
	pointer = &alfa;

	printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer); //4,7,ind

	beta = *pointer;
	printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer); //4,4,ind

	alfa = pointer;
	printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer); //ind, 4, ind

	*pointer = 5;
	printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer); //5, 4, ind

	printf("*********************************** \n");
	//funzione con puntatori
	int alfax = 5;
	int betax = 13;
	printf("alfa -> %d, beta -> %d\n", alfax, betax);
	swap(&alfax, &betax);
	printf("alfa -> %d, beta -> %d\n", alfax, betax);

	printf("*********************************** \n");
	// definisco un array ed una variabile intera
	int array[20], h;
	array[0]=99;
	array[1]=22;
	// creo il puntatore;
	int *puntatore;
	// puntatore all'indirizzo di a[0]
	puntatore = &array[0];
	// x prende il valore di pointer, cioè di a[0];
	h = *puntatore;

	printf("puntatore: %d \n", puntatore);
	printf("primo el array: %d \n", *puntatore);
	printf("primo el array: %d \n", h);  //stesso della riga prima
	printf("secondo el array: %d \n", *(puntatore+1));


	// allocazione della memoria
	int numero, *arr, u;
	char buffer[15];
	int allocati;
	numero = 100;
	printf("Numero di elementi dell'array: %d", numero);

	arr = (int *)malloc(sizeof(int) * numero);

	if(array == NULL) {
		printf("Memoria esaurita\n");
		exit(1);
	}

	allocati = sizeof(int) * numero;

	for(u=0; u<numero; u++) {
		arr[u] = u;
	}

	printf("\nValori degli elementi\n");

	for(u=0; u<numero; u++) {
		printf("%6d%c", arr[u], u%10 == 9 ? '\n' : ' '); //6 davanti a d serve per stampare gli interi con dello spazio
	}

	printf("\n\nNumero elementi %d\n", numero);
	printf("Dimensione elemento %d\n", sizeof(int));
	printf("Bytes allocati %d\n", allocati);

	free(arr);

	printf("\nMemoria Liberata\n");

}

//dichiarazione variabili
char carattere; 		//carattere
int intero;				//numero intero	(16bit)
short corto; 			//numero intero corto (16bit)
long lungo;				//numero intero lungo (32 bit)
float reale;			//numero reale (32 bit)
double realelungo;		//numero reale lungo (64 bit)

/*
 * Alcuni degli specificatori di formato sono:
 *
 * %d ---> interi
 * %f ---> float/double
 * %e ---> decimali (notazione esponenziale)
 * %c ---> caratteri
 * %s ---> Una stringa di caratteri
 *
 *  */

// funzioni
void creaArray(int dimensione) {
	int n = dimensione;
	int a[n];

	for (int k = 0; k < n; k++) {
		a[k] = k;
	}

	for (int k = 0; k < 10; k++) {
		printf("%d \n", a[k]);
	}

}

int elevaPotenza(int base, int esponente) {
	int valore = base;
	for (int y = 0; y < esponente - 1; y++) {
		valore *= base;
	}
	return valore;
}

//funzione swap (alfa, beta) che scambia il valore di alfa con beta e viceversa

void swap(int *apt, int *bpt) {
	int temp;
	temp = *apt;
	*apt = *bpt;
	*bpt = temp;
}

