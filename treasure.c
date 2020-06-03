// CreatedAt: 2020-06-01
// Author: 202011358 장지훈
//
// C 프로그래밍 (0451)
// 과제 #2: 보물 찾기

#include "header/print.h"
#include "header/controls.h"
#include "header/flag.h"
#include "header/obstacle.h"


// 시작하기 전 초기화하는 함수
void initialize() {
    // 난이도 만큼 깃발과 장애물 생성
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

    // 난이도 선택
    chooseLevel();

    // 게임 초기화
    initialize();

    // 게임오버 전까지 계속 실행
    while(checkGameOver()){
        // 화면 초기화 후 새로 그림
        system("cls");
        printGame();

        // 입력 받아서 깃발과 장애물에 닿았는지 체크
        inputKey();
        flagCheck();
        obstacleCheck();
    }

    // 게임 종료!
    system("cls");
    printf("게임 종료!\n");
    printf("당신의 점수는 %d점 입니다 :)", score);

    // 메모리 정리
    free(flags);
    free(obstacles);

    getchar();
    return 0;
}