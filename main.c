#include <stdio.h>
#include <string.h>

typedef struct {
    char    acc_no[20];     // 계좌번호
    char    user_name[40];  // 고객명
    long    balance;        // 잔고 (단위: 원)   
}   Account;

int main(){
    Account my_acc;

    strcpy(my_acc.acc_no, "110-123-456789");
    strcpy(my_acc.user_name, "Park Developer");
    my_acc.balance = 5000000;

    // 2. 결과 출력
    printf("==============================\n");
    printf("   [C-STOCK] 계좌 정보 확인   \n");
    printf("==============================\n");
    printf(" 계좌번호 : %s\n", my_acc.acc_no);
    printf(" 고 객 명 : %s\n", my_acc.user_name);
    printf(" 현재잔고 : %ld 원\n", my_acc.balance);
    printf("==============================\n");

    return 0;
}