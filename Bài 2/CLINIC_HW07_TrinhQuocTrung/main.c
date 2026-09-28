#include <stdio.h>

int main() {
    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    int phi_kham[4];
    int tong_doanh_thu = 0;
    int tong_uu_tien = 0;

    for (int i = 0; i < 4; i++) {
        printf("Nhap tuoi benh nhan %d: ", i + 1);
        scanf("%d", &tuoi_benh_nhan[i]);
        
        printf("BHYT (1: Co, 0: Khong) benh nhan %d: ", i + 1);
        scanf("%d", &co_bao_hiem[i]);

        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            co_bao_hiem[i] = 0;
        }

        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0;
        } else {
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = 40000;
            } else {
                phi_kham[i] = 200000;
            }

            if (tuoi_benh_nhan[i] > 70) {
                tong_uu_tien++;
            }
            tong_doanh_thu += phi_kham[i];
        }
    }

    printf("\n--- TONG HOP CA TRUC ---\n");
    for (int i = 0; i < 4; i++) {
        printf("Benh nhan %d - Tuoi: %d - BHYT: %d - Phi kham: %d VND - Luong: ", 
                i + 1, tuoi_benh_nhan[i], co_bao_hiem[i], phi_kham[i]);
        
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            printf("LOI DU LIEU\n");
        } else if (tuoi_benh_nhan[i] > 70) {
            printf("UU TIEN\n");
        } else {
            printf("THUONG\n");
        }
    }

    printf("Tong doanh thu: %d VND\n", tong_doanh_thu);
    printf("Tong so ca uu tien: %d\n", tong_uu_tien);

    return 0;
}
