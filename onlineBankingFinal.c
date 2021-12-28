//Library
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
//End Library

//Deklarasi Struct
struct user
{
    char telp[15], nama[50], ktp[25], password[15];
    float saldo;
};
struct user usr, usr1;

struct transfer
{
    float samaBank, antarBank;
};
struct transfer tf;

struct listrik
{
    float token, meter;
};
struct listrik lstrk;
//End Deklarasi Struct

//Variabel Pendukung
int noMeter, kodeBank, h = 0, i = 0;
char filename[50], nama[50], telp[15], pass[15], newPass[15], ktp[20];
char pilih, yakin, k, opt;
float jml_deposit, jml_tarik, jml_tf;
float pulsa, listrik, nominal;
time_t ambil_waktu;
FILE *fp; //Pointer
//End Variabel Pendukung

//Header Fungsi
void menuAwal();
void menuDaftar();
void menuMasuk();
void lupaPass();
void mainMenu();
void menuDeposit();
void menuPenarikan();
void menuTransfer();
void pembayaranOnline();
void bayarListrik();
void bayarPulsa();
void bayarAir();
void gantiPass();
void struk();
void setColor(unsigned short);
//End Header Fungsi

//Fungsi Main
int main()
{
    system("cls");
    menuAwal();
}
//End Fungsi Main

//Fungsi Menu Awal, Masuk atau Daftar
void menuAwal(void)
{
    setColor(15);
    printf("AdP - KELOMPOK 1");
    printf("\n\nMenu Pilihan");
    printf("\n\n1. Daftar");
    printf("\n2. Masuk");
    printf("\n0. Lupa Password");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);

    if (pilih == 1)
    {
        system("cls");
        menuDaftar(); //Memanngil Fungsi Menu Daftar
    }
    else if (pilih == 2)
    {
        system("cls");
        menuMasuk(); //Memanggil Fungsi Menu Masuk
    }
    else
    {
        printf("Invalid. Mohon Masukkan Ulang");
        getch();
        menuAwal();
    }
}

//Fungsi Lupa Password
void lupaPass()
{
    ktp:
    printf("\nMasukkan No. KTP Anda: ");
    scanf("%s", &ktp);

    strcpy(filename, telp);
    fp = fopen(strcat(filename, ".dat"), "r");

    if (strcmp(ktp, usr.ktp))
    {
        printf("\nNo. KTP Tidak Terdaftar");
        getch();
        system("cls");
        goto ktp;
    }
    else
    {
        if (!strcmp(ktp, usr.ktp))
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            printf("\nMasukkan Password Baru Anda: ");
            scanf("%s", newPass);

            fp = fopen(filename, "w");
            strcpy(usr.password, newPass);
            fwrite(&usr, sizeof(struct user), 1, fp);
            if (fwrite != NULL)
                printf("\nPassword Berhasil Diganti");
            fclose(fp);
            system("cls");
            menuAwal();
        }
        else
        {
            printf("\nKesalahan Terjadi. Mohon Coba Lagi\n");
            getch();
            menuAwal();
            system("cls");
        }
    }
}
//End Fungsi Lupa Password

void menuDaftar() //Fungsi Untuk Pendaftaran Akun Baru Bagi User
{   
    printf("Menu Registrasi\n\n");
    printf("Masukkan Nama Anda          : ");
    scanf("%49s", usr.nama);
    printf("Masukkan No. Telpon Anda    : ");
    scanf("%s", usr.telp);
    printf("Masukkan No. KTP Anda       : ");
    scanf("%s", usr.ktp);
    printf("Masukkan Password Anda      : ");
    scanf("%s", usr.password);
    usr.saldo = 50000;

    printf("\nNama          : %s\nNo. Telpon    : %s\nNo. KTP       : %s", usr.nama, usr.telp, usr.ktp);
    printf("\nApakah Data Diatas Sudah Benar?");
    printf("\n(y/n): ");
    scanf("%s", &yakin);
    
    if (yakin == 'y'||yakin == 'Y')
    {
        strcpy(filename, usr.telp); //Penamaan File Berdasarkan No. Telpon Yang Telah Diinput
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp); //Penulisan Data Yang Telah Diinput Dalam Format File ".dat"
        if (fwrite != 0)
        {
            printf("\nAkun Berhasil Terdaftar. Silahkan Gunakan Untuk Masuk");
            printf("\n\nTekan ENTER Untuk Melanjutkan");
            getch();
            system("cls");
            menuAwal();
        }
        else
        {
            printf("Kesalahan Terjadi, Mohon Coba Lagi\n");
            system("pause");
            system("cls");
            menuAwal();
        }
        fclose(fp);
    }
    else
    {
        menuDaftar();
        system("cls");
    }
}

