/*
Owner   : Ghani Rafif (ghani@ekickx.codes)
Repo    : https://github.com/ekickx/pemrograman-lanjut/tree/master/Tugas-2
License : This code is licensied under MIT LICENSE
*/

#include <stdio.h>
#include <string.h>

struct _book_info{
  char title[200];
  char author[100];
  char artist[100];
  float rating;
};
typedef struct _book_info _bi;

/* Fungsi untuk membersihkan buffer, */
/* agar proses entri dapat dilakukan dengan benar */
void clear_buffer(){
  char ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

/* Membaca value struct menggunakan pointer */
/* (pass-by-reference) */
void input_data(_bi *input){
  /* %[^\n] means input until \n */
  printf("Judul:");
  scanf("%[^\n]", input->title);
  clear_buffer();

  printf("Author:");
  scanf("%[^\n]", input->author);
  clear_buffer();

  printf("Artist:");
  scanf("%[^\n]", input->artist);
  clear_buffer();

  printf("Rating:");
  scanf("%f", &input->rating);
  clear_buffer();
}

/* Karena fungsi tidak mengubah nilai, */
/* hanya menampilkan, */
/* maka menggunakan metode pass-by-value */
void print_data(_bi input){
  printf("%-46s %-13s %-11s %.1f/5\n", input.title, input.author, input.artist, input.rating);
}

void recommend(){
  FILE *f;
  f = fopen("novel.dat", "w");

  _bi recommendation[99];

  strcpy(recommendation[0].title, "Deathbound Duke's Daughter and Seven Noblemen");
  strcpy(recommendation[0].author, "Terasu Senoo");
  strcpy(recommendation[0].artist, "Munashichi");
  recommendation[0].rating = 4.6;

  strcpy(recommendation[1].title, "I Favor the Villainess");
  strcpy(recommendation[1].author, "Inori");
  strcpy(recommendation[1].artist, "Hanagata");
  recommendation[1].rating = 4.4;  

  fwrite(recommendation, sizeof(recommendation), 1, f);
  printf("Rekomendasi berhasil ditambahkan ke daftar novel!\n\n");
}

int main(){
  /* Inisialisasi file yang akan dibaca */
  FILE *f;
  f = fopen("novel.dat", "r");

  /* Inisialisasi variable */
  _bi novel[99];
  char choice;
  int amount;
  int last_index = 0;

  /* Jika file tidak ada, akan direkomendasikan daftar novel */
  if(f == NULL){
    printf("Daftar novel tidak ada!\n");
    printf("Maukah direkomendasikan daftar novel?(y/n)");
    scanf("%s", &choice);
    
    /* Setelah memanggil fungsi recommend, */
    /* membaca kembali novel.dat dengan fopen*/
    /* karena file sudah berubah */
    if(choice == 'y'){recommend();}
    f = fopen("novel.dat", "r");
  }

  printf("Apa yang ingin anda lakukan?\n");
  printf("A) Melihat daftar novel\n");
  printf("B) Menambah daftar novel\n"); 
  scanf("%s", &choice);

  switch(choice){
    case 'A':
      /* Jangan meload file jika tidak ada */
      if(f != NULL){
        fread(novel, sizeof(novel), 1, f);
        fclose(f);
      }
      
      printf("%s %-46s %-13s %-11s %s\n", 
          "No", "Judul", "Author", "Artist", "Rating");
        
      /* Melakukan perulangan untuk membaca isi novel.dat */ 
      for (int i = 0; i < 99; i++){
        /* Akan menghentikan perulangan */
        /* pada element array struct yang kosong */
        if(novel[i].rating == 0){break;}
        printf("%d. ", i+1);
        print_data(novel[i]);
      }
      
      break;
    case 'B':
      /* Jangan meload file jika tidak ada */
      if(f != NULL){
        fread(novel, sizeof(novel), 1, f);
        fclose(f);
      }
      
      /* Mendeteksi index terakhir array */
      /* (agar bisa diappend) */
      for (int i = 0; i < 99; i++){
        if(novel[i].rating == 0){
          last_index = i;
          break;
        }
      }
      
      printf("Jumlah novel yang ingin di-inputkan: ");
      scanf("%d", &amount);
      clear_buffer();
      
      /* Mulai menginput dari index terakhir array */
      /* (Append) */
      for (int i = 0; i < amount; i++){
        printf("Buku ke-%d\n", i+1);
        input_data(&novel[last_index+i]);
      }
      
      /* Menulis array struct ke novel.dat */
      f = fopen("novel.dat", "w");
      fwrite(novel, sizeof(novel), 1, f);
      fclose(f);
      
      break;
    default:
      printf("Pilihan tidak ada");
  }

  return 0;
}
