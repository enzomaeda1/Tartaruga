#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <pthread.h> 

void *taylor(void *arg); 

int thread_count = 4;

long double resultado = 0; 


//Função série de Taylor
void *taylor(void *arg){

    int cont = (int)arg;
    
    resultado += (1.0 / cont);

    return NULL;
}

int main(){
    char temp;
    long int t = 1;
    long thread;

    //Inicia contagem de tempo

    time_t inicio = time(NULL);

    printf("\nAperte qualquer tecla para para começar contagem: ");
    scanf("%c", &temp);

    //Inicio e alocamento de threads

    pthread_t *thread_handles;

    thread_handles = malloc(thread_count * sizeof(pthread_t)); 

    do{ 
        for(thread = 0; thread < thread_count; thread++){
          //Soma da função e inicialização de nova thread
            pthread_create(&thread_handles[thread], NULL, taylor, &t);

            pthread_join(thread_handles[thread], NULL);

            t++;
        }
        //Saída
        printf("\nTartaruga caminhou: %.10Lf metros em %ld segundos", resultado, time(NULL) - inicio);

    }while(1); 

    free(thread_handles);
}
