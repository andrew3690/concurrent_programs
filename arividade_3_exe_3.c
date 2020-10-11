


for(int i = 0;i < n_threads;i++){
        vet[i] = malloc(sizeof(vals));      // alocaçao dinamica para o struct valores por meio da variavel declarada
        //vet[i] -> a_size = a_size;                // atribuiçao das variaveis 
        vet[i] -> a = a;
        vet[i] -> b = b;
        vet[i] -> begin = i * range;
        vet[i] -> end = end;
        vet[i] -> result = 0;
        //double *resultado;                   // ponteiro do tipo double para comunicaçao do resultado da funçao somar 
                                        //for(int i = 0 ; i < n_threads ;i++){ // carregamento das threads
        begin = range * i;               // distribuiçao das atividades das threads
        if(i != n_threads -1){           
            end = begin + range;         // fim do vetor como a soma do inicial e a media de atividade das threads
        } else {
            end = a_size;                // fim do vetor com o tamanho do vetor
        }
        vet[i] -> begin = begin;
        vet[i] -> end = end;
        pthread_create(&threads[i],NULL,somar,(void *)vet[i]); // criaçao da thread com passagem de ponteiros e funçao somar
    }
