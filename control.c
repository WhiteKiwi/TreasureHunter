#include "const.c"
#include <stdlib.h>
#include <time.h>

static time_t inThePuddleTime;
static time_t startTime;
static int move_count = 0;

// 게임종료 여부를 검사하는 함수
int checkGameOver() {
    if (time(NULL) - startTime >= LIMIT_TIME)
        return 0;
    if (move_count >= LIMIT_COUNT)
        return 0;
    
    return 1;
}

// 방향키를 입력받아 좌표를 조정하는 함수
void inputKey() {
    int key;
    key = getch();

    if(key == 224) {
        key = getch();
        if (swampFlag) {
            swampFlag--;
            if (swampFlag) {
                move_count++;
                return;
            }
        } else if (puddleFlag){
            if (time(NULL) - inThePuddleTime >= LIMIT_PUDDLE_TIME[LEVEL])
                puddleFlag = 0;
            else
                return;
        }
        
        switch(key) {
            case 72:
                // 위
                if (y != 1) {
                    move_count++;
                    y--;
                }
                break;
            case 75:
                // 왼쪽
                if (x != 2) {
                    move_count++;
                    x -= 2;
                }
                break;
            case 77:
                // 오른쪽
                if (x < FIELD_SIZE*2-2) {
                    move_count++;
                    x += 2;
                }
                break;
            case 80:
                // 아래
                if (y != FIELD_SIZE-1) {
                    move_count++;
                    y++;
                }
                break;
        }
    } else if(key == 27) {
        exit(0);
    }
}
