#include "const.c"
#include <stdlib.h>
#include <time.h>

// Ű���� �Է°���
#define ARROW_KEY 224
    #define UP_KEY 72
    #define LEFT_KEY 75
    #define RIGHT_KEY 77
    #define DOWN_KEY 80
#define ESC_KEY 27
#define ENTER_KEY 13


// ���� ����
void setting() {
    int choice = 0;
    int key;
    int level;
    int num;

    printSetting(choice);
    while(1) {
        key = getch();
        if (key == ARROW_KEY) {
            key = getch();
            switch(key) {
                case UP_KEY:
                    // ��
                    if (choice != 0) {
                        choice--;
                        printSetting(choice);
                    }
                    break;
                    break;
                case DOWN_KEY:
                    // �Ʒ�
                    if (choice != 2) {
                        choice++;
                        printSetting(choice);
                    }
                    break;
            }
        } else if (key == ESC_KEY) {
            return;
        } else if (key == ENTER_KEY) {
            if (choice == 0) { // �� ũ�� ����
                system("cls");
                printf("���ϴ� �� ũ�⸦ �Է��ϼ���: ");
                scanf("%d", &FIELD_SIZE);
            } else if (choice == 1) { // ��� ����
                system("cls");
                printf("���̵��� ���� ��� ����: [%d - %d - %d]\n\n", FLAG_COUNT[0], FLAG_COUNT[1], FLAG_COUNT[2]);
                printf("���̵�(��: 3, ��: 2, ��: 1)�� ���ϴ� ��� ������ ���ʷ� �Է��ϼ���: ");
                scanf("%d", &level);
                scanf("%d", &FLAG_COUNT[3-level]);

            } else if (choice == 2) { // ��ֹ� ����
                system("cls");
                printf("���̵��� ���� ��ֹ� ����: [%d - %d - %d]\n\n", OBSTACLE_COUNT[0], OBSTACLE_COUNT[1], OBSTACLE_COUNT[2]);
                printf("���̵�(��: 3, ��: 2, ��: 1)�� ���ϴ� ��ֹ� ������ ���ʷ� �Է��ϼ���: ");
                scanf("%d", &level);
                scanf("%d", &OBSTACLE_COUNT[3-level]);
            }

            printf("\n����Ǿ����ϴ�\n");
            getch();
            return;
        }
    }
}

// ���� ������ ����
int chooseMain() {
    int choice = 0;
    int key;

    printMain(choice);
    while(1) {
        key = getch();
        if (key == ARROW_KEY) {
            key = getch();
            switch(key) {
                case UP_KEY:
                    // ��
                    if (choice != 0) {
                        choice--;
                        printMain(choice);
                    }
                    break;
                    break;
                case DOWN_KEY:
                    // �Ʒ�
                    if (choice != 2) {
                        choice++;
                        printMain(choice);
                    }
                    break;
            }
        } else if (key == ESC_KEY) {
            exit(0);
        } else if (key == ENTER_KEY) {
            return choice;
        }
    }
}

// ���̵� ����
void chooseLevel() {
    int choice = 0;
    int key;

    printLevel(choice);
    while(1) {
        key = getch();
        if (key == ARROW_KEY) {
            key = getch();
            switch(key) {
                case UP_KEY:
                    // ��
                    if (choice != 0) {
                        choice--;
                        printLevel(choice);
                    }
                    break;
                    break;
                case DOWN_KEY:
                    // �Ʒ�
                    if (choice != 2) {
                        choice++;
                        printLevel(choice);
                    }
                    break;
            }
        } else if (key == ESC_KEY) {
            exit(0);
        } else if (key == ENTER_KEY) {
            LEVEL = choice;
            return;
        }
    }
}

// �޴� ����
void chooseMenu() {
    int choice = 0;
    int key;

    printMenu(choice);
    while(1) {
        key = getch();
        if (key == ARROW_KEY) {
            key = getch();
            switch(key) {
                case UP_KEY:
                    // ��
                    if (choice != 0) {
                        choice--;
                        printMenu(choice);
                    }
                    break;
                    break;
                case DOWN_KEY:
                    // �Ʒ�
                    if (choice != 2) {
                        choice++;
                        printMenu(choice);
                    }
                    break;
            }
        } else if (key == ESC_KEY) {
            return;
        } else if (key == ENTER_KEY) {
            if (choice == 0) { // ����ȭ��
                main();
            } else if (choice == 1) { // �ٽý���
                startGame();
            } else if (choice == 2) { // ��������
                exit(0);
            }

            return;
        }
    }
}

// �������� ���θ� �˻��ϴ� �Լ�
static time_t startTime;
static int move_count = 0;
int checkGameOver() {
    // ���ѽð��� ������ ���� ����
    if (time(NULL) - startTime >= LIMIT_TIME)
        return 0;
    // ���� �̵� Ƚ���� ������ ���� ����
    if (move_count >= LIMIT_COUNT)
        return 0;
    // monster type 1 - ������ ������ ���� ����
    if (monsterFlag) {
        return 0;
    }
    // ���� 12���� ������ ����
    if (score == 12) {
        return 0;
    }
    
    return 1;
}

// ����Ű�� �Է¹޾� ��ǥ�� �����ϴ� �Լ�
static time_t inThePuddleTime;
void inputKey() {
    int key;
    key = getch();

    if(key == ARROW_KEY) {
        key = getch();
        if (swampFlag) {
            // ���� �˿� ��������
            swampFlag--;
            // swampFlag��ŭ �������� ����, �̵� Ƚ���� ������
            if (swampFlag) {
                move_count++;
                return;
            }
        } else if (puddleFlag){
            // ���� �����̿� ��������
            if (time(NULL) - inThePuddleTime >= LIMIT_PUDDLE_TIME[LEVEL])
                // ���ѽð��� �Ǹ� flag�� ����
                puddleFlag = 0;
            else
                // �ð��� ���� �������� �̵� �Ұ�, �̵� Ƚ���� ����
                return;
        }
        
        switch(key) {
            // �Է¹��� �������� �̵� �����ϸ� �̵��Ѵ� 
            case UP_KEY:
                // ��
                if (y != 1) {
                    move_count++;
                    y--;
                }
                break;
            case LEFT_KEY:
                // ����
                if (x != 2) {
                    move_count++;
                    x -= 2;
                }
                break;
            case RIGHT_KEY:
                // ������
                if (x < FIELD_SIZE*2-2) {
                    move_count++;
                    x += 2;
                }
                break;
            case DOWN_KEY:
                // �Ʒ�
                if (y != FIELD_SIZE-1) {
                    move_count++;
                    y++;
                }
                break;
        }
    } else if (key == ESC_KEY) {
        chooseMenu();
    } else if (key == 't' && IS_TEST) {
        score = 12;
    }
}
