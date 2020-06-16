#include <stdio.h>
#include "control.c"
#include <Windows.h>

#define USER_ICON "��"
#define FLAG_ICON "��"
#define TREASURE_ICON "��"
#define OBSTACLE_ICON "��"
#define MONSTER_ICON "��"

// Ŀ�� �̵��ϴ� �Լ�
void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ������ �׸��� �Լ�
void printGame() {
    system("cls");

    printField();
    printFlags();
    printObstacles();
    printMonsters();
    printInfo();
    printUser();
}

// ��
// ���� �׸��� �Լ�
void printUser() {
    gotoxy(x, y);
    printf(USER_ICON);

    if (IS_TEST)
        printf("%d, %d", x, y);
}

// ������
// ��� ��� �Լ�
extern int finderFlag;
void printFlags() {
    int i;

    for(i = 0; i < FLAG_COUNT[LEVEL]; i++){
        gotoxy(flags[i].x, flags[i].y);
        if (flags[i].type == 4 && (finderFlag || IS_TEST)) {
            printf(TREASURE_ICON);
        } else {
            printf(FLAG_ICON);
        }

        if (IS_TEST)
            printf("%d", flags[i].type);
    }
}

// �͢͢�
// ��ֹ� ��� �Լ�
void printObstacles() {
    int i;

    for(i = 0; i < OBSTACLE_COUNT[LEVEL]; i++){
        gotoxy(obstacles[i].x, obstacles[i].y);
        if (finderFlag || IS_TEST) {
            printf(OBSTACLE_ICON);
        } else {
            printf(FLAG_ICON);
        }

        if (IS_TEST) {
            printf("-%d", obstacles[i].type);
            if (obstacles[i].type == 1)
                printf("/%d", swampFlag);
            else if (obstacles[i].type == 2)
                printf("/%d", puddleFlag);
        }
    }
}

// ������
// ���� ��� �Լ�
void printMonsters() {
    int i;

    for(i = 0; i < MONSTER_COUNT[LEVEL]; i++){
        gotoxy(monsters[i].x, monsters[i].y);
        if (finderFlag || IS_TEST) {
            printf(MONSTER_ICON);
        } else {
            printf(FLAG_ICON);
        }

        if (IS_TEST) {
            printf("-%d", monsters[i].type);
        }
    }
}

// ������������
// ��    ��
// ������������
// �� �׸��� �Լ�
void printField() {
    int i, j;
    
    gotoxy(0, 0);

    // �� ���� ���
    printf("��");
    for (i = 0; i < FIELD_SIZE*2-1; i++)
        printf("��");
    printf("��\n");
    
    // �߰� ���
    // �߰� �� �����
    for(i = 0; i < FIELD_SIZE-1; i++){
        printf("��");
        gotoxy(FIELD_SIZE*2, i+1);
        printf("��\n");
    }
    
    // ������ �� ���
    printf("��");
    for(i = 0; i < FIELD_SIZE*2-1; i++)
        printf("��");
    printf("��\n");
}

// ������ ���� ���� �׸��� �Լ�
void printInfo() {
    // ��� ��ġ
    const int INFO_X = FIELD_SIZE*2 + 5, INFO_Y = 3;
    gotoxy(INFO_X, INFO_Y);
    printf("===== System: %s =====", GAME_MESSAGE);
    gotoxy(INFO_X, INFO_Y + 1);
    printf("���� ����: %d��", score);
    gotoxy(INFO_X, INFO_Y + 2);
    printf("���� �ð�: %d��", LIMIT_TIME - (time(NULL) - startTime));
    gotoxy(INFO_X, INFO_Y + 3);
    printf("���� �̵� Ƚ��: %dȸ", LIMIT_COUNT - move_count);

    gotoxy(INFO_X, INFO_Y + 6);
    printf("======== ���� ���� ========");
    gotoxy(INFO_X, INFO_Y + 7);
    printf("���� �ð�, ���� �̵� Ƚ�� ���� �ִ��� ���� ������ ã�Ƴ��� �����Դϴ�.");
    gotoxy(INFO_X, INFO_Y + 8);
    printf("4 ������ ��߰� 3 ������ ��ֹ� �׸��� 2 ������ ���Ͱ� �־��~");
    gotoxy(INFO_X, INFO_Y + 9);
    printf("��ź�� ������ �ֽ� ���� ��������� ���ư� �� ������ �����ϼ���...!!");
    gotoxy(INFO_X, INFO_Y + 10);
    printf("�׸��� ���ù����� ������ ���������� �����ϼ���...!");

    gotoxy(INFO_X, INFO_Y + 12);
    printf("��� �Ǵ� ��ֹ�: %s", FLAG_ICON);
    gotoxy(INFO_X, INFO_Y + 13);
    printf("Ž���� ȹ�� �� ����: %s", TREASURE_ICON);
    gotoxy(INFO_X, INFO_Y + 14);
    printf("Ž���� ȹ�� �� ��ֹ�: %s", OBSTACLE_ICON);

    if(IS_TEST) {
        gotoxy(INFO_X, INFO_Y + 16);
        printf("DEBUG_MSG: %s", DEBUG_MSG);
    }
}

