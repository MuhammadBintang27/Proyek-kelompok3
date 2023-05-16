#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20
#define N 40

int main (int argc, char *argv[])
{
  //memeriksa kebenaran format login dan melakukan registrasi
  char usernameinput[n], passwordinput[n];
  if(argc != 3)
  {
    printf("\n=================================== GAGAL LOGIN ===================================\n");
    printf("Cara Login : \"(./Nama_File_Utama)(spasi)(Username)(spasi)(password)\"\n\n");

    printf("Silahkan Registrasi Terlebih Dahulu \n");

    FILE *fp = fopen("database/login.bin", "wb");
    char username[n], password[n], pemisah[2] = "@";
    
    printf("\n************************************REGISTRASI**************************************\n");
    printf("Masukkan username dan password akun anda(max 20 character)(berupa huruf dan angka)\n");
    
    printf("Username: ");
    scanf("%s", username);
    
    printf("Password: ");
    scanf("%s", password);

    fwrite(username, sizeof(char), sizeof(username)/sizeof(char), fp);
    fwrite(pemisah, sizeof(char), sizeof(pemisah)/sizeof(char), fp);
    fwrite(password, sizeof(char), sizeof(password)/sizeof(char), fp);

     fclose(fp);
    }

    strcpy(usernameinput, argv[1]);
    strcpy(passwordinput, argv[2]);
  

return 0;
}
