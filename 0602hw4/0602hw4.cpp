// H1.43�}���� HW4
//vscode����
//����Vscode���ץ��\��
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

// �ϥ� typedef �w�q���c������
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
void drawPicture();   // �ӤH����ƭ��� �i
void checkPassword(); // �ˬd�K�X �i
void pressToContinue(); //���U�����M���ù��i�J�U�@�B �i

void displayChooseMenu(); // ��ܥD��檺��� OK
void enterStudentGrades(Student students[], int *n);  // ��J�ǥͦ��Z�����
void searchStudentGrades(Student students[], int n);  // �j�M�ǥͦ��Z�����
void gradeRanking(Student students[], int n);         // ���Z�ƦW�����
void displayStudentGrades(Student students[], int n); // ��ܾǥͦ��Z�����
void exitConfirmation(); // �T�{���}�����

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
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;
    //����ܭӤH����Ƶe��
    //�����ˬd�K�X��ơA�Y�ˬd��
    drawPicture();
    // �s�������Ѽƪ���Ƥ��ݦb�A������J void
    checkPassword();

        while (1)
    {
        pressToContinue(); 
        //���U�����M���ù��i�J�U�@�B 
        displayChooseMenu(); // ��ܥD��檺��� 
        printf("\n��J�z�Q�ϥΪ��\��: \n");
        fflush(stdin);
        scanf("%c", &choice);
        choice = tolower(choice);
        // �r���j�g��p�g

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
            printf("\n�L�ġA�Э��s��ܡC\n\n");
            system("pause");
            break;
        }
    }

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

void checkPassword()
{
    int password;               // �x�s�ϥΪ̿�J���K�X
    int correctpassword = 2024; // �x�s���T�K�X
    int count = 0;              // �x�s���~����
    //���ӿ��~���ƹw�]1�A�Ĥ@���Q�I�s���ɭԡA
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

// ��ܥD��檺���
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


// ��J�ǥͦ��Z�����
void enterStudentGrades(Student students[], int *n)
{
    pressToContinue(); //���U�����M���ù��i�J�U�@�B �i
    while (1)
    {
        printf("�п�J�ǥͤH�� (5~10)�G");
        fflush(stdin);
        scanf("%d", n);
        if (*n >= MIN_STUDENTS && *n <= MAX_STUDENTS)
        {
            break;
        }
        else
        {
            printf("\n��J���~�A�п�J 5 �� 10 ��������ơC\n\n");
        }
    }

    for (int i = 0; i < *n; i++)
    {
        printf("\n�п�J�� %d ��ǥ͸��\n", i + 1);

        printf("�m�W�G");
        fflush(stdin);
        scanf("%s", students[i].name);

        printf("�Ǹ� (6����)�G");
        while (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999)
        {
            printf("\n�Ǹ���J���~�A�п�J 6 ���ƾǸ��G");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        printf("�ƾǦ��Z (0~100)�G");
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100)
        {
            printf("\n�ƾǦ��Z��J���~�A�п�J 0 �� 100 ���������ơG");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        printf("���z���Z (0~100)�G");
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100)
        {
            printf("\n���z���Z��J���~�A�п�J 0 �� 100 ���������ơG");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        printf("�^�妨�Z (0~100)�G");
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100)
        {
            printf("\n�^�妨�Z��J���~�A�п�J 0 �� 100 ���������ơG");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        // �p�⥭�����Z
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    printf("\n�Ҧ��ǥ͸�Ƥw��J�����A�Ы��U���@��H��^�D���C");
    getch();
    //���U������~��
}


//�߱o:
//1.
//�o���@�~�۸��W��²��@�ǡA
//���@�~�٬O�S��k�b����ҤW�Үɶ����g�����D�ءA
//�Ʊ楼�ӯ�O�i�H����C
//2.
//�bgithub�W�h�Ƿ|�ѨM�@�Ǳ`�����D�A
//�Ҧp
//"nothing to commit, working tree clean"
//"Changes not staged for commit"
//"error: switch 'm' requires a value"
//"fatal: invalid gitfile format: HW4.c"
//���������D�C���M�]�ϱohash�����ܱo�ܦh(�]���d�X���ְ��D)�A
//���bdeadline�e�A���Ǩ�F���Z�}�ߪ��C

