#include <stdio.h>
#include<limits.h>
#define BAC_CU 6
#define BAC_MOI 5
#define VAT 1.1
/*VD: Dùng 150kwh:
    tiền điện = (50-0+1)*1.728 + (100-51+1)*1.786 + (150-101+1)*2.047
*/
struct Infor
{
    Infor (int mi, int ma, double pric){
        min = mi;
        max = ma;
        price = pric;
    }
    int min, max;
    double price;
};
double CashRegister (int so_dien, Infor a[], int so_bac){
    double tien;
    for (int i = 0; i < so_bac; i++)
    {
        if (so_dien >= a[i].min && so_dien <= a[i].max) {
            tien += a[i].price * (so_dien - a[i].min + 1);
        }
        if(so_dien > a[i].max){
            tien += a[i].price * (a[i].max - a[i].min + 1);
        }
        
    }
    
    return tien;
}
int main (){
    Infor old_price[BAC_CU] = {
        Infor(0, 50, 1.728), 
        Infor(51, 100, 1.786),
        Infor(101, 200, 2.074),
        Infor(201, 300, 2.612),
        Infor(301, 400, 2.919),
        Infor(401, INT_MAX, 3.015)
    };
    Infor new_price[BAC_MOI] = {
        Infor(0, 100, 1.728), 
        Infor(101, 200, 2.074),
        Infor(201, 400, 2.612),
        Infor(401, 700, 3.111),
        Infor(701, INT_MAX, 3.457)
    };
    int so_dien = 150;
    printf("Nhap so dien da dung: ");scanf("%d", &so_dien);
    double so_tien_theo_gia_cu = CashRegister(so_dien, old_price, BAC_CU) * VAT;
    double so_tien_theo_gia_moi = CashRegister(so_dien, new_price, BAC_MOI) * VAT;
    double chenh_lech = so_tien_theo_gia_moi - so_tien_theo_gia_cu;
    printf("So tien theo gia moi: %.2lf\n", so_tien_theo_gia_moi);
    printf("So tien theo gia cu: %.2lf\n", so_tien_theo_gia_cu);
    printf("So tien chech lech: %.2lf\n", chenh_lech);
    return 0;
}