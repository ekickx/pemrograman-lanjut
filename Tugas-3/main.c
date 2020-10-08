/*
 * NPM: 19081010110
 * Nama: Ghani Rafif Irawan
 * Repo: https://github.com/ekickx/pemrograman-lanjut/blob/master/Tugas-3
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
  char npm[12];
  char name[30];
  char major[20];
  char phone[20];
  char address[35];
  int age;
  int semester;
} data;

/* Fungsi untuk membersihkan buffer, */
/* agar proses entri dapat dilakukan dengan benar */
void clear_buffer(){
  char ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

/* Karena fungsi tidak mengubah nilai, */
/* hanya menampilkan, */
/* maka menggunakan metode pass-by-value */
void print_data(data input){
  printf("%-13s|%-31s|%-21s|%d    |%-21s|%-36s|%d   |\n",
    input.npm, input.name, input.major,
    input.semester, input.phone,
    input.address, input.age);
}

/* Membaca value struct menggunakan pointer */
/* (pass-by-reference) */
void input_data(data *input){
  printf("NPM:");
  scanf("%[^\n]", input->npm);
  clear_buffer();

  printf("Nama:");
  scanf("%[^\n]", input->name);
  clear_buffer();

  printf("Jurusan:");
  scanf("%[^\n]", input->major);
  clear_buffer();

  printf("Semester:");
  scanf("%d", &input->semester);
  clear_buffer();

  printf("Nomor Telephone:");
  scanf("%[^\n]", input->phone);
  clear_buffer();

  printf("Alamat:");
  scanf("%[^\n]", input->address);
  clear_buffer();

  printf("Umur:");
  scanf("%d", &input->age);
  clear_buffer();
}

int main(){
  int choice; /* penampung pilihan */
  int size = 99; /* panjang array */
  data mahasiswa[size]; /* array mahasiswa */

start:
  printf("\nPilih yang ingin anda lakukan:\n");
  printf("1) Melihat data mahasiswa\n");
  printf("2) Mengedit data\n");
  printf("3) Menambah data baru\n");
  printf("4) Menghapus data\n");
  printf("5) Keluar\n");
  
  /* Baca inputan untuk var choice */
  scanf("%d", &choice);
  clear_buffer();

  if(choice == 1){ /* Melihat data */
    system("clear");

    printf("|No |%-13s|%-31s|%-21s|%s |%-21s|%-36s|%s |\n",
      "NPM", "Nama", "Jurusan", "Smt.",
      "No. Telephone", "Alamat", "Umur");

    for (int i = 0; i < size; i++){
      /* Akan menghentikan perulangan */
      /* pada element array struct yang kosong */
      if(mahasiswa[i].semester == 0){break;}

      printf("|%d  |", i+1);
      print_data(mahasiswa[i]);
    } 
  }else if(choice == 2){ /* Mengedit data */
    system("clear");
    printf("Piliha nomor data yang ingin anda edit:");
    scanf("%d", &choice); 
    clear_buffer();

    input_data(&mahasiswa[choice-1]);
  }else if(choice == 3){ /* Menambah data */
    system("clear");
    int amount; /* Penampung banyaknya data baru */
    int last_index; /* Penampung nilai index terakhir array */
    printf("Masukan jumlah data yang ingin anda tambahkan:");
    scanf("%d", &amount);
    clear_buffer();

    /* Mendeteksi index terakhir array */
    /* (agar bisa diappend) */
    for (int i = 0; i < size; i++){
      if(mahasiswa[i].semester == 0){
        last_index = i;
        break;
      }
    }

    /* Append data */
    for (int i = 0; i < amount; i++){
      printf("\n# Data ke-%d\n", i+1);
      input_data(&mahasiswa[last_index+i]);
    }
  }else if(choice == 4){ /*Menghapus data */
    printf("Masukan data yang ingin anda hapus:");
    scanf("%d", &choice);
    clear_buffer();

    /* Mengganti data array dengan array di depannya */
    for(int i = choice-1; i < size; i++){
      strcpy(mahasiswa[i].npm,mahasiswa[i+1].npm); 
      strcpy(mahasiswa[i].name,mahasiswa[i+1].name);
      strcpy(mahasiswa[i].major,mahasiswa[i+1].major);
      strcpy(mahasiswa[i].phone,mahasiswa[i+1].phone);
      strcpy(mahasiswa[i].address,mahasiswa[i+1].address);
      mahasiswa[i].age = mahasiswa[i+1].age;
      mahasiswa[i].semester = mahasiswa[i+1].semester;

      /* Menghentikan perulangan saat ada semester 0 */
      /* Semester 0 = array kosong */
      for (int i = 0; i < size; i++){
        if(mahasiswa[i].semester == 0){break;}}
}
  }else if(choice == 5){ /* Keluar */
    exit(0);
  }else{
    printf("Inputan yang anda masukkan tidak ada\n");
    system("clear");
  }
  goto start;
}
