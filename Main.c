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
  
    printf("Selamat datang di Permainan \"SIAPA YANG MAU JADI MILIADER\"\n");
    printf("Cara bermain: \n");
    printf("1. Disediakan 10 Pertanyaan umum\n");
    printf("2. Setiap pertanyaan memiliki 4 pilihan ganda\n");
    printf("3. Setiap pertanyaan benar akan menaikan hadiahnya\n");
    printf("4. Anda bisa BERHENTI dengan membawa hadiah yang sudah didapat atau LANJUT dengan risiko hadiah tersebut HANGUS\n");
    printf("5. TOTAL HADIAH yang bisa didapatkan adalah Rp.1.000.000.000,00!\n\n");
    
    int mulai;
    while(mulai < 1 || mulai > 2)
    {
        printf("PILIHAN\n");
        printf("1 = MULAI\n");
        printf("2 = KELUAR\n");
        printf("MULAI/KELUAR:");
        scanf("%d", &mulai);

        if(mulai < 1 || mulai > 2)
        {printf("tolong pilih dengan benar");}

        if(mulai == 1)
        {
            int skor=0;
            
            printf("\n");
            soal1(&skor);
            hadiah(&skor);

            printf("skor = %d", skor);
            printf("\n");
            soal2(&skor);
            hadiah(&skor);

            printf("\n");
            soal3(&skor);
            hadiah(&skor);

            printf("\n");
            soal4(&skor);
            hadiah(&skor);

            printf("\n");
            soal5(&skor);
            hadiah(&skor);

            printf("\n");
            soal6(&skor);
            hadiah(&skor);

            printf("\n");
            soal7(&skor);
            hadiah(&skor);

            printf("\n");
            soal8(&skor);
            hadiah(&skor);

            printf("\n");
            soal9(&skor);
            hadiah(&skor);

            printf("\n");
            soal10(&skor);
            hadiah(&skor);
        

        }
    }
    
}

return 0;
}
