//H1.43�}���� HW4
#include<stdio.h>
#include <stdlib.h>
//���F�ϥ�rand()���
#include <time.h>
//�ΨӨϥ�time()���
#include <ctype.h> 
//���F�ϥ� <ctype.h> �o�Ө禡�w����
//tolower()���(�ΨӤj�g��p�g)
#include <conio.h>
//�ΨӨϥ�getch()�Bgetche()Ū����L��J

//�w���ŧi���
int drawPicture(); //�ӤH����ƭ���
int checkPassword(); //�ˬd�K�X



//�Ʋ�
//�p�G�A�b�I�s��Ƥ��e�S���ŧi��ơA
//�sĶ���|�����D�o�Ө�ƪ��s�b�A
//�|�����Υͦ������T���{���X�C
//��ƫŧi�i�D�sĶ���o�Ө�ƪ��W�r�B��^�������M�Ѽ������A
//�o�˷�A�b�{���X���I�s�o�Ө�ƮɡA
//�sĶ���i�H���T�a�ѪR�M�B�z�o�өI�s�C


int main(void)
{
    drawPicture();
    //�I�s�������Ѽƪ���Ƥ��ݦb�A������J void
    

    printf("�z�n");


    return 0;
}



int drawPicture()
{
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
    int password; //�x�s�ϥΪ̿�J���K�X
    int correctpassWord = 2024; //�x�s���T�K�X
    
    printf("�п�J�K�X�G\n");
    scanf("%d",&password);






}
 
