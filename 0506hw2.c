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
    //判斷用戶輸入的字母有沒有在範圍內
    //ch: 用戶輸入的字母，
	//確定了三角形的高度和最寬的一行的字母數。
    //因為如果輸入c，那他是由a數到c第三個字母，
    //所以高度和三角形底邊會分別為三個字元的高度及寬度
	 
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
    //就是三角形底邊的最左邊的"a"    
    //stable: 固定的
    

		for (char space = ch; space > stable; space--) 
		{
            //用來打印空格
            
            //複習
            //for迴圈的運算式會在整個大括號的最後執行

            //char space = ch意思是:
            //假設要輸出的是下面這個
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
        
            printf(" ");
            //先打印出空格，以將字母向右對齊
    	}
 
    
		for (char i = ch - ( stable- 'a'); i <= ch; i++) 
		{
        //用來打印字母
        //char i 
        //一樣用ch = c舉例,
        //  c
        // bc
        //abc

        //char i = ch - ( stable- 'a')
        //第一排i等於c - (a-a)，char i也等於c
        //所以第一行唯一一個字母也是第一個字母，就是c
        //第二排，c = c-(b-a);
        //char i 被修改b，所以第二行的第一個字母會是b，
        //然後b++就會變成c，所以在第二行的b的右邊補上c
        //第三排
        //b = c-(c-a)
        //所以char i被修改為a，第三行第一個字母是a
        //剩下的以此類推
	    	printf("%c", i); //根據上面的邏輯，把字母(字元)輸出到螢幕
    	}		
    printf("\n"); //每輸出到無法輸出字母，就換行
	}
    printf("\n按任意鍵返回主選單...");
    getch();
}


void drawMultiplicationTable(int n) {
    if (n < 1 || n > 9) 
	{
        //如果n不在1和9之間
		do
		{	
		fflush(stdin);
        //就清除螢幕重新要求使用者輸入，直到輸入正確範圍內的整數
		printf("請輸入有效的整數(1至9)。\n");
    	scanf("%d",&n);
    	
		}while(n < 1 || n > 9);
		//do-while的while()要加分號 
		
    }

    for (int i = 1; i <= n; i++) 
    {
        //被輸出到螢幕上的九九乘法表的除數與被除數的最大值的大小，
        //不能超過使用者輸入的數字
        //所以n值為5，那最大的計算式就是5*5=25
        for (int j = 1; j <= i; j++) 
        {
            printf("%d*%d=%-2d ", j, i, i * j);
        // " - " :左對齊
        }
        printf("\n");
    }

    printf("\n按任意鍵返回主選單...");
    getch();
    //getch(); 已經有被定義了
    //只是被放在int main，所以函數裡面就不用再定義
}