//Fungsi Menu Masuk
void menuMasuk()
{
    printf("Masukkan No. Telpon Anda: ");
    scanf("%s", telp);
    printf("Masukkan Password Anda: ");
    scanf("%s", pass);

    strcpy(filename, telp);
    fp = fopen(strcat(filename, ".dat"), "r");
    if (fp == NULL)
    {
        printf("\nAkun Tidak Ada, Pastikan Anda Sudah Terdaftar\n");
        system("pause");
        system("cls");
        menuAwal();
    }
    else
    {
        fread(&usr, sizeof(struct user), 1, fp);
        fclose(fp);

        if (!strcmp(pass, usr.password))
        {
            do //Dilakukan Perulangan Pada Fungsi Main Menu Selama Nilai 'k' Sama Dengan 0
            {
                mainMenu(); //Pemanggilan Fungsi Main Menu
                printf("\n\nIngin Melakukan Transaksi Lainnya?");
                printf("\nMasukkan Pilihan (y/n): ");
                scanf("%s", &opt);
                if (opt == 'n' || opt == 'N')
                {
                    if (h > 0)
                    {
                    k = 1;
                    }
                    else
                    {
                        system("cls");
                        printf("Terima Kasih\n");
                        printf("\nAnda Telah Keluar");
                        exit(EXIT_SUCCESS);
                    }
                }
            } while (k != 1);
            system("cls");
            struk();
        }
        else
        {
            while (i < 2)
            {
                printf("\nPassword Invalid, Mohon Coba Lagi\n");
                i += 1;
                system("pause");
                system("cls");
                menuAwal();
            }
            system("cls");
            printf("Anda Telah 3x Salah Memasukkan Password\n");
            printf("\n1. Lupa Password?");
            printf("\n2. Keluar");
            printf("\n\nMasukkan Pilihan: ");
            scanf("%d", &pilih);
            
            switch (pilih)
            {
                case 1:
                    lupaPass();
                    break;

                case 2:
                    exit(EXIT_SUCCESS);
                    break;
                
                default:
                    printf("Invalid. Mohon Masukkan Ulang");
            }
        }
    }
}
//End Fungsi Menu Masuk

//Fungsi Main Menu
void mainMenu()
{
    system("cls");
    printf("Selamat Datang Sdr/(i) %s", usr.nama);
    printf("\n\n1. Cek Saldo");
    printf("\n2. Deposit");
    printf("\n3. Tarik Tunai");
    printf("\n4. Transfer Online");
    printf("\n5. Pembayaran Online");
    printf("\n6. Ganti Password");
    printf("\n0. Keluar");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);
    system("cls");

    //Switch Case Pilihan Berdasarkan Nomor
    switch (pilih)
    {
    case 1:
        printf("Saldo Anda: Rp %.2f", usr.saldo);
        break;

    case 2:
        menuDeposit();
        break;

    case 3:
        menuPenarikan();
        break;

    case 4:
        menuTransfer();
        break;

    case 5:
        pembayaranOnline();
        break;

    case 6:
        gantiPass();
        break;

    case 00:
        printf("\nYakin Ingin Keluar?");
        printf("\nMasukkan Pilihan (y/n): ");
        scanf("%s", &yakin);
        if (yakin == 'y' || yakin == 'Y')
        {
            if (i > 0)
            {
            printf("\nTekan ENTER Untuk Melihat Struk Transaksi");
            getch();
            system("cls");
            struk();
            }
            else
            {
                printf("\nTerima Kasih");
                exit(EXIT_SUCCESS);
            }
        }
        break;

    default:
        printf("Pilihan Tidak Ada");
        break;
    } //End Switch Case
}
//End Fungsi Main Menu

//Mengatur Warna Tulisan
void setColor(unsigned short color)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}
//End Mengatur Warna Tulisan

