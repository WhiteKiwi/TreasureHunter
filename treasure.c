// CreatedAt: 2020-06-01
// Author: 202011358 장지훈 
// 
// C 프로그래밍 (0451)
// 과제 #2: 보물 찾기

#include "print.c"
#include "flag.c"
#include "obstacle.c"


// 시작하기 전 초기화하는 함수
void initialize() {
    flags = malloc(sizeof(Flag) * FLAG_COUNT[LEVEL]);
    obstacles = malloc(sizeof(Obstacle) * OBSTACLE_COUNT[LEVEL]);

    // 시작 시간 기록
    startTime = time(NULL);
    // 깃발 초기화
    suffleFlags();
    // 장애물 초기화
    suffleObstacles();

    // Console 창 크기 조절
    system("mode con cols=150 lines=30"); 
}

int main(){
    srand(time(NULL));

    do {
        printf("난이도를 선택하세요(상: 1, 중: 2, 하: 3): ");
        scanf("%d", &LEVEL);
    } while (LEVEL != 1 && LEVEL != 2 && LEVEL != 3);
    LEVEL--;

    initialize();

    while(checkGameOver()){
        system("cls");
        printGame();
        inputKey();
        flagCheck();
        obstacleCheck();
    }

    // 게임 종료!
    system("cls");
    printf("게임 종료!\n");
    printf("당신의 점수는 %d점 입니다 :)", score);
    free(flags);

    getchar();
    return 0;
}