#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void drawMenu()
{
	// �]���o�Ө�ƪ������Ovoid�A
	// �ҥH�b�ŧi���ɭ�
	// �p�A���̭��i�H���Ω����F��
	// �i�H�b�̭��]�w�Ѽ�(�ܼ�)
	// �]�w�@�Ө�ƥΨӵe���
	printf("--------------------------\n");
	printf("|                        |\n");
	printf("|                        |\n");
	printf("|                        |\n");
	printf("|  a. �e�X�����T����     |\n");
	printf("|  b. ��ܭ��k��         |\n");
	printf("|  c. ����               |\n");
	printf("|                        |\n");
	printf("|                        |\n");
	printf("--------------------------\n");
}

void drawRightTriangle(char ch)
{
	// �]�w�@�Ө�ƥΨӵe�V�k������T����
	if (ch < 'a' || ch > 'n')
	{
		// �P�_�Τ��J���r�����S���b�d��
		// ch: �Τ��J���r���A
		// �T�w�F�T���Ϊ����שM�̼e���@�檺�r���ơC
		// �]���p�G��Jc�A���L�O��a�ƨ�c�ĤT�Ӧr���A
		// �ҥH���שM�T���Ω���|���O���T�Ӧr�������פμe��

		do
		{
			fflush(stdin);
			// �C�����s�i�J�j��ɡA
			// ���M���@���ù��A���M�|�@���X�{��洣��
			printf("�Э��s��J���Ī��r��(a��n)�C\n");
			scanf("%c", &ch);
		} while (ch < 'a' || ch > 'n');
		// ��ch���Ȥ��b�n�D���d�򤺡A
		// �N�~��n�D�ϥΪ̭��s��J

		// return;�Ʋ�
		// �]���o�Ө�ƬOvoid�A
		// ���Oint�A�ҥH����return 0(����return����Ʀr)
		// �o�䤣��bdo-while ���U��return�A
		// �_�h�|�������L�U���Ψӵe�Ϫ��j��
		// �y�����~
	}

	for (char stable = 'a'; stable <= ch; stable++)
	{
		// char ch�O�ϥΪ̿�J���r���A
		// �N�O�T���Ω��䪺�̥��䪺"a"
		// stable: �T�w��

		for (char space = ch; space > stable; space--)
		{
			// �Ψӥ��L�Ů�

			// �Ʋ�
			// for�j�骺�B�⦡�|�b��Ӥj�A�����̫����

			// char space = ch�N��O:
			// ���]�n��X���O�U���o��
			//   c
			//  bc
			// abc
			// ��������ϥΪ̿�J�� "c"
			// ���]��space(�N��۪Ů�ƶq)
			// for(�Ů�ƶq = �ϥΪ̿�J���r�� ; ����:�Ů�ƶq�n�j��T�w�� a ;�C�`���@���Ů�ƶq��@)
			// �ҥH�p�W�ܷN�ϡA�n�e�X//  c���ɭԡA
			// ����c�N�J�A�P�_c>a�A��X�@�ӪŮ�A�M��r����@�ܦ�b
			// �P�_�r��b�j��a�A��X�@�ӪŮ�A�M��r����@�ܦ�a
			// �P�_�r��a���j��a�A�ҥH����X�Ů�
			// ��r������m�ѤU�@��for�j��N�r����J

			printf(" ");
			// �����L�X�Ů�A�H�N�r���V�k���
		}

		for (char i = ch - (stable - 'a'); i <= ch; i++)
		{
			// �Ψӥ��L�r��
			// char i
			// �@�˥�ch = c�|��,
			//   c
			//  bc
			// abc

			// char i = ch - ( stable- 'a')
			// �Ĥ@��i����c - (a-a)�Achar i�]����c
			// �ҥH�Ĥ@��ߤ@�@�Ӧr���]�O�Ĥ@�Ӧr���A�N�Oc
			// �ĤG�ơAc = c-(b-a);
			// char i �Q�ק�b�A�ҥH�ĤG�檺�Ĥ@�Ӧr���|�Ob�A
			// �M��b++�N�|�ܦ�c�A�ҥH�b�ĤG�檺b���k��ɤWc
			// �ĤT��
			// b = c-(c-a)
			// �ҥHchar i�Q�קאּa�A�ĤT��Ĥ@�Ӧr���Oa
			// �ѤU���H������
			printf("%c", i); // �ھڤW�����޿�A��r��(�r��)��X��ù�
		}
		printf("\n"); // �C��X��L�k��X�r���A�N����
	}
	printf("\n�����N���^�D���...");
	getch();
}

