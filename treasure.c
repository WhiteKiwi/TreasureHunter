// CreatedAt: 2020-06-01
// Author: 202011358 ������ 
// 
// C ���α׷��� (0451)
// ���� #2: ���� ã��

#include "print.c"
#include "flag.c"
#include "obstacle.c"


// �����ϱ� �� �ʱ�ȭ�ϴ� �Լ�
void initialize() {
    // ���̵� ��ŭ ��߰� ��ֹ� ����
    flags = malloc(sizeof(Flag) * FLAG_COUNT[LEVEL]);
    obstacles = malloc(sizeof(Obstacle) * OBSTACLE_COUNT[LEVEL]);

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
    }

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