// Fungsi Deposit
void menuDeposit()
{
menuDeposit:
    printf("MENU DEPOSIT\n");
    printf("\n1. Rp 50.000      4. Rp 200.000");
    printf("\n2. Rp 100.000     5. Rp 500.000");
    printf("\n3. Lainnya        6. Kembali");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
        case 1:
            printf("\nAnda Akan Melakukan Deposit Sebesar Rp 50.000");
            printf("\nLanjutkan? (y/n): ");
            scanf("%s", &yakin);

            if (yakin == 'y'||yakin == 'Y')
            {
                fp = fopen(filename, "w");
                usr.saldo += 50000;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);

                printf("\nDeposit Berhasil! Saldo Anda: Rp %.2f", usr.saldo);
                h += 1;
            }
            else
            {
                mainMenu();
            }
            break;

        case 2:
            printf("\nAnda Akan Melakukan Deposit Sebesar Rp 100.000");
            printf("\nLanjutkan? (y/n): ");
            scanf("%s", &yakin);

            if (yakin == 'y' || yakin == 'Y')
            {
                fp = fopen(filename, "w");
                usr.saldo += 100000;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);

                printf("\nDeposit Berhasil! Saldo Anda: Rp %.2f", usr.saldo);
                h += 1;
            }
            else
            {
                mainMenu();
            }
            break;

        case 3:
            printf("\nMasukkan Nominal Deposit: ");
            scanf("%f", &jml_deposit);

            if (!fmod(jml_deposit, 50000))
            {
                if (jml_deposit <= 0 || jml_deposit >= 1000000000)
                {
                    printf("Nominal Tidak Valid, Mohon Masukkan Ulang\n");
                    getch();
                    system("cls");
                    goto menuDeposit;
                }
                else
                {
                    fp = fopen(filename, "w");
                    usr.saldo += jml_deposit;
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    if (fwrite != NULL)
                        printf("Deposit Berhasil! Total Saldo Anda Sekarang: Rp %.2f", usr.saldo);
                    fclose(fp);
                    h += 1;
                }
            }
            else
            {
                printf("\nMasukkan Nominal Dalam Kelipatan: Rp 50.000\n");
                system("pause");
                system("cls");
                goto menuDeposit;
            }

        case 4:
            printf("\nAnda Akan Melakukan Deposit Sebesar Rp 200.000");
            printf("\nLanjutkan? (y/n): ");
            scanf("%s", &yakin);

            if (yakin == 'y' || yakin == 'Y')
            {
                fp = fopen(filename, "w");
                usr.saldo += 200000;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);

                printf("\nDeposit Berhasil! Saldo Anda: Rp %.2f", usr.saldo);
                h += 1;
            }
            else
            {
                mainMenu();
            }
            break;

        case 5:
            printf("\nAnda Akan Melakukan Deposit Sebesar Rp 500.000");
            printf("\nLanjutkan? (y/n): ");
            scanf("%s", &yakin);

            if (yakin == 'y' || yakin == 'Y')
            {
                fp = fopen(filename, "w");
                usr.saldo += 500000;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);

                printf("\nDeposit Berhasil! Saldo Anda: Rp %.2f", usr.saldo);
                h += 1;
            }
            else
            {
                mainMenu();
            }
            break;

        case 6:
            mainMenu();
            break;

        default:
            printf("Pilihan Tidak Ada. Mohon Masukkan Ulang");
            getch();
    }
}
//End Fungsi Deposit

//Fungsi Penarikan
void menuPenarikan()
{
    tarik:
    printf("TARIK TUNAI\n");
    printf("\n1. 50.000         4. 300.000");
    printf("\n2. 100.000        5. 500.000");
    printf("\n3. Lainnya        0. Kembali");
    printf("\n\nMasukkan Pilihan (1/2/3/4/5/0): ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        if (usr.saldo <= 50000)
        {
            printf("\nSaldo Anda Tidak Mencukupi");
        }
        else
        {
            printf("\nAnda Akan Melakukan Penarikan Sebesar Rp 50.000");
            printf("\nLanjutkan? (y/n): ");
            scanf("%s", &yakin);
            
            if (yakin == 'y'||yakin == 'Y')
            {
            fp = fopen(filename, "w");
            usr.saldo -= 50000;
            fwrite(&usr, sizeof(struct user), 1, fp);
            fclose(fp);

            printf("\nPenarikan Sebesar Rp 50.000 Berhasil. Sisa Saldo Anda: %.2f", usr.saldo);
            h += 1;
            }
            else
            {
                mainMenu();
            }
        }
        break;

    case 2:
        if (usr.saldo >= 100000)
        {
            printf("\nSaldo Anda Tidak Mencukupi");
        }
        else
        {
            printf("\nAnda Akan Melakukan Penarikan Sebesar Rp 100.000");
            printf("\nLanjutkan? (y/n): ");
            scanf("%s", &yakin);

            if (yakin == 'y' || yakin == 'Y')
            {
                fp = fopen(filename, "w");
                usr.saldo -= 50000;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);

                printf("\nPenarikan Sebesar Rp 100.000 Berhasil. Sisa Saldo Anda: %.2f", usr.saldo);
                h += 1;
            }
            else
            {
                mainMenu();
            }
        }
        break;

    case 3:
    penarikan:
        system("cls");
        printf("TARIK TUNAI");
        printf("\n\nMasukkan Nominal Penarikan: ");
        scanf("%f", &jml_tarik);

        if (!fmod(jml_tarik, 50000))
        {
            if (jml_tarik >= usr.saldo)
            {
                printf("\nSaldo Anda Tidak Mencukupi");
            }
            else
            {
                fp = fopen(strcat(filename, ".dat"), "w");
                usr.saldo -= jml_tarik;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);

                printf("\nPenarikan Berhasil. Saldo Anda Sekarang %.2f", usr.saldo);
                h += 1;
            }
        }
        else
        {
            printf("Masukkan Nominal Dalam Kelipatan Rp 50.000\n\n");
            system("pause");
            goto penarikan;
        }
        break;

    case 4:
        if (300000 >= usr.saldo)
        {
            printf("\nSaldo Anda Tidak Mencukupi");
        }
        else
        {
            strcpy(filename, usr.telp);
            fp = fopen(strcat(filename, ".dat"), "w");
            usr.saldo -= 300000;
            fwrite(&usr, sizeof(struct user), 1, fp);
            fclose(fp);

            printf("\nPenarikan Sebesar Rp 50.000 Berhasil. Sisa Saldo Anda: %.2f", usr.saldo);
            h += 1;
        }
        break;

    case 5:
        if (500000 >= usr.saldo)
        {
            printf("\nSaldo Anda Tidak Mencukupi");
        }
        else
        {
            strcpy(filename, usr.telp);
            fp = fopen(strcat(filename, ".dat"), "w");
            usr.saldo -= 500000;
            fwrite(&usr, sizeof(struct user), 1, fp);
            fclose(fp);

            printf("\nPenarikan Sebesar Rp 50.000 Berhasil. Sisa Saldo Anda: %.2f", usr.saldo);
            h += 1;
        }
        break;

    case 0:
        mainMenu();
        break;

    default:
        printf("Invalid. Mohon Masukkan Ulang");
        getch();
        goto tarik;
    }
}
//End Fungsi Penarikan

