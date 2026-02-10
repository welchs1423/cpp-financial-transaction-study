#include <stdio.h>
#include <string.h>

typedef struct {
    char    acc_no[20];     // 계좌번호
    char    user_name[40];  // 고객명
    long    balance;        // 잔고 (단위: 원)   
}   Account;

// 현재 계좌 정보를 파일에 저장
void save_to_file(Account *a) {
    FILE *fp = fopen("account.txt", "w");   // 쓰기 모드로 파일 열기
    if (fp == NULL){
        printf("파일을 열수 없습니다!\n");
        return;
    }
    fprintf(fp, "%s %s %ld", a->acc_no, a->user_name, a->balance);
    fclose(fp);
    printf(">> 데이터가 account.txt에 저장되었습니다. \n");
}

void load_from_file(Account *a){
    FILE *fp = fopen("account.txt", "r");
    if(fp == NULL){
        printf(">> 기존 데이터가 없습니다. 기본 정보를 생성합니다. \n");
        return;
    }
    fscanf(fp, "%s %s %ld", a->acc_no, a->user_name, &a->balance);
    fclose(fp);
    printf(">> 데이터를 파일에서 성공적으로 불러왔습니다. \n");
}

int main(){
    Account my_acc = {"110-123-456", "Park_Dev", 5000000};

    load_from_file(&my_acc);
    printf("\n--- 현재 계좌 정보 ---\n");
    printf("계좌번호: %s | 고객명: %s | 잔액: %ld원\n\n", my_acc.acc_no,my_acc.user_name,my_acc.balance);

    int choice;
    long amount;
    printf("1.입금 2.출금 (번호 선택): ");
    scanf("%d", &choice);
    printf("금액 입력: ");
    scanf("%ld", &amount);

    if(choice == 1){
        my_acc.balance += amount;
        printf("[입금 완료] 현재 잔액: %ld원\n", my_acc.balance);
    } else if(choice == 2){
        if(my_acc.balance < amount){
            printf("[실패] 잔액이 부족합니다!\n");
        } else {
            my_acc.balance -= amount;
            printf("[출금 완료] 현재 잔액: %ld원\n", my_acc.balance);
        }
    }

    save_to_file(&my_acc);

    return 0;
}