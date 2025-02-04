#include <stdio.h>
#include <pthread.h>

/*
Implementa un programma che riceva per argomento quattro numeri interi e che avvii quattro
thread, ognuno dei quali effettuer   un test di primalit
su uno dei numeri ricevuti per argomento. Ognuno di questi thread, se il numero in input
stato verificato essere primo, aggiorner   una variabile globale condivisa in modo tale
che quest'ultima contenga, al termine dell'esecuzione dei quattro thread, il valore del
primo maggiore. Il thread principale, dopo aver atteso la terminazione dei quattro thread,
stamper   a video il valore della variabile globale precedentemente introdotta.

Suggerimenti:
- Utilizzare un algoritmo semplice per effettuare il test di primalit  .
Ad esempio,    sufficiente verificare la divisibilit   intera per tutti gli interi a partire
da 2 alla radice quadrata del numero da testare. Se il numero da testare risulta divisibile
per uno di questi numeri, allora non    primo

- E' possibile convertire a interi i numeri in formato stringa passati come argomento
utilizzando la funzione atoi() - man atoi per maggiori informazioni.

- Se si usa sqrt() da math.h    necessario utilizzare l'opzione -lm sulla riga di comando di gcc
*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int max = -1;

int primalit(int i){
        // Implementazione minima
        return (i % 2) == 0;
}

void *thread(void * args){
        //printf("%d\n", *(int *)args);
        if(primalit(*(int*)args)){
                pthread_mutex_lock(&mutex);
                if(max < *(int*)args)
                        max = *(int*)args;
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}
int main(){
        // Inputs
        int input[4];
        for(int  i = 0; i < 4 ; i++){
        printf("Input %d scegli un numero:", i+1);
        scanf("%d", &input[i]);
        // printf("%d\n", input[i]);
        }

        pthread_t t[4];

        for(int i = 0; i < 4 ; i++){
                /*
                pthread_create(pthread_t *restrict, const pthread_attr_t *restrict,
                     void *(*)(void*), void *restrict);
                */
                 pthread_create(&t[i], NULL, &thread, &input[i] );
        }
        for(int i = 0; i < 4 ; i++){
                /*
                 int   pthread_join(pthread_t, void **);
                */
                pthread_join(t[i], NULL);
        }
        printf("Il primo piu grande e' %d\n", max);
        return 0;
}