//Fungsi Menu Transfer
void menuTransfer()
{
    printf("MENU TARNSFER");
    printf("\n\n1. Sesama Bank      0. Kembali\n2. Bank Lain");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);
    system("cls");

    switch (pilih)
    {
    case 1:
        printf("MENU TRANSFER");
        printf("Transfer Sesama Bank");
        printf("\n\nMasukkan No. Telpon Tujuan: ");
        scanf("%s", telp);

        strcpy(filename, telp);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\nNo. Telpon Tidak Terdaftar\n\n");
        }
        else
        {
            fread(&usr1, sizeof(struct user), 1, fp);
        }
        fclose(fp);

        printf("Masukkan Jumlah Transfer: ");
        scanf("%f", &tf.samaBank);

        if (tf.samaBank > usr.saldo)
            printf("\nSaldo Anda Tidak Cukup Untuk Melakukan Transaksi. Saldo Anda: %.2f", usr.saldo);
        else
        {
            fp = fopen(filename, "w");
            usr1.saldo += tf.samaBank;
            fwrite(&usr1, sizeof(struct user), 1, fp);
            fclose(fp);

            if (fwrite != NULL)
            {
                printf("\nTransaksi Berhasil!");
                printf("\nAnda Telah Melakukan Transfer Sebesar: Rp %.2f Ke No. Telp %s", tf.samaBank, telp);

                strcpy(filename, usr.telp);
                fp = fopen(strcat(filename, ".dat"), "w");
                usr.saldo -= tf.samaBank;
                fwrite(&usr, sizeof(struct user), 1, fp);
                fclose(fp);
            }
        }
        break;

    case 2:
    trk2:
        printf("1. 002 : BRI        4. 014 : BCA        0. Kembali");
        printf("\n2. 009 : BNI        5. 122 : Bank Kalsel");
        printf("\n3. 008 : Mandiri    6. Lainnya");
        printf("\n\nMasukkan Kode Bank Pilihan: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            printf("\n002 : BRI");
            printf("\nMasukkan No. Telpon Tujuan: ");
            scanf("%s", &telp);
            printf("Masukkan Nominal Transfer: ");
            scanf("%f", &tf.antarBank);

            if (tf.antarBank + 3000 > usr.saldo)
            {
                printf("Saldo Anda Tidak Mencukupi Untuk Melakukan Transaksi. Saldo Anda: Rp %.2f\n", usr.saldo);
            }
            else
            {
                printf("\nAnda Akan Melakukan Transaksi Transfer Sebesar %.2f ke No. Telpon %s Dengan Kode Bank 002", tf.antarBank, telp);
                printf("\nTransaksi Akan Dikenakan Biaya Admin Sebesar Rp 3.000");
                printf("\nIngin Melanjutkan Transaksi? (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= (tf.antarBank + 3000);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nTransaksi Berhasil. Sisa Saldo Anda: Rp %.2f", usr.saldo);
                }
                else if (pilih == 'n' | pilih == 'N')
                {
                    printf("Anda Membatalkan Transaksi\n\n");
                    system("pause");
                    mainMenu();
                }
                else
                {
                }
            }
            break;

        case 2:
            printf("\n009 : BNI");
            printf("\nMasukkan No. Telpon Tujuan: ");
            scanf("%s", &telp);
            printf("Masukkan Nominal Transfer: ");
            scanf("%f", &tf.antarBank);

            if (tf.antarBank + 3000 > usr.saldo)
            {
                printf("Saldo Anda Tidak Mencukupi Untuk Melakukan Transaksi. Saldo Anda: Rp %.2f\n", usr.saldo);
            }
            else
            {
                printf("\nAnda Akan Melakukan Transaksi Transfer Sebesar %.2f ke No. Telpon %s Dengan Kode Bank 009", tf.antarBank, telp);
                printf("\nTransaksi Akan Dikenakan Biaya Admin Sebesar Rp 3.000. Ingin Melanjutkan Transaksi?");
                printf("\nMasukkan Pilihan (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    fp = fopen(filename, "w");
                    usr.saldo -= (tf.antarBank + 3000);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nTransaksi Berhasil. Sisa Saldo Anda: Rp %.2f", usr.saldo);
                }
                else if (pilih == 'n' | pilih == 'N')
                {
                    printf("Anda Membatalkan Transaksi\n\n");
                    system("pause");
                    mainMenu();
                }
            }
            break;

        case 3:
            printf("\n008 : Mandiri");
            printf("\nMasukkan No. Telpon Tujuan: ");
            scanf("%s", &telp);
            printf("Masukkan Nominal Transfer: ");
            scanf("%f", &tf.antarBank);

            if (tf.antarBank + 3000 > usr.saldo)
            {
                printf("Saldo Anda Tidak Mencukupi Untuk Melakukan Transaksi. Saldo Anda: Rp %.2f\n", usr.saldo);
            }
            else
            {
                printf("\nAnda Akan Melakukan Transaksi Transfer Sebesar %.2f ke No. Telpon %s Dengan Kode Bank 008", tf.antarBank, telp);
                printf("\nTransaksi Akan Dikenakan Biaya Admin Sebesar Rp 3.000. Ingin Melanjutkan Transaksi?");
                printf("\nMasukkan Pilihan (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    strcpy(filename, usr.telp);
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= (tf.antarBank + 3000);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nTransaksi Berhasil. Sisa Saldo Anda: Rp %.2f", usr.saldo);
                }
                else if (pilih == 'n' | pilih == 'N')
                {
                    printf("Anda Membatalkan Transaksi\n\n");
                    system("pause");
                    mainMenu();
                }
            }
            break;

        case 4:
            printf("\n014 : BCA");
            printf("\nMasukkan No. Telpon Tujuan: ");
            scanf("%s", &telp);
            printf("Masukkan Nominal Transfer: ");
            scanf("%f", &tf.antarBank);

            if (tf.antarBank + 3000 > usr.saldo)
            {
                printf("Saldo Anda Tidak Mencukupi Untuk Melakukan Transaksi. Saldo Anda: Rp %.2f\n", usr.saldo);
            }
            else
            {
                printf("\nAnda Akan Melakukan Transaksi Transfer Sebesar %.2f ke No. Telpon %s Dengan Kode Bank 014", tf.antarBank, telp);
                printf("\nTransaksi Akan Dikenakan Biaya Admin Sebesar Rp 3.000. Ingin Melanjutkan Transaksi?");
                printf("\nMasukkan Pilihan (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    strcpy(filename, usr.telp);
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= (tf.antarBank + 3000);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nTransaksi Berhasil. Sisa Saldo Anda: Rp %.2f", usr.saldo);
                }
                else if (pilih == 'n' | pilih == 'N')
                {
                    printf("Anda Membatalkan Transaksi\n\n");
                    system("pause");
                    mainMenu();
                }
            }
            break;

        case 5:
            printf("\n112 : Bank Kalsel");
            printf("\nMasukkan No. Telpon Tujuan: ");
            scanf("%s", &telp);
            printf("Masukkan Nominal Transfer: ");
            scanf("%f", &tf.antarBank);

            if (tf.antarBank + 3000 > usr.saldo)
            {
                printf("Saldo Anda Tidak Mencukupi Untuk Melakukan Transaksi. Saldo Anda: Rp %.2f\n", usr.saldo);
            }
            else
            {
                printf("\nAnda Akan Melakukan Transaksi Transfer Sebesar %.2f ke No. Telpon %s Dengan Kode Bank 112", tf.antarBank, telp);
                printf("\nTransaksi Akan Dikenakan Biaya Admin Sebesar Rp 3.000. Ingin Melanjutkan Transaksi?");
                printf("\nMasukkan Pilihan (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    strcpy(filename, usr.telp);
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= (tf.antarBank + 3000);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nTransaksi Berhasil. Sisa Saldo Anda: Rp %.2f", usr.saldo);
                    h += 1;
                }
                else if (pilih == 'n' | pilih == 'N')
                {
                    printf("Anda Membatalkan Transaksi\n\n");
                    system("pause");
                    mainMenu();
                }
            }
            break;

        case 6:
            printf("\nMasukkan Kode Bank: ");
            scanf("%d", &kodeBank);
            printf("Masukkan Nominal Transfer: ");
            scanf("%f", &tf.antarBank);

            if (tf.antarBank + 5000 >= usr.saldo)
            {
                printf("\nSaldo Anda Tidak Mencukupi. Saldo Anda: Rp %.2f", usr.saldo);
            }
            else
            {
                printf("\nAnda Akan Melakukan Transfer Sebesar Rp %.2f Dengan Kode Bank %d", jml_tf, kodeBank);
                printf("\nLanjutkan? (y/n): ");
                scanf("%s", &yakin);

                if (yakin == 'y'||yakin == 'Y')
                {
                    fp = fopen(filename, "w");
                    usr.saldo -= (tf.antarBank + 5000);
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nTransaksi Berhasil");
                    h += 1;
                }
                else
                {
                    goto trk2;
                }
            }
            break;

        case 0:
            mainMenu();
            break;

        default:
            printf("\nPilihan Invalid, Mohon Masukkan Ulang");
            getch();
            goto trk2;
            break;
        }
        break;
    
    case 0:
        mainMenu();
        break;

    default:
        printf("\nPilihan Invalid, Mohon Masukkan Ulang");
        getch();
        break;
    }
}
//End Fungsi Menu Transfer

