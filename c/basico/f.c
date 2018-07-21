#include <stdio.h>
#include <string.h>

int main(){

  char c;
  float v1, v2;
  FILE* fp = fopen("entrada.txt","rt");
  char linha[121];


  while(fgets(linha,121,fp)){
    int n = sscanf(linha,"%c %f %f",&c,&v1,&v2);
    if(n > 0){
      switch (c) {
        case '#':
            printf("COMENTARIO!\n");
          break;
        case 'r':
          if(n != 3){
            printf("ERRO NO FORMAATO DO ARQUIVO!\n");
          }else{
            printf("RETANGULO!\n");
            float base = v1;
            float altura = v2;
            float area = v1 * v2;
            printf("base: %.2f\naltura: %.2f\nAREA: %.2f\n",v1,v2,area);
          }
          break;
        case 't':
          if(n != 3){
            printf("ERRO NO FORMATO DO ARQUIVO!\n");
          }else{
            float base = v1;
            float altura = v2;
            printf("TRIANGULO!\n");
            float area = (v1 * v2) / 2;
            printf("base: %.2f\naltura: %.2f\nAREA: %.2f\n",v1,v2,area);
          }
          break;
        case 'c':
          if (n != 2){
            printf("ERRO NO FORMATO DO ARQUIVO!\n");
          }else{
            float raio = v1;
            float area = 3.14 * (v1*v1);
            printf("CIRCULAO!\n");
            printf("RAIO: %.2f\nAREA:%.2f\n",v1,area);
          }
          break;
        default:
          printf("ERRO NO FORMATO DO ARQUIVO!\n");
          break;
      }

    }
  }

  return 0 ;
}
