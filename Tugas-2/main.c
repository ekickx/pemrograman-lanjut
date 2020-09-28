#include <stdio.h>
#include <string.h>

struct recommendation {
  char title[150];
  char author[100];
  char artist[100];
  float rating;
};

int main(){
  /* Init struct */
  struct recommendation novel[3];

  strcpy(novel[0].title, "Deathbound Duke's Daughter and Seven Noblemen");
  strcpy(novel[0].author, "Terasu Senoo");
  strcpy(novel[0].artist, "Munashichi");
  novel[0].rating = 4.6;
  
  strcpy(novel[1].title, "I Favor the Villainess");
  strcpy(novel[1].author, "Inori");
  strcpy(novel[1].artist, "Hanagata");
  novel[1].rating = 4.4;

  strcpy(novel[2].title, "The World of Otome Games is Tough For Mobs");
  strcpy(novel[2].author, "Mishima Yomu");
  strcpy(novel[2].artist, "Monda");
  novel[2].rating = 4.2;

  /* Print Ouput */
  printf("%-15s Rekomendasi Novel bertema Otomege/Villainess\n\n", " ");
  printf("%s %-46s %-13s %-11s %s\n", \
    "No", "Judul", "Author", "Artist", "Rating");

  for (int i = 0; i < 3; i++){
    printf("%d. %-46s %-13s %-11s %.1f/5\n", \
      i+1, novel[i].title, novel[i].author, novel[i].artist, novel[i].rating);
  }
}