//Fungsi Pembayaran Online
void pembayaranOnline()
{
    pembayaran:
    printf("\nPembayaran Online\n");
    printf("\n1. Pulsa      3. PDAM");
    printf("\n2. Listrik    0. Kembali");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        bayarPulsa();
        break;

    case 2:
        bayarListrik();
        break;

    case 3:
        bayarAir();
        break;

    case 0:
        mainMenu();
        break;

    default:
        printf("Pilihan Tidak Ada, Silakan Masukkan Ulang");
        goto pembayaran;
        break;
    }
}
//End Fungsi Pembayaran Online

//Fungsi Switch Case Pembayaran Online
//Fungsi Bayar Pulsa
void bayarPulsa()
{
bayarPulsa:
    printf("PULSA");
    printf("\n\n1. Rp 10.000      3. Rp 50.000    0. Kembali");
    printf("\n2. Rp 20.000      4. Lainnya");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
        case 1:
            if (usr.saldo <= 10000)
            {
                printf("\nSaldo Anda Tidak Mencukupi. Saldo Anda: Rp %.2f", usr.saldo);
            }
            else
            {
                printf("Masukkan No. Telpon: ");
                scanf("%s", telp);
                system("cls");
                printf("\nAnda Akan Melakukan Pengisian Pulsa Sebesar RP 10.000 ke No. Telpon: %s", telp);
                printf("\nLanjutkan? (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y'||pilih == 'Y')
                {
                    fp = fopen(filename, "w");
                    usr.saldo -= 10000;
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("Transaksi Berhasil!");
                    h += 1;
                }
            }
            break;

        case 2:
            if (usr.saldo <= 20000)
            {
                printf("Saldo Anda Tidak Mencukupi. Saldo Anda: Rp %.2f", usr.saldo);
            }
            else
            {
                printf("Masukkan No. Telpon: ");
                scanf("%d", telp);
                system("cls");
                printf("\nAnda Akan Melakukan Pengisian Pulsa Sebesar RP 10.000 ke No. Telpon: %d", telp);
                printf("\nLanjutkan? (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= 10000;
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("Transaksi Berhasil!");
                    h += 1;
                }
            }
            break;

        case 3:
            if (usr.saldo <= 50000)
            {
                printf("\nSaldo Anda Tidak Mencukupi. Saldo Anda: Rp %.2f", usr.saldo);
            }
            else
            {
                printf("Masukkan No. Telpon: ");
                scanf("%d", telp);
                system("cls");
                printf("\nAnda Akan Melakukan Pengisian Pulsa Sebesar RP 10.000 ke No. Telpon: %d", telp);
                printf("\nLanjutkan? (y/n): ");
                scanf("%s", &pilih);

                if (pilih == 'y' || pilih == 'Y')
                {
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= 10000;
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("Transaksi Berhasil!");
                    h += 1;
                }
            }
            break;

        case 4:
            printf("\nMasukkan Nominal Pulsa: Rp ");
            scanf("%f", &pulsa);

            if (pulsa > usr.saldo)
            {
                printf("\nSaldo Anda Tidak Cukup Untuk Melakukan Transaksi. Saldo Anda Rp %.2f", usr.saldo);
            }
            else
            {
                if (!fmod(pulsa, 5000))
                {
                    bayarPulsa2:
                    printf("Masukkan No. Telpon Tujuan: ");
                    scanf("%s", &telp);

                    strcpy(filename, usr.telp);
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.saldo -= pulsa;
                    fwrite(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    printf("\nAnda Telah Melakukan Pembayaran Pulsa Sebesar: Rp %.2f ke No. Telpon: %s", pulsa, telp);
                    h += 1;
                }
                else
                {
                    printf("\nMasukkan Nominal Dalam Kelipatan Rp. 5000");
                    getch();
                    goto bayarPulsa2;
                }
            }
            break;

        case 0:
            mainMenu();
            break;

        default:
            printf("\nPilihan Tidak Ada. Mohon Masukkan Ulang");
            getch();
            goto bayarPulsa;
    }
}
//End Fungsi Bayar Pulsa

//Fungsi Bayar Listrik
void bayarListrik()
{
    byrListrik:
    printf("LISTRIK");
    printf("\n\n1. Token Listrik");
    printf("\n2. Tagihan Listirk");
    printf("\n0. Kembali");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &pilih);
    system("cls");

    switch (pilih)
    {
        case 1:
            printf("Masukkan ID Pelanggan (No. Telpon): ");
            scanf("%s", telp);

            strcpy(filename, telp);
            fp = fopen(strcat(filename, ".dat"), "r");
            if (fp == NULL)
            {
                printf("\nID Pelanggan Tidak Terdaftar");
            }
            else
            {
                fread(&usr, sizeof(struct user), 1, fp);
                fclose(fp);
                tknListrik:
                printf("\n1. Rp 20.000      4. Rp 50.000");
                printf("\n2. Rp 100.000     5. Rp 200.000");
                printf("\n3. Lainnya        0. Kembali");
                printf("\n\nMasukkan Pilihan: ");
                scanf("%d", &pilih);

                switch (pilih)
                {
                    case 1:
                        if (usr.saldo <= 20000)
                        {
                            printf("\nSaldo Anda Tidak Mencukupi");
                        }
                        else
                        {
                            printf("\nAnda Akan Melakukan Pengisian Token Listrik Sebesar Rp 20.000");
                            printf("\nLanjutkan? (y/n):  ");
                            scanf("%s", &pilih);

                            if (pilih == 'y' || pilih == 'Y')
                            {
                                strcpy(filename, usr.telp);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                usr.saldo -= 20000;
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);

                                srand(time(NULL));
                                int token = 1000 + rand() % 9000;

                                printf("Transaksi Berhasil! Token Pengisian Anda: %d", token);
                                h += 1;
                            }
                            else if (pilih == 'n'||pilih == 'N')
                            {
                                mainMenu();
                            }
                            else
                            {
                                printf("\nInputan Tidak Valid");

                            }
                        }
                        break;

                    case 2:
                        if (usr.saldo <= 100000)
                        {
                            printf("\nSaldo Anda Tidak Mencukupi");
                        }
                        else
                        {
                            printf("\nAnda Akan Melakukan Pengisian Token Listrik Sebesar Rp 100.000");
                            printf("\nLanjutkan? (y/n):  ");
                            scanf("%s", &pilih);

                            if (pilih == 'y' || pilih == 'Y')
                            {
                                strcpy(filename, usr.telp);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                usr.saldo -= 100000;
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);

                                srand(time(NULL));
                                int token = 1000 + rand() % 9000;

                                printf("Transaksi Berhasil! Token Pengisian Anda: %d", token);
                                h += 1;
                            }
                            else if (pilih == 'n' || pilih == 'N')
                            {
                                mainMenu();
                            }
                            else
                            {
                                printf("\nInputan Tidak Valid");
                            }
                        }
                        break;

                    case 3:
                        tokenListrik:
                        printf("\nMasukkan Nominal Pengisian (Kelipatan Rp 50.000): Rp ");
                        scanf("%f", &lstrk.token);
                        
                        if (!fmod(lstrk.token, 50000))
                        {
                            printf("\nAnda Akan Melakukan Pengisian Token Listrik Sebesar Rp %.2f", listrik);
                            printf("\nLanjutkan? (y/n):  ");
                            scanf("%s", &pilih);

                            if (pilih == 'y' || pilih == 'Y')
                            {
                                strcpy(filename, usr.telp);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                usr.saldo -= lstrk.token;
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);

                                srand(time(NULL));  // Fungsi Untuk Menghasilkan Token
                                int token = 1000 + rand() % 9000;

                                printf("Transaksi Berhasil! Token Pengisian Anda: %d", token);
                                h += 1;
                            }
                            else if (pilih == 'n' || pilih == 'N')
                            {
                                mainMenu();
                            }
                            else
                            {
                                printf("\nInputan Tidak Valid, Mohon Masukkan Ulang");
                                goto tokenListrik;
                            }
                        }
                        else
                        {
                            printf("Masukkan Nominal Dalam Kelipatan Rp 50.000");
                            goto tokenListrik;
                        }
                        break;

                    case 4:
                        printf("\nAnda Akan Melakukan Pengisian Token Listrik Sebesar Rp 50.000");
                        printf("\nLanjutkan? (y/n):  ");
                        scanf("%s", &pilih);

                        if (pilih == 'y' || pilih == 'Y')
                        {
                            strcpy(filename, usr.telp);
                            fp = fopen(strcat(filename, ".dat"), "w");
                            usr.saldo -= 50000;
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);

                            srand(time(NULL));
                            int token = 1000 + rand() % 9000;

                            printf("Transaksi Berhasil! Token Pengisian Anda: %d", token);
                            h += 1;
                        }
                        else if (pilih == 'n' || pilih == 'N')
                        {
                            mainMenu();
                        }
                        else
                        {
                            printf("\nInputan Tidak Valid");
                        }
                        break;

                    case 5:
                        printf("\nAnda Akan Melakukan Pengisian Token Listrik Sebesar Rp 200.000");
                        printf("\nLanjutkan? (y/n):  ");
                        scanf("%s", &pilih);

                        if (pilih == 'y' || pilih == 'Y')
                        {
                            strcpy(filename, usr.telp);
                            fp = fopen(strcat(filename, ".dat"), "w");
                            usr.saldo -= 200000;
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);

                            srand(time(NULL));
                            int token = 1000 + rand() % 9000;

                            printf("Transaksi Berhasil! Token Pengisian Anda: %d", token);
                            h += 1;
                        }
                        else if (pilih == 'n' || pilih == 'N')
                        {
                            mainMenu();
                        }
                        else
                        {
                            printf("\nInputan Tidak Valid");
                        }
                        break;

                    case 0:
                        mainMenu();
                        break;

                    default:
                        printf("Invalid. Mohon Masukkan Ulang");
                        getch();
                        goto tknListrik;
                
                }

    }           
                case 2:
                    printf("\nTAGIHAN LISTRIK");
                    printf("\n\nMasukkan No Meter           : ");
                    scanf("%d", &noMeter);
                    printf("Masukkan Nominal Pembayaran    : Rp ");
                    scanf("%f", &listrik);

                    if (usr.saldo <= listrik)
                    {
                        printf("\nSaldo Anda Tidak Mencukupi. Saldo Anda: Rp %.2f", usr.saldo);
                    }
                    else
                    {
                        printf("\nAnda Akan Membayar Tagihan Listrik Sebesar Rp %.2f dengan No. Meter %d", listrik, noMeter);
                        printf("\nLanjutkan? (y/n): ");
                        scanf("%s", &yakin);

                        if (yakin == 'y'||yakin == 'Y')
                        {
                            fp = fopen(filename, "w");
                            usr.saldo -= listrik;
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);

                            printf("\nPembayaran Berhasil. Saldo Anda: Rp %.2f", usr.saldo);
                            h += 1;
                        }
                        else
                        {
                            mainMenu();
                        }
                    }
                    break;

                case 0:
                    mainMenu();
                    break;

                default:
                    printf("\nInvalid. Mohon Masukkan Ulang");
                    getch();
                    goto byrListrik;
                    break;
    }
} 
//End Fungsi Bayar Listrik

