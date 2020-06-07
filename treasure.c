// CreatedAt: 2020-06-01
// Author: 202011358 ������ 
// 
// C ���α׷��� (0451)
// ���� #2: ���� ã��

#include "print.c"
#include "flag.c"
#include "obstacle.c"
#include "monster.c"


// �����ϱ� �� �ʱ�ȭ�ϴ� �Լ�
void initialize() {
    int i;

    // ���̵� ��ŭ ��߰� ��ֹ� ����
    flags = malloc(sizeof(Flag) * FLAG_COUNT[LEVEL]);
    obstacles = malloc(sizeof(Obstacle) * OBSTACLE_COUNT[LEVEL]);
    monsters = malloc(sizeof(Monster) * MONSTER_COUNT[LEVEL]);

    // ���ʹ� ó���� �ʱ�ȭ
    for(i = 0; i < MONSTER_COUNT[LEVEL]; i++) {
        monsters[i].x = ((rand() % (FIELD_SIZE - 1)) + 1) * 2;
        monsters[i].y = (rand() % (FIELD_SIZE - 1)) + 1;
        monsters[i].type = getRandomMonsterType();
    }

    // ���� �ð� ���
    startTime = time(NULL);
    // ��� �ʱ�ȭ
    suffleFlags();
    // ��ֹ� �ʱ�ȭ
    suffleObstacles();

    // Console â ũ�� ����
    system("mode con cols=150 lines=30"); 
}

int main(){
    srand(time(NULL));

    // ���̵� ����
    chooseLevel();
    sprintf(DEBUG_MSG, "LEVEL: %d", LEVEL);

    // ���� �ʱ�ȭ
    initialize();

    // ���ӿ��� ������ ��� ����
    while(checkGameOver()){
        // ȭ�� �ʱ�ȭ �� ���� �׸�
        system("cls");
        printGame();

        // �Է� �޾Ƽ� ��߰� ��ֹ��� ��Ҵ��� üũ
        inputKey();
        flagCheck();
        obstacleCheck();
        monsterCheck();
        moveMonster();
    }

    system("cls");
    printGame();
    getch();

    // ���� ����!
    system("cls");
    printf("���� ����!\n");
    printf("����� ������ %d�� �Դϴ� :)", score);

    // �޸� ����
    free(flags);
    free(obstacles);

    getchar();
    return 0;
}