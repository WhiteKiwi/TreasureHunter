#pragma once
#include <time.h>

// - obstacle types - 
// 0: 바위 (튕겨냄)
// 1: 늪 (빠지면 n번 못움직임)
// 2: 물웅덩이 (빠지면 n초 못움직임)

// 장애물 섞는 함수
void suffleObstacles();

// type 0
void bounce();
// type 1
void swamp();
// type 2
void puddle();

// 깃발에 닿았는지 검사, 닿았다면 효과 실행
void obstacleCheck();

// obstacle type을 확률별로 반환 
int getRandomObstacleType();