//Fungsi Pembayaran Air
void bayarAir()
{
    printf("Masukkan No. Meter: ");
    scanf("%s", &noMeter);
    printf("\nMasukkan Nominal Pembayaran: Rp ");
    scanf("%f", &nominal);

    if (nominal > usr.saldo)
    {
        printf("\nSaldo Anda Tidak Cukup Untuk Melakukan Transaksi. Saldo Anda Rp %.2f", usr.saldo);
    }
    else
    {
        fp = fopen(filename, "w");
        usr.saldo -= nominal;
        fwrite(&usr, sizeof(struct user), 1, fp);
        fclose(fp);

        printf("\nAnda Telah Melakukan Pembayaran Listrik Sebesar: Rp %.2f", nominal);
        h += 1;
    }
}
//End Fungsi Pembayaran Air
//End Fungsi Case Pembayaran Online

//Fungsi Ganti Password
void gantiPass()
{
gantiPass:
    printf("GANTI PASSWORD\n");
    printf("\nAnda Yakin Untuk Mengganti Password Anda?");
    printf("\nMasukkan Pilihan (y/n): ");
    scanf("%s", &yakin);
    system("cls");

    if (yakin == 'y' || yakin == 'Y')
    {
        printf("Masukkan Password Lama Anda: ");
        scanf("%s", pass);

        strcpy(filename, telp);
        fp = fopen(strcat(filename, ".dat"), "r");

        if (strcmp(pass, usr.password))
        {
            printf("Password Tidak Sesuai, Mohon Masukkan Ulang\n\n");
            system("pause");
            system("cls");
            goto gantiPass;
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);

            if (!strcmp(pass, usr.password))
            {
                printf("\nMasukkan Password Baru Anda: ");
                scanf("%s", &newPass);

                fp = fopen(filename, "w");
                strcpy(usr.password, newPass);
                fwrite(&usr, sizeof(struct user), 1, fp);
                if (fwrite != NULL)
                    printf("Password Berhasil Diganti!");
                fclose(fp);
            }
            else
            {
                printf("\nTerjadi Kesalahan, Mohon Coba Lagi\n");
                system("pause");
                goto gantiPass;
            }
        }
    }
    else if (yakin == 'n' || yakin == 'N')
    {
        system("cls");
        mainMenu();
    }
    else
    {
        printf("\nPilihan Tidak Ada, Mohon Masukkan Ulang\n\n");
        system("pause");
        goto gantiPass;
    }
}
//End Fungsi Ganti Password

