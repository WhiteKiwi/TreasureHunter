#include <time.h>

// - flag types - 
// 0: 기본 (아무 효과 없음)
// 1: 포탈 (시작 지점으로 복귀)
// 2: 폭탄 (점수 초기화)
// 3: 탐지기 (보물 및 장애물의 위치 표시)
// 4: 보물 (점수 +1)

// type 0, and everywhen
void suffleFlags() {
    int i;

    // 플래그를 섞는다 (위치와 타입 모두)
    for(i = 0; i < FLAG_COUNT[LEVEL]; i++) {
        flags[i].x = ((rand() % (FIELD_SIZE - 1)) + 1) * 2;
        flags[i].y = (rand() % (FIELD_SIZE - 1)) + 1;
        flags[i].type = getRandomFlagType();
    }
    suffleObstacles();
}
// type 1
void respone() {
    // 출발 위치로 되돌아간다
    x = 2, y = 1;
}
// type 2
void boom() {
    // 점수를 초기화한다
    score = 0;
}
// type 3
int finderFlag = 0;
void finder() {
    // 탐지기를 킨다
    finderFlag = 1;
}
// type 4
void treasure() {
    // 보물을 찾으면 점수를 올리고 
    score++;
    // 탐지기를 끈다
    finderFlag = 0;
}

// 깃발에 닿았는지 검사, 닿았다면 효과 실행
void flagCheck() {
    int i, type;

    // 깃발 개수만큼 실행
    for (i = 0; i < FLAG_COUNT[LEVEL]; i++) {
        // 깃발의 위치와 내 위치가 같으면
        if (x == flags[i].x && y == flags[i].y){
            // 표시할 메세지 지정
            GAME_MESSAGE = FLAG_TYPES[flags[i].type];
            
            // 타입에 해당하는 효과 실행
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

            // 깃발은 셔플이 기본
            suffleFlags();
        }
    }
}

// flag type을 확률별로 반환 
int getRandomFlagType() {
    // 위에서 정한 확률에 따라 깃발 타입을 뽑아 반환함
    int i, t = 0;
    int dice = rand() % 100;
    for(i = 0; i < NUM_OF_FLAG_TYPE; i++){
        t += PROB_OF_FLAG_TYPE[LEVEL][i];
        if (dice < t)
            return i;
    }
}
