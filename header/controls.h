#pragma once
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
void chooseLevel();

// 게임종료 여부를 검사하는 함수
static time_t startTime;
static int move_count = 0;
int checkGameOver();

// 방향키를 입력받아 좌표를 조정하는 함수
static time_t inThePuddleTime;
void inputKey();
