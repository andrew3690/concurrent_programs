#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

//                          (principal)
//                               |
//              +----------------+--------------+
//              |                               |
//           filho_1                         filho_2
//              |                               |
//    +---------+-----------+          +--------+--------+
//    |         |           |          |        |        |
// neto_1_1  neto_1_2  neto_1_3     neto_2_1 neto_2_2 neto_2_3

// ~~~ printfs  ~~~
//      principal (ao finalizar): "Processo principal %d finalizado\n"
// filhos e netos (ao finalizar): "Processo %d finalizado\n"
//    filhos e netos (ao inciar): "Processo %d, filho de %d\n"

// Obs:
// - netos devem esperar 5 segundos antes de imprmir a mensagem de finalizado (e terminar)
// - pais devem esperar pelos seu descendentes diretos antes de terminar

//Meu codigo que vale 6 pontos 
/*pid_t filho,neto;
		filho = fork();
		if (filho < 0){
			fprintf(stderr, "Erro ao criar filho\n");
		}else if(filho == 0){
			printf("Processo %d filho de %d\n",getpid(),getppid());
			for(int i = 0 ;i < 3;i++){
				neto = fork();
				if(neto < 0){
					fprintf(stderr, "Erro ao criar o neto\n");
				} else if(neto == 0){
					printf("Processo %d filho de %d\n",getpid(),getppid()); 
				} else {
					wait(NULL);
					printf("Processo %d finalizado\n",getpid());
				}
			}
		}else {
			wait(NULL);
			printf("Processo principal %d finalizado\n", getpid());  
		}
*/
int main(int argc, char** argv) {
    
    // ....

    /*************************************************
     * Dicas:                                        *
     * 1. Leia as intruções antes do main().         *
     * 2. Faça os prints exatamente como solicitado. *
     * 3. Espere o término dos filhos                *
     *************************************************/
	pid_t filho,neto; // declaraçao de processos filhos e netos
	for(int i=0;i<2;i++) // loop para criaçao dos processos filhos
    	{ 
        if((filho = fork()) == 0) // criaçao do processo fiho
        { 
        printf("Processo %d, filho de %d\n",getpid(),getppid());
        fflush(stdout); // evita repetiçao de print
        for(int i = 0;i < 3;i++){ // loop pra criaçao do processo neto
        	if ((neto =fork()) == 0){ // criaçao e execuçao do processo neto
        	printf("Processo %d filho de %d\n",getpid(),getppid());
        	sleep(5);
        	printf("Processo %d finalizado\n",getpid());
        	exit(0);
        	}
        }
        for(int i = 0; i < 3;i++){ // loop para espera da finalizaçao de cada processo neto 
        	wait(NULL);
        }
        printf("Processo %d finalizado\n",getpid()); // finalizaçao do processo
        exit(0);
        }
	} 
	    for(int i=0;i<2;i++){ // loop para espera da finalizaçao de cada processo filho
		wait(NULL);
	    }
		printf("Processo principal %d finalizado\n", getpid()); // finalizaçao de processo filho
	    }

		printf("O processo pai criou %d\n",getpid());
		printf("O processo filho %d foi criado\n",getpid());
		exit(0);
		}
	    } 
	    for(int i=0;i<2;i++){ // loop para espera da finalizaçao do processo filho 
		wait(NULL);
	    }
	    printf("Processo pai finalizado!\n");
	}
