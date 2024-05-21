// H1.43徐維均 HW4
#include <stdio.h>
#include <stdlib.h>
// 為了使用rand()函數
#include <time.h>
// 用來使用time()函數
#include <ctype.h>
// 為了使用 <ctype.h> 這個函式庫中的
// tolower()函數(用來大寫轉小寫)
#include <conio.h>
// 用來使用getch()、getche()讀取鍵盤輸入

// 預先宣告函數
int drawPicture();   // 個人風格化頁面
int checkPassword(); // 檢查密碼
void pressToContinue(); //按下按鍵後清除螢幕進入下一步 

//「按下任何鍵繼續」，為了方便，簡化程式提升效率
// 複習
// 如果你在呼叫函數之前沒有宣告函數，
// 編譯器會不知道這個函數的存在，
// 會報錯或生成不正確的程式碼。
// 函數宣告告訴編譯器這個函數的名字、返回值類型和參數類型，
// 這樣當你在程式碼中呼叫這個函數時，
// 編譯器可以正確地解析和處理這個呼叫。

int main(void)
{
    //先顯示個人風格化畫面
    //執行檢查密碼函數，若檢查完
    drawPicture();
    // 叫不接受參數的函數不需在括號中填入 void
    checkPassword();

    return 0;
}

int drawPicture()
{
    printf("這是一本書\n");
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
    int password;               // 儲存使用者輸入的密碼
    int correctpassword = 2024; // 儲存正確密碼
    int count = 1;              // 儲存錯誤次數
    // 錯誤次數預設1，因為第一次被呼叫的時候，
    //就不用再多一個count = count + 1;的步驟
    //

    printf("請輸入密碼：\n");
    scanf("%d", &password);

    if (password == correctpassword)
    {
        // 如果輸入正確(2024)，按下按鍵後清除螢幕進入第二題 
        printf("歡迎:\n點擊任一按鍵進入步驟2\n");
        void pressToContinue(); //等按下按鍵才清除螢幕進入步驟2
		 
        fflush(stdin);
        system("CLS");
        //「按下任何鍵繼續」，為了方便，簡化程式提升效率
    
    
    }
    else
    {
        do
        {
        	printf("密碼輸入錯誤達%d次",count);
        	printf("請重新輸入密碼：\n");
    		scanf("%d", &password);

		}while(password != correctpassword);
    
    }
}






void pressToContinue() //按下按鍵後清除螢幕進入下一步  
{
    printf("按下任一按鍵");
    getch();
}
