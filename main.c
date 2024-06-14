#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data yang digunakan
typedef struct Pasien {
    int indekspasien;
    char nama_pasien[100];
    char alamat[150];
    char kota[50];
    char tempat_lahir[50];
    char tanggal_lahir[30];
    int umur;
    char nomor_bpjs[20];
    char id_pasien[20];
    struct Pasien *next;
} Pasien;

typedef struct RiwayatPasien {
    int indeksriwayat;
    char tanggal_kunjungan[20];
    char id_pasien[20];
    char diagnosis[100];
    char tindakan[100];
    char kontrol[20];
    double biaya;
    struct RiwayatPasien *next;
} RiwayatPasien;

typedef struct BiayaTindakan {
    int indekstindakan;
    char aktivitas[20];
    double biayatindakan;
    struct BiayaTindakan *next;
} BiayaTindakan;

// Fungsi untuk membaca CSV pasien
int baca_csv_pasien(const char *nama_file, Pasien **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[500];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        Pasien *listpasien = (Pasien*)malloc(sizeof(Pasien));
        sscanf(baris, "%d,%99[^,],%149[^,],%49[^,],%49[^,],%29[^,],%d,%19[^,],%19[^\n]",
               &listpasien->indekspasien, listpasien->nama_pasien, listpasien->alamat,
               listpasien->kota, listpasien->tempat_lahir, listpasien->tanggal_lahir,
               &listpasien->umur, listpasien->nomor_bpjs, listpasien->id_pasien);
        listpasien->next = NULL;

        if (*head == NULL) {
            *head = listpasien;
        } else {
            Pasien *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = listpasien;
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk membaca CSV riwayat
int baca_csv_riwayat(const char *nama_file, RiwayatPasien **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[500];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        RiwayatPasien *riwayat = (RiwayatPasien*)malloc(sizeof(RiwayatPasien));
        sscanf(baris, "%d,%19[^,],%19[^,],%99[^,],%99[^,],%19[^,],%lf",
               &riwayat->indeksriwayat, riwayat->tanggal_kunjungan, riwayat->id_pasien,
               riwayat->diagnosis, riwayat->tindakan, riwayat->kontrol, &riwayat->biaya);
        riwayat->next = NULL;

        if (*head == NULL) {
            *head = riwayat;
        } else {
            RiwayatPasien *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = riwayat;
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk membaca CSV biaya
int baca_csv_biaya(const char *nama_file, BiayaTindakan **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[200];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        BiayaTindakan *biaya = (BiayaTindakan*)malloc(sizeof(BiayaTindakan));
        sscanf(baris, "%d,%19[^,],%lf", &biaya->indekstindakan, biaya->aktivitas, &biaya->biayatindakan);
        biaya->next = NULL;

        if (*head == NULL) {
            *head = biaya;
        } else {
            BiayaTindakan *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = biaya;
        }
    }
    fclose(file);
    return 1;
}


// Fungsi main
int main() {
    Pasien *head_pasien = NULL;
    RiwayatPasien *head_riwayat = NULL;
    BiayaTindakan *head_biaya = NULL;
    
    baca_csv_pasien("DataPasien.csv", &head_pasien);
    baca_csv_riwayat("RiwayatPasien.csv", &head_riwayat);
    baca_csv_biaya("BiayaTindakan.csv", &head_biaya);

    int pilihan;
    do {
        printf("\nMenu Utama:\n");
        printf("1. Tambah Data Pasien\n");
        printf("2. Ubah Data Pasien\n");
        printf("3. Hapus Data Pasien\n");
        printf("4. Cari Data Pasien\n");
        printf("5. Tambah Riwayat Pasien\n");
        printf("6. Ubah Riwayat Pasien\n");
        printf("7. Hapus Riwayat Pasien\n");
        printf("8. Cari Riwayat Pasien\n");
        printf("9. Informasi Pendapatan\n");
        printf("10. Informasi Jumlah Pasien dan Penyakit\n");
        printf("11. Informasi Kontrol Pasien\n");
        printf("0. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                //tambah_pasien(&head_pasien);
                break;
            case 2:
                //ubah_pasien(head_pasien);
                break;
            case 3:
                //hapus_pasien(&head_pasien);
                break;
            case 4:
                //cari_pasien(head_pasien);
                break;
            case 5:
                //tambah_riwayat(&head_riwayat);
                break;
            case 6:
                //ubah_riwayat(head_riwayat);
                break;
            case 7:
                //hapus_riwayat(&head_riwayat);
                break;
            case 8:
                //cari_riwayat(head_riwayat);
                break;
            case 9:
                //informasi_pendapatan(head_riwayat);
                break;
            case 10:
                //informasi_riwayat(head_riwayat);
                break;
            case 11:
                //informasi_kontrol(head_riwayat);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);
    return 0;
}
