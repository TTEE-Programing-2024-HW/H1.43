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

//�H�U�� �w�B�z��
#define MAX_STUDENTS 10
#define MIN_STUDENTS 5
//�]�w�ǥͤH�Ƴ̤p�Ȭ�5�A�̤j��10
#define NAME_LEN 50
//�]�w�m�W�����׳̤j�Ȭ�50
#define ID_LEN 6
//����Ǹ��O������
#define BIG_TIMES 3
//�̤j���ƬO3

// �ϥ� typedef �w�q���c������ Student
typedef struct
{
    char name[NAME_LEN];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;


// �w���ŧi���
void drawPicture();   // �ӤH����ƭ���
void checkPassword(); // �ˬd�K�X
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

void drawPicture()
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
    int count = 0;              // �x�s���~����
    // ���ӿ��~���ƹw�]1�A�Ĥ@���Q�I�s���ɭԡA
    //�N���ΦA�h�@��count = count + 1;���B�J�C 
    //���ϥ�do-while�|�X���D 

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
        	count++; 
			//���~���ƭn��b�j�骺�@�}�l�A
			//�~��Y�ɪ��D���F�X�� 
			if(count >= 3 || count == 3)
			{
				//�p�G���~���Ƥj��3�ε���3�A
				//�N���}�j�������{��
				printf("�K�X��J���~�F%d���A�����{��",count);
				return 1; //�Q��return�����{�� 
			}
			 //���~���ƥ[�@ 
			printf("�K�X��J���~�F%d��",count);
        	printf("�Э��s��J�K�X�G\n");
    		scanf("%d", &password);
			
		}while(password != correctpassword); 
        //��K�X���¿��~�A�N�~�����ϥΪ̭��s��J
    
    }
}






void pressToContinue() //���U�����M���ù��i�J�U�@�B  
{
    printf("���U���@����");
    getch();
}

//�߱o:
//�o���@�~�۸��W��²��@�ǡA
//���@�~�٬O�S��k�b����ҤW�Үɶ����g�����D�ءA
//�Ʊ楼�ӯ�O�i�H����C
//github�h�Ƿ|�ѨM�@�Ǳ`�����D�A
//�Ҧp
//"nothing to commit, working tree clean"
//"Changes not staged for commit"
//"error: switch 'm' requires a value"
//"fatal: invalid gitfile format: HW4.c"
//���������D�C