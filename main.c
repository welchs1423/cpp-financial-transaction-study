#include <stdio.h>
#include <string.h>

typedef struct {
    char    acc_no[20];     // 계좌번호
    char    user_name[40];  // 고객명
    long    balance;        // 잔고 (단위: 원)   
}   Account;

// 잔고에 금액을 더합니다.
void deposit(Account *acc, long amount){
    acc->balance += amount;
    printf("[입금 완료] %ld원 (현재 잔고: %ld원)\n", amount, acc->balance);
}

int withdraw(Account *acc, long amount){
    if (acc->balance < amount){
        printf("[출금 실패] 잔액이 부족합니다. (현재 잔고: %ld원)\n", acc->balance);
        return -1;  // 실패 시 -1 반환
    }
    acc->balance -= amount;
    printf("[출금 완료] %ld원 (현재 잔고: %ld원)\n", amount, acc->balance);
    return 0;
}

int main(){
    Account my_acc = {"110-123-456789", "Park Developer", 5000000};
    
    deposit(&my_acc,1000000);   // 100만원 입금
    deposit(&my_acc, 7000000);  // 700만원 출금 시도 (부족 해야함)
    withdraw(&my_acc, 3000000);  // 300만원 출금 성공

    return 0;
}