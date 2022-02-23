# include <stdio.h>
# include <stdlib.h>

# define MAX_CHAR 10
# define CMD_MAX 100

/* Questo programma funziona solo se macchanger è installato sul pc.*/
/* Questo programma funziona solo se stai utilizzando Linux.*/
/* Devi essere amministratore. */

int main (void) {

	char interfaccia[MAX_CHAR];
	char comando[CMD_MAX];

	printf("\n >>> Lista delle interfaccie:\n");					// mostro all'utente le interfacce utili.

	system("ifconfig -s");

	printf("\n >>> Inserire l'interfaccia desiderata [Iface]: ");
	scanf("%s", interfaccia);										// prendo in input il nome dell'interfaccia inserita.

	sprintf(comando, "ifconfig %s down", interfaccia);				
	system(comando);												// spengo l'interfaccia.

	sprintf(comando, "macchanger --random %s", interfaccia);		
	system(comando);												// utilizzo macchanger per eseguire lo spoofing del MAC.


	system("service network-manager restart");						// restart dei servizi di rete.

	sprintf(comando, "ifconfig %s up", interfaccia);				
	system(comando);												// accendo l'interfaccia che era stata spenta.

	printf("\n");
	return 0;
};	