// Fungsi Struk
void struk()
{
    time(&ambil_waktu);
    printf("Struk Transaksi");
    printf("\nWaktu/Hari: %s", ctime(&ambil_waktu));
    printf("\n_______________________________________\n");
    if (jml_deposit != 0)
    {
        printf("\n\nAnda Telah Melakukan Deposit Sebesar: %.2f\n", jml_deposit);
    }
    else if (jml_tarik != 0)
    {
        printf("\n\nAnda Telah Melakukan Penarikan Sebesar: %.2f\n", jml_tarik);
    }
    else if (tf.samaBank != 0)
    {
        printf("\nAnda Telah Melakukan Transfer Sebesar: Rp %.2f ke No. Telpon: %s\n", tf.samaBank, telp);
    }
    else if (tf.antarBank != 0)
    {
        printf("\nAnda Telah Melakukan Transfer Antar Bank Sebesar: Rp %.2f\n", tf.antarBank)
    }
    else
    {
        printf("\nAnda Tidak Melakukan Transaksi Apapun\n");
    }
    printf("\n_______________________________________\n");
    printf("\nSemoga Hari Anda Menyenangkan");
    printf("\n\nTekan ENTER Untuk Keluar");
    getch();
    system("cls");
    printf("Anda Telah Keluar");
    exit(EXIT_SUCCESS);
}
// End Fungsi Struk