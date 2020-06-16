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
    
    x = 2, y = 1; // x, y ��ǥ
    score = 0;

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
    // �̵��Ÿ� �ʱ�ȭ
    move_count = 0;
    // ��� �ʱ�ȭ
    suffleFlags();
    // ��ֹ� �ʱ�ȭ
    suffleObstacles();

    // Console â ũ�� ����
    system("mode con cols=150 lines=30"); 
}

// ���� �� ��
void startGame() {
    // ���� �ʱ�ȭ
    initialize();

    // ���ӿ��� ������ ��� ����
    while(checkGameOver()){
        // ȭ�� �ʱ�ȭ �� ���� �׸�
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
}

// ����
void game() {
    // ���̵� ����
    chooseLevel();
    sprintf(DEBUG_MSG, "LEVEL: %d", LEVEL);

    while(LEVEL >= 0) {
        startGame();
        getch();

        // ���� ����!
        system("cls");
        printf("���� ����!\n");
        printf("����� ������ %d�� �Դϴ� :)\n\n", score);

        if (score == 12 && LEVEL == 0) {
            printf("LEVEL %d Ŭ����..!\n", 3-LEVEL);

            getch();
            getch();
            endingOfGame();
        } else if (score == 12) {
            printf("LEVEL %d Ŭ����..!\n", 3-LEVEL);
            printf("���� �ܰ踦 �����մϴ�...\n");
            LEVEL--;
        } else {
            printf("�̹� �ܰ踦 Ŭ�������� ���߽��ϴ�.\n");
            printf("������ �ٽ� ���۵˴ϴ�!");
        }
        getch();
        getch();
    }
}

// ������ ������ �մϴ�
void endingOfGame() {
    Sleep(1000);

    system("cls");
    printf("����� ���� ����� 12���� �巡�ﺼ�� ��� ��ҽ��ϴ�..\n");
    printf("���� ��Ÿ�� �ҿ��� ����شٰ� �մϴ�...\n\n");

    Sleep(2000);
    printf("�������� ��: �ҿ��� �����̳�\n");
    printf("�ҿ��� �Է��ϼ���: ");
    scanf("%s");
    printf("\n�� �����...\n");

    printf("���� �ҿ��� ��� ������ϴ�.\n\n");

    Sleep(3000);

    printf("����/���: ������ �������θ�Ʈ\n\n");
    printf("��ȹ: ������\n");
    printf("������: ������\n");
    printf("����: ������\n");
    
    // �޸� ����
    free(flags);
    free(obstacles);

    getchar();
    exit(0);
}

int main(){
    int choice;
    srand(time(NULL));

    choice = chooseMain();
    if (choice == 0) { // ���ӽ���
        game();
    } else if (choice == 1) { // ���Ӽ���
        // TODO: �����ϱ�
    } else if (choice == 2) { // ��������
        exit(0);
    }

    return 0;
}