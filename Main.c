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
void soal1(int *skor)
{
    char jawaban[2];
    printf("1. Rumus kimia air adalah?\n");
    printf("A. O2 \n");
    printf("B. H2O \n");
    printf("C. CO2 \n");
    printf("D. H3O \n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'B')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal2(int *skor)
{
    char jawaban[2];
    printf("2. Siapa penemu lampu pijar ?\n");
    printf("A. Alessandro Cruto \n");
    printf("B. Thomas Alva Edison \n");
    printf("C. Nikola Tesla \n");
    printf("D. Galileo Galilei\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'B')
    {
        printf("JAWABAN BENAR!\n");
        skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal3(intskor)
{
    char jawaban[2];
    printf("3. Apa nama ibukota Australia ? \n");
    printf("A. Perth \n");
    printf("B. Sydney \n");
    printf("C. Canberra \n");
    printf("D. Ankara \n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'C')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal4(int *skor)
{
    char jawaban[2];
    printf("4.Siapakah pemenang SEA GAMES sepak bola tahun 2023 yang diadakan di kamboja\n");
    printf("A.Filipina \n");
    printf("B.Myanmar \n");
    printf("C.Thailand \n");
    printf("D.Indonesia \n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'D')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal5(int *skor)
{
    char jawaban[2];
    printf("5.Siapkah ketua PDIP Umum?\n");
    printf("A.Megawati\n");
    printf("B.Puan Maharani\n");
    printf("C.Bung Rocky\n");
    printf("D.Ruhud Sitompul\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'A')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal6(int *skor)
{
    char jawaban[2];
    printf("6.siapakah presiden indonesia ke-3\n");
    printf("A.Anies baswedan\n");
    printf("B.Soeharto\n");
    printf("C.Bj.Habibie\n");
    printf("D.Puan Maharani\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'C')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal7(int *skor)
{
    char jawaban[2];
    printf("7. Apabila nilai x=7 dan y=3, berapakah nilai X^2 + xy - 3y =\n");
    printf("A.61 \n");
    printf("B.49\n");
    printf("C.57\n");
    printf("D.65\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'A')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}
void soal8(int *skor)
{
    char jawaban[2];
    printf("8. Dimanakah letak Mesjid Baiturrahman yang masih kokoh setelah tsunami?\n");
    printf("A.Bandung\n");
    printf("B.Jakarta\n");
    printf("C.Aceh\n");
    printf("D.Palu\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'C')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal9(int *skor)
{
    char jawaban[2];
    printf("9. Dimana letak ibu kota dari Sumatra Utara?\n");
    printf("A.Aceh\n");
    printf("B.Jambi\n");
    printf("C.Riau\n");
    printf("D.Medan\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'D')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}

void soal10(int *skor)
{
    char jawaban[2];
    printf("10. Tanggal berapa proklamasi kemerdekaan diumumkan?\n");
    printf("A.17 Agustus\n");
    printf("B.19 Agustus\n");
    printf("C.30 April\n");
    printf("D.16 Mei\n");
    printf("Jawab: ");
    scanf("%s", jawaban);
    if(jawaban[0] == 'A')
    {
        printf("JAWABAN BENAR!\n");
        *skor += 1;
    }else
    {
        printf("jawaban salah!\n");
    }
}
return 0;
}
