#pragma once
#include <time.h>

// - flag types -
// 0: 기본 (아무 효과 없음)
// 1: 포탈 (시작 지점으로 복귀)
// 2: 폭탄 (점수 초기화)
// 3: 탐지기 (보물 및 장애물의 위치 표시)
// 4: 보물 (점수 +1)

// type 0, and everywhen
void suffleFlags();
// type 1
void respone();
// type 2
void boom();
// type 3
int finderFlag = 0;
void finder();
// type 4
void treasure();

// 깃발에 닿았는지 검사, 닿았다면 효과 실행
void flagCheck();

// flag type을 확률별로 반환 
int getRandomFlagType();
