// H1.43徐維均 HW4
//vscode測試
//測試Vscode的修正功能
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

// 使用 typedef 定義結構體類型
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
void drawPicture();   // 個人風格化頁面 可
void checkPassword(); // 檢查密碼 可
void pressToContinue(); //按下按鍵後清除螢幕進入下一步 可

void displayChooseMenu(); // 顯示主選單的函數 OK
void enterStudentGrades(Student students[], int *n);  // 輸入學生成績的函數
void searchStudentGrades(Student students[], int n);  // 搜尋學生成績的函數
void gradeRanking(Student students[], int n);         // 成績排名的函數
void displayStudentGrades(Student students[], int n); // 顯示學生成績的函數
void exitConfirmation(); // 確認離開的函數

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
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;
    //先顯示個人風格化畫面
    //執行檢查密碼函數，若檢查完
    drawPicture();
    // 叫不接受參數的函數不需在括號中填入 void
    checkPassword();

        while (1)
    {
        pressToContinue(); 
        //按下按鍵後清除螢幕進入下一步 
        displayChooseMenu(); // 顯示主選單的函數 
        printf("\n輸入您想使用的功能: \n");
        fflush(stdin);
        scanf("%c", &choice);
        choice = tolower(choice);
        // 字母大寫轉小寫

        switch (choice)
        {
        case 'a':
            enterStudentGrades(students, &studentCount);
            break;
        case 'b':
            displayStudentGrades(students, studentCount);
            break;
        case 'c':
            searchStudentGrades(students, studentCount);
            break;
        case 'd':
            gradeRanking(students, studentCount);
            break;
        case 'e':
            exitConfirmation();
            break;
        default:
            printf("\n無效，請重新選擇。\n\n");
            system("pause");
            break;
        }
    }

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

void checkPassword()
{
    int password;               // 儲存使用者輸入的密碼
    int correctpassword = 2024; // 儲存正確密碼
    int count = 0;              // 儲存錯誤次數
    //本來錯誤次數預設1，第一次被呼叫的時候，
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

// 顯示主選單的函數
void displayChooseMenu()
{
    printf(" ------------[Grade System]-----------\n");
    printf("|     a. Enter student grades         |\n");
    printf("|     b. Display student grades       |\n");
    printf("|     c. Search for student grades    |\n");
    printf("|     d. Grade ranking                |\n");
    printf("|     e. Exit system                  |\n");
    printf(" -------------------------------------\n");
}


// 輸入學生成績的函數
void enterStudentGrades(Student students[], int *n)
{
    pressToContinue(); //按下按鍵後清除螢幕進入下一步 可
    while (1)
    {
        printf("請輸入學生人數 (5~10)：");
        fflush(stdin);
        scanf("%d", n);
        if (*n >= MIN_STUDENTS && *n <= MAX_STUDENTS)
        {
            break;
        }
        else
        {
            printf("\n輸入錯誤，請輸入 5 到 10 之間的整數。\n\n");
        }
    }

    for (int i = 0; i < *n; i++)
    {
        printf("\n請輸入第 %d 位學生資料\n", i + 1);

        printf("姓名：");
        fflush(stdin);
        scanf("%s", students[i].name);

        printf("學號 (6位整數)：");
        while (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999)
        {
            printf("\n學號輸入錯誤，請輸入 6 位整數學號：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        printf("數學成績 (0~100)：");
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100)
        {
            printf("\n數學成績輸入錯誤，請輸入 0 到 100 之間的分數：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        printf("物理成績 (0~100)：");
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100)
        {
            printf("\n物理成績輸入錯誤，請輸入 0 到 100 之間的分數：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        printf("英文成績 (0~100)：");
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100)
        {
            printf("\n英文成績輸入錯誤，請輸入 0 到 100 之間的分數：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        // 計算平均成績
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    printf("\n所有學生資料已輸入完畢，請按下任一鍵以返回主選單。");
    getch();
    //按下按鍵並繼續
}


//心得:
//1.
//這次作業相較上次簡單一些，
//但作業還是沒辦法在實驗課上課時間內寫完的題目，
//希望未來能力可以做到。
//2.
//在github上則學會解決一些常見問題，
//例如
//"nothing to commit, working tree clean"
//"Changes not staged for commit"
//"error: switch 'm' requires a value"
//"fatal: invalid gitfile format: HW4.c"
//等等的問題。雖然也使得hash次數變得很多(因為搞出不少問題)，
//但在deadline前，有學到東西蠻開心的。

