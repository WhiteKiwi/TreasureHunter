#include <time.h>

// - flag types - 
// 0: 깃발 셔플
// 1: 시작 지점으로 복귀
// 2: 점수 초기화
// 3: 보물의 위치 표시
// 4: 보물

// type 0
void suffleFlags() {
    int i;

    for(i = 0; i < FLAG_COUNT[LEVEL]; i++) {
        flags[i].x = ((rand() % (FIELD_SIZE - 1)) + 1) * 2;
        flags[i].y = (rand() % (FIELD_SIZE - 1)) + 1;
        flags[i].type = getRandomFlagType();
    }
    suffleObstacles();
}
// type 1
void respone() {
    x = 2, y = 1;
}
// type 2
void boom() {
    score = 0;
}
// type 3
int finderFlag = 0;
void finder() {
    finderFlag = 1;
}
// type 4
void treasure() {
    score++;
    finderFlag = 0;
}

// 깃발에 닿았는지 검사, 닿았다면 효과 실행
void flagCheck() {
    int i, type;

    for (i = 0; i < FLAG_COUNT[LEVEL]; i++) {
        if (x == flags[i].x && y == flags[i].y){
            GAME_MESSAGE = FLAG_TYPES[flags[i].type];
            
            switch (flags[i].type) {
                case 1:
                    respone();
                    break;
                case 2:
                    boom();
                    break;
                case 3:
                    finder();
                    break;
                case 4:
                    treasure();
                    break;
            }
            // 셔플은 기본
            suffleFlags();
        }
    }
}

// flag type을 확률별로 반환 
int getRandomFlagType() {
    // 깃발 별 나올 확률, 합이 100이 되어야 함
    const int PROB_OF_TYPE[3][NUM_OF_FLAG_TYPE] = {
        { 50, 30, 10, 0, 10 },  // 상
        { 40, 25, 5, 10, 20 },  // 중
        { 40, 17, 3, 10, 30 }   //하
    };

    // 위에서 정한 확률에 따라 깃발 타입을 뽑아 반환함
    int i, t = 0;
    int dice = rand() % 100;
    for(i = 0; i < NUM_OF_FLAG_TYPE; i++){
        t += PROB_OF_TYPE[LEVEL][i];
        if (dice <= t)
            return i;
    }
}
