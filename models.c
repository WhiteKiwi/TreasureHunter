typedef struct Flag {
    int x;
    int y;
    int type;
    // - flag types - 
    // 0: �⺻ (�ƹ� ȿ�� ����)
    // 1: ��Ż (���� �������� ����)
    // 2: ��ź (���� �ʱ�ȭ)
    // 3: Ž���� (���� �� ��ֹ��� ��ġ ǥ��)
    // 4: ���� (���� +1)
} Flag;

typedef struct Obstacle {
    int x;
    int y;
    int type;
    // - obstacle types - 
    // 0: ���� (ƨ�ܳ�)
    // 1: �� (������ n�� ��������)
    // 2: �������� (������ n�� ��������)
} Obstacle;
