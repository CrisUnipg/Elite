#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  system("clear");

  int k; //chiave k del cifrario di sostituzione
  char stringa[256]; // frase inserita da tastiera ancora da criptare
  char frasecriptata[256]; //frase criptata mediante il cifrario di Cesare
  char alfabetomescolato[26]; //l'utente decide con quale codice cifrare la frase da lui inserita
  int scelta; //valore di scelta fra cifrario di Cesare e cifrario a sostituzione

  printf("Inserisci la frase che vuoi cifrare:\n");
  fgets(stringa, sizeof(stringa), stdin);
  /*fgets legge caratteri dallo stardard input e li memorizza nel suo primo argomento
  (un array di char)*/
  system("clear");

  printf("Per utilizzare il cifrario di Cesare premere il tasto 1\n");
  printf("Per utilizzare il cifrario a sostituzione premere il tasto 2\n");
  scanf("%d", &scelta);

  if(scelta == 1) {

    system("clear");
    printf("Inserisci il valore della chiave k:\n");
    scanf("%d", &k);

    for (size_t i = 0; i < strlen(stringa) - 1; i++) {
      if(stringa[i] >= 97 && stringa[i] <= 122){
        frasecriptata[i] = 97 + (((stringa[i] % 97) + k % 25) % 25);
      } else {
        frasecriptata[i] = stringa[i];
      }
    }

    frasecriptata[strlen(stringa)-1] = '\0';
    printf("La frase inserita criptata con il cifrario di Cesare è: %s\n", frasecriptata);
  }

  if(scelta == 2){
    system("clear");
    printf("Inserisci il tuo alfabeto mescolato:\n");

    for (size_t i = 0; i < 26; i++) {
      scanf("%c", &alfabetomescolato);
    }
  }
}