// ���̵� ���� ������ �׸��� �Լ�
void printLevel(int choice) {
    int X=66, Y;
    int i;
    char level[][3] = { "��", "��", "��" };
    
    system("cls");
    printf("\n");
    printf("\t==================================  ���̵��� �����ϼ���!  ================================== \n");
    printf("\t�س��̵��� ���������� ��߰� ��ֹ��� ���� �������� ������ ȿ���� �߻��� Ȯ���� �þ�ϴ� :)");

    for (i = 0; i < 3; i++){
        Y = 7 * i + 6;
        if (choice == i) {
            printf("\n\n\n");
            printf("\t\t\t\t\t������������������������������������������������������\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(49, Y+1);
            printf("���̵�: %s", level[i]);
            gotoxy(X, Y+1);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y+2);
            printf("��\n");

            printf("\t\t\t\t\t������������������������������������������������������");
        } else {
            printf("\n\n\n");
            printf("\t\t\t\t\t������������������������������������������������������\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(49, Y+1);
            printf("���̵�: %s", level[i]);
            gotoxy(X, Y+1);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y+2);
            printf("��\n");


            printf("\t\t\t\t\t������������������������������������������������������");
        }
    }
}

// ���� ������ �׸��� �Լ�
void printMain(int choice) {
    int X=66, Y;
    int i;
    char level[][3] = { "��", "��", "��" };
    
    system("cls");
    printf("\n");
    printf("\t==================================  �޴��� �����ϼ���!  ================================== \n");

    for (i = 0; i < 3; i++){
        Y = 7 * i + 6;
        if (choice == i) {
            printf("\n\n\n");
            printf("\t\t\t\t\t������������������������������������������������������\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(49, Y+1);
            printf("���̵�: %s", level[i]);
            gotoxy(X, Y+1);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y+2);
            printf("��\n");

            printf("\t\t\t\t\t������������������������������������������������������");
        } else {
            printf("\n\n\n");
            printf("\t\t\t\t\t������������������������������������������������������\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(49, Y+1);
            printf("���̵�: %s", level[i]);
            gotoxy(X, Y+1);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y+2);
            printf("��\n");


            printf("\t\t\t\t\t������������������������������������������������������");
        }
    }
}

// �޴� �׸��� �Լ�
void printMenu(int choice) {
    int X=66, Y;
    int i;
    char menu[][14] = { "����ȭ��", "�ٽý���", "��������" };
    
    system("cls");
    printf("\n");
    printf("\t====================================  �޴��� �����ϼ���!  ==================================== \n");

    for (i = 0; i < 3; i++){
        Y = 7 * i + 6;
        if (choice == i) {
            printf("\n\n\n");
            printf("\t\t\t\t\t������������������������������������������������������\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(50, Y+1);
            printf("%s", menu[i]);
            gotoxy(X, Y+1);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y+2);
            printf("��\n");

            printf("\t\t\t\t\t������������������������������������������������������");
        } else {
            printf("\n\n\n");
            printf("\t\t\t\t\t������������������������������������������������������\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(50, Y+1);
            printf("%s", menu[i]);
            gotoxy(X, Y+1);
            printf("��\n");

            printf("\t\t\t\t\t��");
            gotoxy(X, Y+2);
            printf("��\n");


            printf("\t\t\t\t\t������������������������������������������������������");
        }
    }
}