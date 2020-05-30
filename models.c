typedef struct Flag {
    int x;
    int y;
    int type;
    // - flag types - 
    // 0: 기본 (아무 효과 없음)
    // 1: 포탈 (시작 지점으로 복귀)
    // 2: 폭탄 (점수 초기화)
    // 3: 탐지기 (보물 및 장애물의 위치 표시)
    // 4: 보물 (점수 +1)
} Flag;

typedef struct Obstacle {
    int x;
    int y;
    int type;
    // - obstacle types - 
    // 0: 바위 (튕겨냄)
    // 1: 늪 (빠지면 n번 못움직임)
    // 2: 물웅덩이 (빠지면 n초 못움직임)
} Obstacle;
