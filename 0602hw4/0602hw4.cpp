// H1.43�}���� HW4
#include <stdio.h>
#include <stdlib.h>
// ���F�ϥ�rand()���
#include <time.h>
// �ΨӨϥ�time()���
#include <ctype.h>
// ���F�ϥ� <ctype.h> �o�Ө禡�w����
// tolower()���(�ΨӤj�g��p�g)
#include <conio.h>
// �ΨӨϥ�getch()�Bgetche()Ū����L��J

// �w���ŧi���
int drawPicture();   // �ӤH����ƭ���
int checkPassword(); // �ˬd�K�X
void pressToContinue(); //���U�����M���ù��i�J�U�@�B 

//�u���U�������~��v�A���F��K�A²�Ƶ{�����ɮĲv
// �Ʋ�
// �p�G�A�b�I�s��Ƥ��e�S���ŧi��ơA
// �sĶ���|�����D�o�Ө�ƪ��s�b�A
// �|�����Υͦ������T���{���X�C
// ��ƫŧi�i�D�sĶ���o�Ө�ƪ��W�r�B��^�������M�Ѽ������A
// �o�˷�A�b�{���X���I�s�o�Ө�ƮɡA
// �sĶ���i�H���T�a�ѪR�M�B�z�o�өI�s�C

int main(void)
{
    //����ܭӤH����Ƶe��
    //�����ˬd�K�X��ơA�Y�ˬd��
    drawPicture();
    // �s�������Ѽƪ���Ƥ��ݦb�A������J void
    checkPassword();

    return 0;
}

int drawPicture()
{
    printf("�o�O�@����\n");
	printf(" _______________________________\n");
    printf("/                             /|\n");
    printf("|  _________________________  ||\n");
    printf("| |                         | ||\n");
    printf("| |        ��     ��        | ||\n");
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
    int password;               // �x�s�ϥΪ̿�J���K�X
    int correctpassword = 2024; // �x�s���T�K�X
    int count = 1;              // �x�s���~����
    // ���~���ƹw�]1�A�]���Ĥ@���Q�I�s���ɭԡA
    //�N���ΦA�h�@��count = count + 1;���B�J
    //

    printf("�п�J�K�X�G\n");
    scanf("%d", &password);

    if (password == correctpassword)
    {
        // �p�G��J���T(2024)�A���U�����M���ù��i�J�ĤG�D 
        printf("�w��:\n�I�����@����i�J�B�J2\n");
        void pressToContinue(); //�����U����~�M���ù��i�J�B�J2
		 
        fflush(stdin);
        system("CLS");
        //�u���U�������~��v�A���F��K�A²�Ƶ{�����ɮĲv
    
    
    }
    else
    {
        do
        {
        	printf("�K�X��J���~�F%d��",count);
        	printf("�Э��s��J�K�X�G\n");
    		scanf("%d", &password);

		}while(password != correctpassword);
    
    }
}






void pressToContinue() //���U�����M���ù��i�J�U�@�B  
{
    printf("���U���@����");
    getch();
}
