#include <stdio.h>
#include <string.h>

int main(){

  int achou = 0;

  char linha[121]="cumendo";
  char sub[121];
  FILE * EN = fopen("entrada.txt","rt");

  while(fgets(linha,121,EN) != NULL){
    if(strstr(linha,sub)){
      achou = 1;
      break;
    }
  }
  fclose(EN);
  if(achou){
    printf("%s\n",linha);
  }else{
    printf("NENHUMA OCORRÊNCIA.\n");
  }

  return 0;
}
