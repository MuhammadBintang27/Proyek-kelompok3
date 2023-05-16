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
  
    char user[n], pass[n], pemisah[2] = "@", akun[N];
    char *token, username[n], password[n];
    int ctrl = 0;

    //membaca file binari login.bin untuk username & password
    FILE *fp;
    if((fp = fopen("database/login.bin", "rb")) == NULL)
    {
        printf("Error opening file %s\n", "database/login.bin");
        return EXIT_FAILURE;
    }

    fread(user, sizeof(char), sizeof(user)/sizeof(char), fp);
    fread(pemisah, sizeof(char), sizeof(pemisah)/sizeof(char), fp);
    fread(pass, sizeof(char), sizeof(pass)/sizeof(char), fp);
    strcpy(akun, user);
    strcat(akun, pemisah);
    strcat(akun, pass);

    token = strtok(akun, "@");
    strcpy(username, token);
    token = strtok(NULL, "@");
    strcpy(password, token);
    
    //pengecekan kesamaan username dan password inputan dengan akun yang ada
    if(strcmp(usernameinput, username) == 0 && (strcmp(passwordinput, password) == 0))
    {
        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LOGIN BERHASIL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    } 
    else
    {
        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LOGIN GAGAL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("--------------------------- PASSWORD ATAU USERNAME SALAH ---------------------------\n");
        return EXIT_FAILURE;
    }

    fclose(fp);

return 0;
}
