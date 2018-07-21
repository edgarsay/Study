#include <stdio.h>
#include <ctype.h>

int main() {

  int c;

  FILE * EN = fopen("entrada.txt","rt");
  FILE * SA = fopen("saida.txt","wt");

  while((c = fgetc(EN)) != EOF){
    fputc(toupper(c),SA);
}
  fclose(EN);
  fclose(SA);

  return 0;
}
