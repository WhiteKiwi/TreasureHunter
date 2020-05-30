#include <time.h>

// - obstacle types - 
// 0: 바위 (튕겨냄)
// 1: 늪 (빠지면 n번 못움직임)
// 2: 물웅덩이 (빠지면 n초 못움직임)

// 장애물 섞는 함수
void suffleObstacles() {
    int i;

    // 장애물을 섞는다 (위치와 타입 모두)
    for(i = 0; i < OBSTACLE_COUNT[LEVEL]; i++) {
        obstacles[i].x = ((rand() % (FIELD_SIZE - 1)) + 1) * 2;
        obstacles[i].y = (rand() % (FIELD_SIZE - 1)) + 1;
        obstacles[i].type = getRandomObstacleType();
    }
}

// type 0
void bounce(){
    int c;
    // 랜덤한 방향으로 튕김
    c = rand() % 4;

    // 튕긴 위치가 밖이 아닐 때까지 재실행
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
        // 늪에 빠지지 않았으면 swampFlag를 난이도에 맞춰 이동제한 횟수를 대입 
        swampFlag = LIMIT_SWAMP_COUNT[LEVEL];
    }
}
// type 2
void puddle(){
    if (!puddleFlag) {
        // 웅덩이에 빠지지 않았으면 현재 시간을 기록하고 puddleFlag를 킴
        inThePuddleTime = time(NULL);
        puddleFlag = 1;
    }
}

// 깃발에 닿았는지 검사, 닿았다면 효과 실행
void obstacleCheck() {
    int i, type;

    // 장애물 개수만큼 실행
    for (i = 0; i < OBSTACLE_COUNT[LEVEL]; i++) {
        // 장애물의 위치와 내 위치가 같으면
        if (x == obstacles[i].x && y == obstacles[i].y){
            // 표시할 메세지 지정
            GAME_MESSAGE = OBSTACLE_TYPES[obstacles[i].type];
            
            // 타입에 해당하는 효과 실행
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
    // 난이도에 따른 타입별 장애물이 나올 확률, 합이 100이 되어야 함
    // - obstacle types - 
    // 0: 바위 (튕겨냄)
    // 1: 늪 (빠지면 n번 못움직임)
    // 2: 물웅덩이 (빠지면 n초 못움직임)
    const int PROB_OF_TYPE[3][NUM_OF_OBSTACLE_TYPE] = {
        { 50, 25, 25 }, // 상
        { 70, 15, 15 }, // 중
        { 90, 5, 5 }    // 하
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
