#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2


// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!


int main(int argc, char** argv) {

    // ....

    /*************************************************
     * Dicas:                                        *
     * 1. Leia as intruções antes do main().         *
     * 2. Faça os prints exatamente como solicitado. *
     * 3. Espere o término dos filhos                *
     *************************************************/
	for(int i=0;i<2;i++) // quantidade de processos filhos a serem criados
    { 
        if(fork() == 0) // Criaçao do processo filho
        { 
        printf("O processo pai criou %d\n",getpid());
        printf("O processo filho %d foi criado\n",getpid());
        exit(0); // (opcional) saida do processo , afim de garantir a saida
        }
    } 
    for(int i=0;i<2;i++){ // loop para espera da finalizaçao do processo filho
        wait(NULL) ;      // execuçao do codigo do processo pai
    }
    printf("Processo pai finalizado!\n");
}
