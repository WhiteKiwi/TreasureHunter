#include "models.c"

#define IS_TEST 1 // �� ������ �׽�Ʈ���� ����
static char DEBUG_MSG[50]; // DEBUG Message

#define FIELD_SIZE 25 // Field ũ��
#define LIMIT_TIME 60 * 3 // ���� ���� �ð�(��)
#define LIMIT_COUNT 1000 // �̵� ���� Ƚ��
static int x = 2, y = 1; // x, y ��ǥ
static int score = 0; // ����
static int LEVEL = 0; // ���̵�


static char *GAME_MESSAGE = ""; // �˸�â�� �� �޼���
const char FLAG_TYPES[][50] = { "��!", "���� �������� �ٽ�!", "��~ �������� ��������Ⱦ��!", "���� Ž����!", "���� ȹ��!" };
const char OBSTACLE_TYPES[][50] = { "�Ŵ��� ������ ƨ�ܳ��ϴ�!", "�����̿� �������ϴ� �Ф�", "�˿� �������Ⱦ��..!" };
const char MONSTER_TYPES[][50] = { "������ ���� ������ ���Ѱ���ϴ�..", "������ ���� ����߽��ϴ� [GAME OVER]" };


static Flag *flags; // ��� ����
static int FLAG_COUNT[] = {8, 6, 4}; // �� ���� ��µ� ��� ����
#define NUM_OF_FLAG_TYPE 5 // ��� ������ ��
// ���̵��� ���� Ÿ�Ժ� ����� ���� Ȯ��, ���� 100�� �Ǿ�� ��
// - flag types - 
// 0: �⺻ (�ƹ� ȿ�� ����)
// 1: ��Ż (���� �������� ����)
// 2: ��ź (���� �ʱ�ȭ)
// 3: Ž���� (���� �� ��ֹ��� ��ġ ǥ��)
// 4: ���� (���� +1)
static int PROB_OF_FLAG_TYPE[3][NUM_OF_FLAG_TYPE] = {
    { 50, 30, 3, 7, 10 },  // ��
    { 45, 23, 2, 10, 20 },  // ��
    { 40, 19, 1, 10, 30 }   // ��
};


static Obstacle *obstacles; // ��ֹ� ����
static int OBSTACLE_COUNT[] = {5, 3, 1}; // �� ���� ��µ� ��ֹ� ����
#define NUM_OF_OBSTACLE_TYPE 3 // ��ֹ� ������ ��
// ���̵��� ���� Ÿ�Ժ� ��ֹ��� ���� Ȯ��, ���� 100�� �Ǿ�� ��
// - obstacle types - 
// 0: ���� (ƨ�ܳ�)
// 1: �� (������ n�� ��������)
// 2: �������� (������ n�� ��������)
static int PROB_OF_OBSTACLE_TYPE[3][NUM_OF_OBSTACLE_TYPE] = {
    { 50, 25, 25 }, // ��
    { 70, 15, 15 }, // ��
    { 90, 5, 5 }    // ��
};

static int puddleFlag = 0; // �� �����̿� �������� üũ�ϴ� �÷���
static int LIMIT_PUDDLE_TIME[] = {10, 5, 3}; // �� ������ ���� �ð�
static int swampFlag = 0; // �˿� �������� üũ�ϴ� �÷���
static int LIMIT_SWAMP_COUNT[] = {9, 6, 3}; // �� ���� ī��Ʈ


static Monster *monsters; // ���� ����
static int MONSTER_COUNT[] = {3, 2, 1}; // �� ���� ��µ� ���� ��
#define NUM_OF_MONSTER_TYPE 2 // ���� ������ ��
// ���̵��� ���� Ÿ�Ժ� ��ֹ��� ���� Ȯ��, ���� 100�� �Ǿ�� ��
// - monster types - 
// 0: ����(������ ������ ���ѱ�)
// 1: ����(GameOver)
static int PROB_OF_MONSTER_TYPE[3][NUM_OF_MONSTER_TYPE] = {
    { 50, 50 }, // ��
    { 70, 30 }, // ��
    { 90, 10 }  // ��
};
static int monsterFlag = 0; // �������� �������� üũ�ϴ� �÷���
