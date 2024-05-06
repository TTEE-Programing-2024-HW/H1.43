#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void drawMenu()
{ 
    //因為這個函數的型式是void，
    //所以在宣告的時候
    //小括號裡面可以不用放任何東西
    //可以在裡面設定參數(變數)
    //設定一個函數用來畫選單
    printf("--------------------------\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|  a. 畫出直角三角形     |\n");
    printf("|  b. 顯示乘法表         |\n");
    printf("|  c. 結束               |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("--------------------------\n");
}

void drawRightTriangle(char ch) 
{
    //設定一個函數用來畫向右對齊的三角形
    if (ch < 'a' || ch > 'n') 
	{
    //ch: 用戶輸入的最後一個字母，
	//確定了三角形的高度和最寬的一行的字母數。
	 
		do
        {
		fflush(stdin); 
		//每次重新進入迴圈時，
		//都清除一次螢幕，不然會一次出現兩行提示 
		printf("請重新輸入有效的字元(a至n)。\n");
        scanf("%c",&ch);
		}
        while(ch < 'a' || ch > 'n'); 
		//當ch的值不在要求的範圍內，
		//就繼續要求使用者重新輸入 
		
		
		//return;複習
		//因為這個函數是void，
		//不是int，所以不能return 0(不能return任何數字)
		//這邊不能在do-while 的下面return，
		//否則會直接跳過下面用來畫圖的迴圈
		//造成錯誤 
    }

	for (char stable = 'a'; stable <= ch; stable++) 
	{
    //char ch是使用者輸入的字母，
    //就是三角形底邊的最右邊那個字母    
    
    //stable: 固定的 就是代表三角形第一排"a"這個字母，
    
		for (char space = ch; space > stable; space--) 
		{
            //複習
            //for迴圈的運算式會在整個大括號的最後執行

            //char space = ch意思是:
            //假設要輸出的是這個
            //  c
            // bc
            //abc
            //首先先把使用者輸入的 "c"
            //先設給space(代表著空格數量)
            //for(空格數量 = 使用者輸入的字母 ; 條件:空格數量要大於固定的 a ;每循環一次空格數量減一)
        	//所以如上示意圖，要畫出//  c的時候，
            //先把c代入，判斷c>a，輸出一個空格，然後字元減一變成b
            //判斷字元b大於a，輸出一個空格，然後字元減一變成a
            //判斷字元a不大於a，所以不輸出空格
            //放字元的位置由下一個for迴圈將字元填入
            //
            printf(" ");
            //先打印出空格，以將字母向右對齊
    	}
    // 從 (ch - (temp - 'a')) 開始打印字母直到 ch
    //因為temp -'a' 得出了從 a 到 temp 的字母數量。 
    
		for (char i = ch - ( - 'a'); i <= ch; i++) 
		{
    //char i; i 從 ch - (temp - 'a') 開始，一直遞增到 ch。
	//(char i = ch - (temp - 'a')用來打印每行的字元，
	//從計算得出的起始字元到 ch。
	// 決定了每行應該從哪個字元開始打印。
	    	printf("%c", i);
    	}		
    printf("\n");
	}

}




int main()
{
    return 0;
}  