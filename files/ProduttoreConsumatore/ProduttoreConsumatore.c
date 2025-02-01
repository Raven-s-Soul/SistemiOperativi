#include <stdio.h>
// 	Debug Macro
#define DEBUG_LOG 1
//	1 - Active , 0 - Deactive
#if DEBUG_LOG
#define LOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__);
#else
#define LOG(fmt, ...) ;
#endif

#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

#define MaxCoda 10
// Struct coda
typedef struct Coda{
	int array[MaxCoda];
	int head;
	int coda;
} cd;

cd coda;

// Dequeue
int Dequeue(){
	if(coda.head == coda.coda){
		LOG("Cannot Clear index %d", coda.coda)
		return -1; //Error
	}
	else{
		if(coda.coda +1 == MaxCoda){
			coda.coda = 0;
			int a = coda.array[MaxCoda - 1];
			coda.array[MaxCoda - 1] = 0;
			return a;
		}
		else{
			(coda.coda)++;
			int a = coda.array[coda.coda - 1];
			coda.array[coda.coda - 1] = 0;
			return a;
		}
	}
	return -1;
}

// Enqueue
void Enqueue(int i){
	if(coda.head + 1 == MaxCoda){
		if( 0 == coda.coda)
			LOG("Coda piena index %d", coda.head)
		else {
			coda.head = 0;
			coda.array[coda.head] = i;
		}
	}
	else if(coda.head +1 == coda.coda){
		LOG("Coda piena index %d", coda.head)
		return;
	}
	else{
		coda.array[coda.head] = i;
		coda.head++;
	}
}

void printQueue(){
	for(int i = 0; i < MaxCoda; i++)
		LOG("Index %d = %d", i , coda.array[i])
}

void initQueue(){
	for(int i = 0; i < 15; i++)
		coda.array[i]  = 0;
	coda.head = 0;
	coda.coda = 0;
}

// Testing
void fillQueue(){
	for(int i = 0; i< MaxCoda; i++)
		Enqueue(i);
		//coda.array[i] = i;
}

// Testing
void clearQueue(){
	for(int i = 0; i< MaxCoda; i++)
		Dequeue();
}

// Produttore
void *Produttore(void *arg){
	while(1){
	
	}
}

// Consumatore
void *Consumatore(void *arg){
	while(1){
	
	}
}


int main(){
	initQueue();
	// Queue Tests
	/*
	{
		fillQueue();
		LOG("Filled")
		printQueue();
		clearQueue();
		LOG("Dequeuing")
		printQueue();
		LOG("Refill")
		fillQueue();
		printQueue();
		LOG("Dequeuing")
		clearQueue();
		printQueue();
	}
	*/
	pthread_t c,p;
	pthread_create(&c , NULL , Consumatore, NULL);
	pthread_create(&p , NULL , Produttore , NULL);
	pthread_join(c, NULL);
	pthread_join(p, NULL);
	return 0;
}