void drawMultiplicationTable(int n)
{
	if (n < 1 || n > 9)
	{
		// �p�Gn���b1�M9����
		do
		{
			fflush(stdin);
			// �N�M���ù����s�n�D�ϥΪ̿�J�A�����J���T�d�򤺪����
			printf("�п�J���Ī����(1��9)�C\n");
			scanf("%d", &n);

		} while (n < 1 || n > 9);
		// do-while��while()�n�[����
	}

	for (int i = 1; i <= n; i++)
	{
		// �Q��X��ù��W���E�E���k�����ƻP�Q���ƪ��̤j�Ȫ��j�p�A
		// ����W�L�ϥΪ̿�J���Ʀr
		// �ҥHn�Ȭ�5�A���̤j���p�⦡�N�O5*5=25
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", j, i, i * j);
			// " - " :�����
		}
		printf("\n");
	}

	printf("\n�����N���^�D���...");
	getch();
	// getch(); �w�g���Q�w�q�F
	// �u�O�Q��bint main�A�ҥH��Ƹ̭��N���ΦA�w�q
}

int main()
{
	int passwordAttempts = 0; // �x�s�K�X���~����
	int password = 2024;	  // ���T�K�X
	int inputPassword;		  // �x�s�ϥΪ̿�J���K�X

	printf("�w��e��\n");
	printf("                       |                   \n");  // ���L�Ĥ@��
	printf("                __\\--__|_ \n");				  // ���L�ĤG��
	printf("II=======OOOOO[/ �� ��ǩZ�J ___|           \n");  // ���L�ĤT��
	printf("          _____\\______|/-----. \n");			  // ���L�ĥ|��
	printf("        /____________________|              \n"); // ���L�Ĥ���
	printf("         \\��������������������������������������/ \n");			  // ���L�Ĥ���
	printf("           ~~~~~~~~~~~~~~~~\n");				  // �H�U�N���O���L
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                              \n");
	printf("                                              \n");
	printf("�@�@�D�D�D�D�l�l�D..�D�i�l �� ����� ..../\n");
	printf("�@�@���i�f�f�i�i�f�f�i�i�f�f�f�f�f�f�f�f�f�f�f�f�f�f�f�i�i�i�i�i�i�i��\n");
	printf(" �@ �D���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i��\n");
	printf("����㢪�i�i�i�i�i�i�i�i�Ǵ��ۨ������i�������\n");
	printf("�����~~���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�������\n");
	printf("�����~~~~���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�������\n");
	printf("�����~~~~~~���i�i�i�i�i�i�i�i�i�i�i�������\n");
	printf("����    ��� ���    ��������\n");
	printf("�����   ������   ����� ���  �� ��\n");

	// �B�J1�Ѧ��}�l
	printf("����L�W�����N��A�M���e��\n");

	char end; // �]�w�@���ܼƬ�end�A�N����L�W������@�Ӧr���A���U��N�|�M���ù��e��
	end = getche();
	system("cls"); // �M�z�ù��e��

	// �Ʋ�
	// getche();�\��O:
	// ���U��L�W�����N����A�H�F��Y�ӥت��A
	// getch();�O���b�׺ݱ���x�W�A�ݤ���
	// �ۤv���F�ƻ����A
	// getche();�ݱo��ۤv���F�ƻ����

	// �B�J2�Ѧ��}�l

	// �Ʋ�:

	// ����o�˼gprintf("%d\n,password");
	// �o��%d�|�ܦ��@�ӶýX�A
	// �]���O�q�O����ݭȤ��H�K���@�Ӽ�

	while (passwordAttempts < 3)
	{
		printf("�п�J�|��ƪ��K�X�G");
		scanf("%d", &inputPassword);

		if (inputPassword == password)
		{
			break;
		}
		else
		{
			printf("�K�X��J���~�A�Э��s��J�C\n");
			passwordAttempts++;
		}
	}

	if (passwordAttempts == 3)
	{
		printf("�K�X��J���~���ƹF��T���A�{���Y�N�����C\n");
		return 0;
	}

	char choice; // �]�@���ܼ��x�s�ϥΪ̿�J���r��
	do
	{
		system("cls");
		drawMenu(); // �I�s�W������Ƶe�X���

		printf("�п�J��ܡG");
		fflush(stdin); // �M���w�s
		scanf("%c", &choice);

		switch (choice)
		{
		case 'a':
		case 'A':
		{
			system("cls"); // �M�z�ù��W����X�A���e��²��
			// �M�Ω�windows�t�Τ����ާ@���O�A�u��windows�t�Υi�H��
			printf("�п�J�r��(a��n)�G");
			char ch;
			fflush(stdin); // �M�z�зǿ�J�w�İϤ��S���Q�B�z���ƾ�
			// �p�G�{�������e��Ū���ާ@�]�p scanf�^������ӥΤ��J���Ҧ��r�šA
			// �Ѿl���r�űN�d�b��J�w�İϤ��C
			// �Ҧp�A�Τ��J "abc" ���{���uŪ���F�Ĥ@�Ӧr�šA
			// �ѤU�� "bc" ���M�b�w�İϤ��C

			// ��{�����նi��U�@��Ū���ɡA
			// �o�ǳѾl�r�ťi��|�Q���~�a�����s����J�A
			// �ɭP�{���欰���`�ο��~���ƾڳB�z�C
			scanf("%c", &ch);
			if (ch == 'a')
			{
				printf("�e���X���`���T���ΡA�p�U�ϩҥ� �A�u���@�� a ��!!!!! \n");
				drawRightTriangle(ch);
				// ��ch�o���ܼƥᵹ�e�T���Ϊ����
			}
			else
			{
				// printf("�Ϯצp�U: \n");
				drawRightTriangle(ch); // �I�s�Ψӵe�T���Ϊ����
			}
			break;
		}
		case 'b':
		case 'B':
		{
			system("cls");
			int n;
			printf("�п�J�@��1��9����ơG");
			fflush(stdin);
			scanf("%d", &n);
			drawMultiplicationTable(n);
			// ��n�ᵹ�E�E���k�����
			break;
		}
		case 'c':
		case 'C':
		{
			system("cls");
			char confirm; // �]�w�@���ܼƥΨ� confirm (�T�{)�ϥΪ̪��ʧ@
			printf("Continue? (y/n): ");
			fflush(stdin);
			scanf(" %c", &confirm);

			if (confirm == 'n' || confirm == 'N' || confirm == 'y' || confirm == 'Y')
			{
				// �p�Gconfirm�On��N��y��Y�A�N�A�P�_�ON�٬OY
				if (confirm == 'y' || confirm == 'Y')
				{
					drawMenu(); // �I�s�W������Ƶe�X���
					printf("�п�J��ܡG");
					fflush(stdin);
					scanf("%c", &choice);
					break;
					// break;
					// �o�˼g�~�����{��Ū�����檺��ܡA
					// ���M�|�d�bswitch�j���ح�
				}
				else
				{
					printf("�����{��\n");
					return 1;
				}
			}
			else
			{
				do
				{
					// ���J���r�����O�o�|�ӫ��w�r���A
					// �N���ƭn�D��J�A����ϥΪ̿�J���T
					fflush(stdin);
					printf("�п�J�ŦX�n�D������\n");
					scanf("%c", &confirm);

				} while (confirm != 'n' || confirm != 'N' || confirm != 'y' || confirm != 'Y');
				// while�Bif���p�A�������n�����Y�B��� == �Ӫ�� "����"�A
				// ����ν�ȹB��� " = "��� "����" �o�ӷ���
				// ��ϥΪ̿�J���r�����šA�N�A���i�J�j��
			}

			// �H�U���`�N
			// �o�˷|���������{���A���ŭn�D
			/*
			if (confirm == 'n' || confirm == 'N')
			{
				printf("�{�������C\n");
				return 0;
			} else if (confirm != 'y' && confirm != 'Y')
			{
				printf("�п�J���Ī����(y/n)�C\n");
			}
			*/
			break;
		}
		}
	} while (choice != 'c' && choice != 'C');
	// ��ϥΪ̿�J���r�����Oc�]���OC�A�N���ưj��

	return 0; // �{������
}

// 1.�o�����F��F�Ѱj��A
// �ҥH�յ۸ԲӪ������e�T���Ϊ��L�{�A
// �]�Ǧ��V�m�ڪ��޿�A
// �e�y�{�Ϫ��ɭԤ]�|����o������

// 2.�o���]��F�Ѩ�ƪ��N�q�A
// ���ƤΥD�{�������Y�P�ϥΤ�k��[���m
// �]��F�Ѧۤv���޿��O

// 3.�����]�O�o����ì�̦h�������A
// �ڷQ�O�y�L�F��github�����Τ覡�A
// �o�����ܷP�§U�Ъ�����
// �̫ᬰ�F��K�g�{���A�S�A�Ƿ|�ϥ�VScode�C