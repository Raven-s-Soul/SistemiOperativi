# Coding for OS 
> [!NOTE]
>Semplici esempi.
>- Usate `apropos @pattern` e `man @pattern`.
>>- [Files]
>>- Fork
>>- Execvp
>>- Pthread.h
>>- Semaphore.h
>>- Mutex - lock
***
## Files
>[!TIP]
>```diff
>+ int file = open("filename", @Flags , @Mode);
>+ lseek(file, 0 /*offset*/ , SEEK_SET);
>+ read(file, &char, sizeof(char));
>+ write(file, buffer, dim*sizeof(char));
>+ close(file);
>```
```c
int dimensione(int fd){
        char c;
        int i = 1;
        int dim=0;
        while ((i = read(fd, &c, sizeof(char))) > 0)
            dim++; //LOG("Byte letti %d",i)
        return dim;
}
        ...
        int fileReadONLY=open(filename, O_APPEND | O_RDONLY,S_IRWXU);
        lseek(file,0,SEEK_SET);
        int fileRDWR=open(filename2, O_CREAT | O_TRUNC | O_RDWR,S_IRWXU | S_IRWXO | S_IRGRP | S_IWOTH);
        int dim=dimensione(fds);
        char appoggio[dim+1];
        lseek(fileReadONLY,0,SEEK_SET);
        read(fileReadONLY,appoggio,dim*sizeof(char));
        appoggio[dim] = '\0'; // Garbage
        write(fileRDWR,appoggio,dim*sizeof(char));
        lseek(fileRDWR,0,SEEK_SET);
        read(fileRDWR,appoggio,dim);
        close(fds);
        close(fdd);
        ...
```
***
## Fork
>[!TIP]
>```diff
>```
```c
```
***
## Execvp
>[!TIP]
>```diff
>```
```c
```
***
## Pthread.h
>[!TIP]
>```diff
>+  #include <pthread.h>
>+  void* routine(void* args){}
>+  pthread_t th[THREAD_NUM];
>+  pthread_create(&th[i], NULL, &routine, a);
>+  pthread_join(th[i], NULL);
>```
```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define THREAD_NUM 16

void* routine(void* args) {
    sleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    free(args);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    return 0;
}
```
***
## Semaphore.h
>[!TIP]
>```diff
>+ #include <semaphore.h>
>+ sem_wait(&semaphore);
>+ sem_post(&semaphore);
>+ sem_init(&semaphore, 0, 2);
>// &arg, (0 generale, != 0 usato con fork), @MaxConcorrenti
>+ sem_destroy(&semaphore);
>```
```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#define THREAD_NUM x

sem_t semaphore;
sem_t semaphore2;

void* routine(void* args) {
    sem_wait(&semaphore); // Prima sezione critica
    sleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
    sem_wait(&semaphore2); // Seconda sezione critica
    sem_post(&semaphore2); // Operazioni nella seconda sezione critica
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 2);
    sem_init(&semaphore2, 0, 1); // Inizializza anche semaphore2
    for (int i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semaphore); // Distruggi i semafori al termine
    sem_destroy(&semaphore2);
    return 0;
}
```
***
## Mutex - lock
>[!TIP]
>```diff
>+ #include <pthread.h>
>+ pthread_mutex_t mutex;
>+ pthread_mutex_lock(&mutex);
>+ pthread_mutex_unlock(&mutex);
>+ pthread_mutex_init(&mutex, NULL);
>+ pthread_mutex_destroy(&mutex);
>```
```c
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine() {
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&p1, NULL, &routine, NULL)
    pthread_create(&p2, NULL, &routine, NULL)
    pthread_join(p1, NULL)
    pthread_join(p2, NULL)
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}
```
