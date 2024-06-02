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
#include <string.h>


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
int checkPassword(); // �ˬd�K�X �i
void pressToContinue(); //���U�����M���ù��i�J�U�@�B �i

void displayChooseMenu(); // ��ܥD��檺��� OK
void enterStudentGrades(Student students[], int *n);  // ��J�ǥͦ��Z�����
void searchStudentGrades(Student students[], int n);  // �j�M�ǥͦ��Z�����
void gradeRanking(Student students[], int n);         // ���Z�ƦW�����
void displayStudentGrades(Student students[], int n); // ��ܾǥͦ��Z�����
void exitConfirmation(); // �T�{���}�����
void clearScreen();

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
    //�������Ѽƪ���Ƥ��ݦb�A������J void
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

void clearScreen() //�M���ù�
{
    system("CLS");
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
}

int checkPassword()
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
        pressToContinue(); //�����U����~�M���ù��i�J�B�J2
		 
        fflush(stdin);
        clearScreen();
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
    printf("���U���@����i�J�U�@�B");
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
            //�X�ݵ��c���ܶq�������C
            //�u.�v���Ψӫ����n�X�ݩγ]�m���S�w�����A
            //�q�Ӥ��\�ﵲ�c�餤���U�Ӧ����i��ާ@�C

            //�p�G�ŦX����~�Q�s�J���c�骺�U�Ӷ���

            printf("\n�Ǹ���J���~�A�п�J 6 ���ƾǸ��G");
            while (getchar() != '\n')
                ; // �M���w�İ�
            
            //���n
            //; �O�@�ӪŻy�y�A��ܳo�� while �j�餣�������ާ@�A
            //�u�O���нե� getchar()�A����Ū�촫��Ŭ���C
            //�T�O�b�i��U�@����J���e�A
            //�Ҧ��L�Ī��r�ų��w�g�Q�����A
            //����̤z�Z�U�@����J�C
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

// ��ܾǥͦ��Z�����
// �\��G��ܩҦ��ǥͪ����Z��ơA
// �]�A�m�W�B�Ǹ��B�ƾǦ��Z�B���z���Z�B�^�妨�Z�M�������Z�C
// �ϥΡG��ϥΪ̿����ܾǥͦ��Z�ɡA���榹��ơC

void displayStudentGrades(Student students[], int n)
{
    pressToContinue(); //���U�����M���ù��i�J�U�@�B �i
    printf("�ǥͩm�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t�������Z\n");
    // "\t"�Ψӹ��
    printf("===================================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t%d\t%d\t%d\t%.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }

    printf("\n�Ы��U���@��H��^�D���...");
    getch(); // ���ݥΤ����
}

// �j�M�ǥͦ��Z�����
// �\��G�ھڨϥΪ̿�J���m�W�j�M�ǥ͸�ơC
// �ϥΡG��ϥΪ̿�ܷj�M�ǥͦ��Z�ɡA���榹��ơC
// �B�J�G
// ���ܨϥΪ̿�J�n�j�M���ǥͩm�W�A�ñN�m�W�ഫ���p�g�r���C
// �M���Ҧ��ǥ͸�ơA�N�C�Ӿǥͪ��m�W�ഫ���p�g�r���A�ûP��J���m�W�i�����C
// �Y���ǰt���ǥ͡A��ܸӾǥͪ��Ҧ����Z��ơA�ó]�w found �� 1�C
// �Y�M�����Ҧ��ǥͤ������ǰt���m�W�A��� "��Ƥ��s�b" �����ܡC

void searchStudentGrades(Student students[], int n)
{
    char searchName[NAME_LEN];
    int found = 0;

    pressToContinue(); //���U�����M���ù��i�J�U�@�B �i
    printf("�п�J�n�j�M���ǥͩm�W�A�^�夣���j�p�g�G");
    scanf("%s", searchName);

    // �N�j�M�m�W�ഫ���p�g
    for (int i = 0; searchName[i]; i++)
    {
        searchName[i] = tolower(searchName[i]);
    }

    for (int i = 0; i < n; i++)
    {
        char tempName[NAME_LEN];
        strcpy(tempName, students[i].name);

        // �N�ǥͩm�W�ഫ���p�g
        for (int j = 0; tempName[j]; j++)
        {
            tempName[j] = tolower(tempName[j]);
        }

        if (strcmp(tempName, searchName) == 0)
        {
            printf("\n�ǥ͸�ơG\n");
            printf("�m�W�G%s\n", students[i].name);
            printf("�Ǹ��G%d\n", students[i].id);
            printf("�ƾǦ��Z�G%d\n", students[i].math);
            printf("���z���Z�G%d\n", students[i].physics);
            printf("�^�妨�Z�G%d\n", students[i].english);
            printf("�������Z�G%.1f\n", students[i].average);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n������Ƥ��s�b�C\n");
    }

    printf("\n�Ы��U���@���^�D���...");
    getch(); //
}

// ���Z�ƦW�����
void gradeRanking(Student students[], int n)
{

    // �ϥΪw�j�ƧǪk�ƧǦ��Z
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].average < students[j + 1].average)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("���Z�ƦW�A�Ѱ���C�G\n\n");
    printf("�ǥͩm�W\t�Ǹ�\t�������Z\n");
    printf("--------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }

    printf("\n�Ы��U���@��H��^�D���...");
    pressToContinue();
    }

// �T�{���}�����
void exitConfirmation()
{
    char choice;

    while (1)
    {
        printf("\n�T�w���}�H(Y/N)�A�����j�p�g�G");
        fflush(stdin);
        scanf("%c", &choice);
        choice = tolower(choice);

        if (choice == 'y')
        {
            printf("\n�{���Y�N�����C");
            exit(0);
        }
        else if (choice == 'n')
        {
            return;
        }
        else
        {
            printf("\n�L�Ŀﶵ�A�п�J Y �� N�A�����j�p�g�C\n");
        }
    }
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

//3.
//�p�G�g�{���e���U�i�H���Q�n�[�c���ܡA
//�{���N�i�H�֫ܦh�h�l���y�y�A�Y�Q��{���׾㪺���o�A
//�ե��n�ᤣ�֮ɶ��A�٫ܩȷ|��F�X���D�C

