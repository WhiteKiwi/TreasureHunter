#include "const.c"
#include <stdlib.h>
#include <time.h>

// 키보드 입력값들
#define ARROW_KEY 224
    #define UP_KEY 72
    #define LEFT_KEY 75
    #define RIGHT_KEY 77
    #define DOWN_KEY 80
#define ESC_KEY 27
#define ENTER_KEY 13


// 난이도 선택
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
                    // 위
                    if (choice != 0) {
                        choice--;
                        printLevel(choice);
                    }
                    break;
                    break;
                case DOWN_KEY:
                    // 아래
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


// 게임종료 여부를 검사하는 함수
static time_t startTime;
static int move_count = 0;
int checkGameOver() {
    // 제한시간을 넘으면 게임 오버
    if (time(NULL) - startTime >= LIMIT_TIME)
        return 0;
    // 제한 이동 횟수를 넘으면 게임 오버
    if (move_count >= LIMIT_COUNT)
        return 0;
    // monster type 1 - 괴물을 만나면 게임 오버
    if (monsterFlag) {
        return 0;
    }
    // 보물 12개를 모으면 종료
    if (score == 12) {
        return 0;
    }
    
    return 1;
}

// 방향키를 입력받아 좌표를 조정하는 함수
static time_t inThePuddleTime;
void inputKey() {
    int key;
    key = getch();

    if(key == ARROW_KEY) {
        key = getch();
        if (swampFlag) {
            // 만약 늪에 빠졌으면
            swampFlag--;
            // swampFlag만큼 움직이지 못함, 이동 횟수는 차감됨
            if (swampFlag) {
                move_count++;
                return;
            }
        } else if (puddleFlag){
            // 만약 웅덩이에 빠졌으면
            if (time(NULL) - inThePuddleTime >= LIMIT_PUDDLE_TIME[LEVEL])
                // 제한시간이 되면 flag를 내림
                puddleFlag = 0;
            else
                // 시간이 아직 남았으면 이동 불가, 이동 횟수는 유지
                return;
        }
        
        switch(key) {
            // 입력받은 방향으로 이동 가능하면 이동한다 
            case UP_KEY:
                // 위
                if (y != 1) {
                    move_count++;
                    y--;
                }
                break;
            case LEFT_KEY:
                // 왼쪽
                if (x != 2) {
                    move_count++;
                    x -= 2;
                }
                break;
            case RIGHT_KEY:
                // 오른쪽
                if (x < FIELD_SIZE*2-2) {
                    move_count++;
                    x += 2;
                }
                break;
            case DOWN_KEY:
                // 아래
                if (y != FIELD_SIZE-1) {
                    move_count++;
                    y++;
                }
                break;
        }
    } else if (key == ESC_KEY) {
        exit(0);
    } else if (key == 't' && IS_TEST) {
        score = 12;
    }
}
