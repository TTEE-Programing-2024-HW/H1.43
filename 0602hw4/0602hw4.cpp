//H1.43徐維均 HW4
#include<stdio.h>
#include <stdlib.h>
//為了使用rand()函數
#include <time.h>
//用來使用time()函數
#include <ctype.h> 
//為了使用 <ctype.h> 這個函式庫中的
//tolower()函數(用來大寫轉小寫)
#include <conio.h>
//用來使用getch()、getche()讀取鍵盤輸入

//預先宣告函數
int drawPicture(); //個人風格化頁面
int checkPassword(); //檢查密碼



//複習
//如果你在呼叫函數之前沒有宣告函數，
//編譯器會不知道這個函數的存在，
//會報錯或生成不正確的程式碼。
//函數宣告告訴編譯器這個函數的名字、返回值類型和參數類型，
//這樣當你在程式碼中呼叫這個函數時，
//編譯器可以正確地解析和處理這個呼叫。


int main(void)
{
    drawPicture();
    //呼叫不接受參數的函數不需在括號中填入 void
    

    printf("您好");


    return 0;
}



int drawPicture()
{
    printf(" _______________________________\n");
    printf("/                             /|\n");
    printf("|  _________________________  ||\n");
    printf("| |                         | ||\n");
    printf("| |        休     學        | ||\n");
    printf("| |                         | ||\n");
    printf("| |                         | ||\n");
    printf("| |                         | ||\n");
    printf("| |                         | ||\n");
    printf("| |                         | ||\n");
    printf("| |                         | ||\n");
    printf("| |_________________________| ||\n");
    printf("|  _________________________  ||\n");
    printf("| /                         /| ||\n");
    printf("|/_________________________/ | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|                         |  | ||\n");
    printf("|_________________________| /  ||\n");
    printf("|                         |/   ||\n");
    printf("|                         /    ||\n");
    printf("|_________________________/     |\n");
    printf("|_________________________/     /\n");
    return 0;
}


int checkPassword()
{
    int password; //儲存使用者輸入的密碼
    int correctpassWord = 2024; //儲存正確密碼
    
    printf("請輸入密碼：\n");
    scanf("%d",&password);






}
 
