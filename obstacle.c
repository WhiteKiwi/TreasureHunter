#include <time.h>

// 장애물 섞는 함수
void suffleObstacles() {
    int i;

    for(i = 0; i < OBSTACLE_COUNT[LEVEL]; i++) {
        obstacles[i].x = ((rand() % (FIELD_SIZE - 1)) + 1) * 2;
        obstacles[i].y = (rand() % (FIELD_SIZE - 1)) + 1;
        obstacles[i].type = getRandomObstacleType();
    }
}

// - obstacle types - 
// 0: 바위
// 1: 웅덩이 (빠지면 3번 못움직임)
// 2: 물웅덩이 (빠지면 n초 못움직임)

// type 0
void bounce(){
    int c;
    // 랜덤한 방향으로 튕김
    c = rand() % 4;

    while(1) {
        switch(c) {
            printf("%d", c);
            case 0:
                if (y != 1) {
                    y -= 2;
                    return;
                }
                break;
            case 1:
                if (x != 2) {
                    x -= 4;
                    return;
                }
                break;
            case 2:
                if (x < FIELD_SIZE*2-2) {
                    x += 4;
                    return;
                }
                break;
            case 3:
                if (y != FIELD_SIZE-1) {
                    y += 2;
                    return;
                }
                break;
        }
    }
}
// type 1
void swamp(){
    if (!swampFlag) {
        swampFlag = LIMIT_SWAMP_COUNT[LEVEL];
    }
}
// type 2
void puddle(){
    if (!puddleFlag) {
        inThePuddleTime = time(NULL);
        puddleFlag = 1;
    }
}

// 깃발에 닿았는지 검사, 닿았다면 효과 실행
void obstacleCheck() {
    int i, type;

    for (i = 0; i < OBSTACLE_COUNT[LEVEL]; i++) {
        if (x == obstacles[i].x && y == obstacles[i].y){
            GAME_MESSAGE = OBSTACLE_TYPES[obstacles[i].type];
            
            switch (obstacles[i].type) {
                case 0:
                    bounce();
                    break;
                case 1:
                    swamp();
                    break;
                case 2:
                    puddle();
                    break;
            }
        }
    }
}

// obstacle type을 확률별로 반환 
int getRandomObstacleType() {
    // 깃발 별 나올 확률, 합이 100이 되어야 함
    const int PROB_OF_TYPE[3][NUM_OF_OBSTACLE_TYPE] = {
        { 50, 25, 25 },  // 상
        { 70, 15, 15 },  // 중
        { 90, 5, 5 }   //하
    };

    // 위에서 정한 확률에 따라 깃발 타입을 뽑아 반환함
    int i, t = 0;
    int dice = rand() % 100;
    for(i = 0; i < NUM_OF_OBSTACLE_TYPE; i++){
        t += PROB_OF_TYPE[LEVEL][i];
        if (dice <= t)
            return i;
    }
}
