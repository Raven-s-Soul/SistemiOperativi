#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//      #include <stdio.h>
// 	Debug Macro
#define DEBUG_LOG 0
//	1 - Active , 0 - Deactive
#if DEBUG_LOG
#define LOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__);
#else
#define LOG(fmt, ...) ;
#endif

int dimensione(int fd){
        char c;
        int i = 1;
        int dim=0;
        while ((i = read(fd, &c, sizeof(char))) > 0) {
                //i=read(fd,&c,sizeof(char));
                LOG("Byte letti %d",i)
		dim++;
        }
        return dim;
}

void copy(char* s, char* d){

        int fds=open(s, O_APPEND | O_RDONLY,S_IRWXU);
        lseek(fds,0,SEEK_SET);

        int fdd=open(d, O_CREAT | O_TRUNC | O_RDWR,S_IRWXU | S_IRWXO | S_IRGRP | S_IWOTH);

        printf("\nMetto da %s -> %s\n",s,d);

        if(fds==-1){
                printf("\nErrore nell'apertura del file sorgente\n");
                exit(-1);
        }
        if(fdd==-1){
                printf("\nErrore nell'apertura del file destinatario\n");
                exit(-1);
        }

        //calcolo dimensione del file sorgente
        int dim=dimensione(fds);
        //char *appoggio=(char*)malloc(dim);
        char appoggio[dim+1];
        lseek(fds,0,SEEK_SET);
        read(fds,appoggio,dim*sizeof(char));
	// Clean Garbage
	appoggio[dim] = '\0';
        printf("%s: %s", s , appoggio);
	int t = write(fdd,appoggio,dim*sizeof(char));
        //LOG("Totali: %d usati %d",dim, t)
        lseek(fdd,0,SEEK_SET);
        read(fdd,appoggio,dim);
	printf("%s: %s", d , appoggio);
        //free(appoggio);
        close(fds);
        close(fdd);
}

int main(){
        printf("\nInserisci nome del file sorgente: ");
        char s[50];
        scanf("%s%*c",s);
        printf("\nInserisci nome del file destinatario: ");
        char d[50];
        scanf("%s%*c",d);

        LOG("%s",s)
        LOG("%s",d)

        copy(s,d);
        printf("Copia terminata\n");
        return 0;
}
