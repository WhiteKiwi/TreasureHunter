// 몬스터를 랜덤하게 한 칸씩 옮깁니다
void moveMonster() {
    int i;
    int dice;

    for (i = 0; i < MONSTER_COUNT[LEVEL]; i++) {
        // 난이도가 상이라면 두 번 중 한 번은 플레이어 쪽으로 움직입니다
        if (LEVEL == 0) {
            dice  = rand() % 2;
            if (dice) {
                dice  = rand() % 2;
                if (dice) {
                    // 가로로 가까이 감
                    if (monsters[i].x > x) {
                        monsters[i].x -= 2;
                    } else {
                        monsters[i].x += 2;
                    }
                } else {
                    // 세로로 가까이 감
                    if (monsters[i].y > y) {
                        monsters[i].y--;
                    } else {
                        monsters[i].y++;
                    }
                }
                continue;
            }
        }

        dice  = rand() % 4;
        if (dice == 0) {
            // 위
            if (monsters[i].y != 1) {
                monsters[i].y--;
            }
        } else if (dice == 1) {
            // 왼쪽
            if (monsters[i].x != 2) {
                monsters[i].x -= 2;
            }
        } else if (dice == 2) {
            // 오른쪽
            if (monsters[i].x < FIELD_SIZE*2-2) {
                monsters[i].x += 2;
            }
        } else if (dice == 3) {
            // 아래
            if (monsters[i].y != FIELD_SIZE-1) {
                monsters[i].y++;
            }
        }
    }
}

// - monster types - 
// 0: 도적(만나면 보물을 빼앗김)
// 1: 괴물(GameOver)

// 도적
void thief() {
    // 난이도에 따라 빼앗기는 개수가 다름
    if (LEVEL == 0) {
        if(score > 3) {
            score -= 3;
        } else {
            // 빼앗기는 양보다 가진 보물이 적으면 모두 털림
            score = 0;
        }
    } else if (LEVEL == 1) {
        if (score > 2) {
            score -= 2;
        } else {
            score = 0;
        }
    } else if (LEVEL == 2) {
        if (score > 1) {
            score--;
        } else {
            score = 0;
        }
    }
}

// 괴물
void monster() {
    monsterFlag = 1;
}

void monsterCheck() {
    int i, type;

    // 몬스터 수 만큼 실행
    for (i = 0; i < MONSTER_COUNT[LEVEL]; i++) {
        // 몬스터의 위치와 내 위치가 같으면
        if (x == monsters[i].x && y == monsters[i].y){
            // 표시할 메세지 지정
            GAME_MESSAGE = MONSTER_TYPES[monsters[i].type];
            
            // 타입에 해당하는 효과 실행
            switch (monsters[i].type) {
                case 0:
                    thief();
                    break;
                case 1:
                    monster();
                    break;
            }
        }
    }
}

// monster type을 확률별로 반환 
int getRandomMonsterType() {
    // 위에서 정한 확률에 따라 몬스터 타입을 뽑아 반환함
    int i, t = 0;
    int dice = rand() % 100;
    for(i = 0; i < NUM_OF_MONSTER_TYPE; i++){
        t += PROB_OF_MONSTER_TYPE[LEVEL][i];
        if (dice < t)
            return i;
    }
}
