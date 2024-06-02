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

//以下為 預處理器
#define MAX_STUDENTS 10
#define MIN_STUDENTS 5
//設定學生人數最小值為5，最大值10
#define NAME_LEN 50
//設定姓名的長度最大值為50
#define ID_LEN 6
//限制學號是六位整數
#define BIG_TIMES 3
//最大次數是3

// 使用 typedef 定義結構體類型 Student
typedef struct
{
    char name[NAME_LEN];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;


// 預先宣告函數
void drawPicture();   // 個人風格化頁面
void checkPassword(); // 檢查密碼
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

void drawPicture()
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
    int count = 0;              // 儲存錯誤次數
    // 本來錯誤次數預設1，第一次被呼叫的時候，
    //就不用再多一個count = count + 1;的步驟。 
    //但使用do-while會出問題 

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
        	count++; 
			//錯誤次數要放在迴圈的一開始，
			//才能即時知道錯了幾次 
			if(count >= 3 || count == 3)
			{
				//如果錯誤次數大於3或等於3，
				//就離開迴圈關閉程式
				printf("密碼輸入錯誤達%d次，關閉程式",count);
				return 1; //利用return結束程式 
			}
			 //錯誤次數加一 
			printf("密碼輸入錯誤達%d次",count);
        	printf("請重新輸入密碼：\n");
    		scanf("%d", &password);
			
		}while(password != correctpassword); 
        //當密碼依舊錯誤，就繼續讓使用者重新輸入
    
    }
}






void pressToContinue() //按下按鍵後清除螢幕進入下一步  
{
    printf("按下任一按鍵");
    getch();
}

//心得:
//這次作業相較上次簡單一些，
//但作業還是沒辦法在實驗課上課時間內寫完的題目，
//希望未來能力可以做到。
//github則學會解決一些常見問題，
//例如
//"nothing to commit, working tree clean"
//"Changes not staged for commit"
//"error: switch 'm' requires a value"
//"fatal: invalid gitfile format: HW4.c"
//等等的問題。