#include "header/print.h"

// 커서 이동하는 함수
void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 게임을 그리는 함수
void printGame() {
    printField();
    printFlags();
    printObstacles();
    printInfo();
    printUser();
}

// ◆
// 유저 그리는 함수
void printUser() {
    gotoxy(x, y);
    printf("☆");

    //if (IS_TEST)
    //printf("%d, %d", x, y);
}

// ▶▶▶
// 깃발 찍는 함수
extern int finderFlag;
void printFlags() {
    int i;

    for(i = 0; i < FLAG_COUNT[LEVEL]; i++){
        gotoxy(flags[i].x, flags[i].y);
        if (flags[i].type == 4 && finderFlag) {
            printf("◎");
        } else {
            printf("▶");
        }

        if (IS_TEST)
            printf("%d", flags[i].type);
    }
}

// ♨♨♨
// 장애물 찍는 함수
void printObstacles() {
    int i;

    for(i = 0; i < OBSTACLE_COUNT[LEVEL]; i++){
        gotoxy(obstacles[i].x, obstacles[i].y);
        if (finderFlag) {
            printf("♨");
        } else {
            printf("▶");
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

// ┌────┐
// │    │
// └────┘
// 판 그리는 함수
void printField() {
    int i, j;

    gotoxy(0, 0);

    // 맨 윗줄 출력
    printf("┌");
    for (i = 0; i < FIELD_SIZE*2-1; i++)
        printf("─");
    printf("┐\n");

    // 중간 출력
    // 중간 한 줄출력
    for(i = 0; i < FIELD_SIZE-1; i++){
        printf("│");
        gotoxy(FIELD_SIZE*2, i+1);
        printf("│\n");
    }

    // 마지막 줄 출력
    printf("└");
    for(i = 0; i < FIELD_SIZE*2-1; i++)
        printf("─");
    printf("┘\n");
}

// 우측에 게임 정보 그리는 함수
void printInfo() {
    // 출력 위치
    const int INFO_X = FIELD_SIZE*2 + 5, INFO_Y = 3;
    gotoxy(INFO_X, INFO_Y);
    printf("===== System: %s =====", GAME_MESSAGE);
    gotoxy(INFO_X, INFO_Y + 1);
    printf("현재 점수: %d점", score);
    gotoxy(INFO_X, INFO_Y + 2);
    printf("남은 시간: %d초", LIMIT_TIME - (time(NULL) - startTime));
    gotoxy(INFO_X, INFO_Y + 3);
    printf("남은 이동 횟수: %d회", LIMIT_COUNT - move_count);

    gotoxy(INFO_X, INFO_Y + 6);
    printf("======== 게임 설명 ========");
    gotoxy(INFO_X, INFO_Y + 7);
    printf("제한 시간, 제한 이동 횟수 내에 최대한 많은 보물을 찾아내는 게임입니다.");
    gotoxy(INFO_X, INFO_Y + 8);
    printf("4 종류의 깃발과 3 종류의 장애물이 있어요~");
    gotoxy(INFO_X, INFO_Y + 8);
    printf("폭탄을 찾으면 애써 모은 보물들까지 날아갈 수 있으니 조심하세요...!!");

    gotoxy(INFO_X, INFO_Y + 10);
    printf("깃발 또는 장애물: ▶");
    gotoxy(INFO_X, INFO_Y + 11);
    printf("탐지기 획득 시 보물: ◎");
    gotoxy(INFO_X, INFO_Y + 12);
    printf("탐지기 획득 시 장애물: ♨");

    if(IS_TEST) {
        gotoxy(INFO_X, INFO_Y + 14);
        printf("DEBUG_MSG: %s", DEBUG_MSG);
    }
}

// 난이도 선택 페이지 그리는 함수
void printLevel(int choice) {
    int X=66, Y;
    int i;
    char level[][3] = { "상", "중", "하" };

    system("cls");
    printf("\n");
    printf("\t==================================  난이도를 선택하세요!  ================================== \n");
    printf("\t※난이도가 높아질수록 깃발과 장애물의 수가 많아지고 안좋은 효과가 발생할 확률이 늘어납니다 :)");

    for (i = 0; i < 3; i++){
        Y = 7*i + 6;
        if (choice == i) {
            printf("\n\n\n");
            printf("\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

            printf("\t\t\t\t\t┃");
            gotoxy(X, Y);
            printf("┃\n");

            printf("\t\t\t\t\t┃");
            gotoxy(49, Y+1);
            printf("난이도: %s", level[i]);
            gotoxy(X, Y+1);
            printf("┃\n");

            printf("\t\t\t\t\t┃");
            gotoxy(X, Y+2);
            printf("┃\n");

            printf("\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━┛");
        } else {
            printf("\n\n\n");
            printf("\t\t\t\t\t┌─────────────────────────┐\n");

            printf("\t\t\t\t\t│");
            gotoxy(X, Y);
            printf("│\n");

            printf("\t\t\t\t\t│");
            gotoxy(49, Y+1);
            printf("난이도: %s", level[i]);
            gotoxy(X, Y+1);
            printf("│\n");

            printf("\t\t\t\t\t│");
            gotoxy(X, Y+2);
            printf("│\n");


            printf("\t\t\t\t\t└─────────────────────────┘");
        }
    }
}
