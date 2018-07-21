#include <stdio.h>

int eh_maiusculo(char c){
  int retorno = 1;
    if (c <='z'  && c >= 'a'){
        retorno = 0;
    }
  return retorno;
}

float media (int n , float * N){

    float soma = 0;
    int i;
    for(i = 0;i < n; i++){

        soma += N[i];

    }
    float m = 0;
    m = soma / n;

    return m;
}


//((valores - media)² ) / n
float var(int n, float * N){
    float med2;
    med2 = media(n,N);
    float soma2 = 0;
    int i;
    for(i = 0;i < n;i++){
        soma2 += (N[i] - med2)*(N[i] - med2);
    }
    float v;
    v = soma2 / n ;

    return v ;
}

int main (){

    int n;

    printf("QUANTOS NUMERO ?\n");
    scanf(" %d",&n);

    float N[n];

    int i;
    for(i = 0;i < n; i++){
        printf("digite os %d numero\n",(i+1));
        scanf(" %f",&N[i]);
    }

    float med = media(n,N);
    printf("MEDIA : %.2f\n",med);

    float va = var(n,N);
    printf("VARIAÇÃO PADRÃO : %.2f\n",va);

    char letra ;
    printf("digite um digito :\n");
    scanf(" %c",&letra);

    int eh = eh_maiusculo(letra);
    printf("EH MAIUSCULO ? %d\n",eh);




    return 0;
}