int main() {
    int passwordAttempts = 0; //儲存密碼錯誤次數 
    int password = 2024; //正確密碼
    int inputPassword; //儲存使用者輸入的密碼 
    
    
	printf("歡迎畫面\n");
	printf("                       |                   \n");  // 打印第一行
	printf("                __\\--__|_ \n");  // 打印第二行
	printf("II=======OOOOO[/ ★ 休學坦克 ___|           \n");  // 打印第三行
	printf("          _____\\______|/-----. \n");  // 打印第四行
	printf("        /____________________|              \n");  // 打印第五行
	printf("         \\◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎⊙/ \n");  // 打印第六行
	printf("           ~~~~~~~~~~~~~~~~\n");                  //以下就都是打印
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                              \n");
	printf("                                              \n");
	printf("　　．．．．▍▍．..．█▍ ☆ ★∵★∴ ..../\n");
	printf("　　◥█▅▅██▅▅██▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅███████◤\n");
	printf(" 　 ．◥███████████████████████████◤\n");
	printf("～～～～◥████████學渣號自走火炮█◤～～～～\n");
	printf("～～～～~~◥████████████████████◤～～～～\n");
	printf("～～～～~~~~◥████████████████◤～～～～\n");
	printf("～～～～~~~~~~◥███████████◤～～～～\n");
	printf("～～～    ～～ ～～    ～～～～～～～\n");
	printf("～～～～   ～～～～～   ～～～～ ～～  ～ ～\n");
	


	//步驟1由此開始 
	printf("按鍵盤上的任意鍵，清除畫面\n");
 
	
	char end; //設定一個變數為end，代表鍵盤上的任何一個字元，按下後就會清除螢幕畫面  
	end = getche();  
	system("cls"); //清理螢幕畫面 
	
	//複習 
	//getche();功能是:
	//按下鍵盤上的任意按鍵，以達到某個目的，
	//getch();是指在終端控制台上，看不到 
	//自己按了甚麼按鍵， 
	//getche();看得到自己按了甚麼按鍵 
	
	//步驟2由此開始 
    
	 	//複習: 
	
	//不能這樣寫printf("%d\n,password");
	//這樣%d會變成一個亂碼，
	//因為是從記憶體殘值中隨便取一個數  
	
	while (passwordAttempts < 3) 
	{
        printf("請輸入四位數的密碼：");
        scanf("%d", &inputPassword);

		if (inputPassword == password) 
		{
            break;
        }else 
		{
            printf("密碼輸入錯誤，請重新輸入。\n");
            passwordAttempts++;
        }
        
    }

    if (passwordAttempts == 3)
	{
        printf("密碼輸入錯誤次數達到三次，程式即將結束。\n");
        return 0;
    }

    char choice; //設一個變數儲存使用者輸入的字元 
    do {
        system("cls");
        drawMenu(); //呼叫上面的函數畫出選單 
        
		printf("請輸入選擇：");
        fflush(stdin); //清除緩存
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
            case 'A': 
			{
                system("cls"); //清理螢幕上的輸出，讓畫面簡潔
				//專用於windows系統中的操作指令，只有windows系統可以用 
                printf("請輸入字元(a至n)：");
                char ch;
                fflush(stdin); //清理標準輸入緩衝區中沒有被處理的數據 
                //如果程式中之前的讀取操作（如 scanf）未能消耗用戶輸入的所有字符，
				//剩餘的字符將留在輸入緩衝區中。
				//例如，用戶輸入 "abc" 但程式只讀取了第一個字符，
				//剩下的 "bc" 仍然在緩衝區中。
				
				//當程式嘗試進行下一次讀取時，
				//這些剩餘字符可能會被錯誤地視為新的輸入，
				//導致程式行為異常或錯誤的數據處理。 
				scanf("%c", &ch);
                if(ch == 'a')
				{
					printf("畫不出正常的三角形，如下圖所示 ，只有一個 a 阿!!!!! \n"); 
					drawRightTriangle(ch);
					//把ch這個變數丟給畫三角形的函數
				}
				else
				{
				//printf("圖案如下: \n"); 
				drawRightTriangle(ch);  //呼叫用來畫三角形的函數 
            	}
				break;
            }
            case 'b':
            case 'B': 
			{
                system("cls");
                int n;
                printf("請輸入一個1至9的整數：");
                fflush(stdin);
                scanf("%d", &n);
                drawMultiplicationTable(n); 
				//把n丟給九九乘法表的函數
                break;
            }
            case 'c':
            case 'C': 
			{
                system("cls");
                char confirm; //設定一個變數用來 confirm (確認)使用者的動作 
                printf("Continue? (y/n): ");
                fflush(stdin);
                scanf(" %c", &confirm);
                
				
				if(confirm == 'n' || confirm == 'N' || confirm == 'y' || confirm == 'Y')
				{
				//如果confirm是n或N或y或Y，就再判斷是N還是Y
					if(confirm == 'y' || confirm == 'Y')
					{
						drawMenu(); //呼叫上面的函數畫出選單 
						printf("請輸入選擇：");
        				fflush(stdin);
						scanf("%c", &choice);
        				break;
        				//break;
						//這樣寫才能讓程式讀取到選單的選擇，
						//不然會卡在switch迴圈裏面 
					} 
					else
					{
						printf("結束程式\n");
						return 1;	
					}
				}
				else
				{
					do
					{
						//當輸入的字母不是這四個指定字元，
						//就重複要求輸入，直到使用者輸入正確 
						fflush(stdin);
						printf("請輸入符合要求的答案\n");
						scanf("%c",&confirm);
					
					}while(confirm != 'n' || confirm != 'N' || confirm != 'y' || confirm != 'Y');
					//while、if的小括號內都要用關係運算符 == 來表示 "等於"，
					//不能用賦值運算符 " = "表示 "等於" 這個概念 
					//當使用者輸入的字元不符，就再次進入迴圈 
				}
				
				//以下須注意
				//這樣會直接結束程式，不符要求 
				/*
				if (confirm == 'n' || confirm == 'N') 
				{
                    printf("程式結束。\n");
                    return 0;
                } else if (confirm != 'y' && confirm != 'Y') 
				{
                    printf("請輸入有效的選擇(y/n)。\n");
                }
                */ 
				break;
			}

        }
    } while (choice != 'c' && choice != 'C'); 
	//當使用者輸入的字元不是c也不是C，就重複迴圈 

    return 0;//程式結束
}

//1.這次為了更了解迴圈，
//所以試著詳細的解釋畫三角形的過程，
//也藉此訓練我的邏輯，
//畫流程圖的時候也會比較得心應手

//2.這次也更了解函數的意義，
//對函數及主程式的關係與使用方法更加熟練
//也更了解自己的邏輯能力

//3.最難也是這次收穫最多的部分，
//我想是稍微了解github的應用方式，
//這部份很感謝助教的幫忙
//最後為了方便寫程式，又再學會使用VScode。



