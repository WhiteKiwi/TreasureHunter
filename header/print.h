#pragma once
#include <stdio.h>
#include "controls.h"
#include <Windows.h>

// 커서 이동하는 함수
void gotoxy(int x, int y);

// 게임을 그리는 함수
void printGame();

// ◆
// 유저 그리는 함수
void printUser();

// ▶▶▶
// 깃발 찍는 함수
extern int finderFlag;
void printFlags();

// ♨♨♨
// 장애물 찍는 함수
void printObstacles();

// ┌────┐
// │    │
// └────┘
// 판 그리는 함수
void printField();

// 우측에 게임 정보 그리는 함수
void printInfo();

// 난이도 선택 페이지 그리는 함수
void printLevel(int choice);
