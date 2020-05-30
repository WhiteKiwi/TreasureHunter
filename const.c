#include "models.c"

#define IS_TEST 0 // �� ������ �׽�Ʈ���� ����

#define FIELD_SIZE 25 // Field ũ��
#define LIMIT_TIME 60 * 3 // ���� ���� �ð�(��)
#define LIMIT_COUNT 1000 // �̵� ���� Ƚ��
static int x = 2, y = 1; // x, y ��ǥ
static int score = 0; // ����
static int LEVEL = 0; // ���̵�

static char *GAME_MESSAGE = ""; // �˸�â�� �� �޼���
const char FLAG_TYPES[][50] = { "��!", "���� �������� �ٽ�!", "��~ �������� ��������Ⱦ��!", "���� Ž����!", "���� ȹ��!" };
const char OBSTACLE_TYPES[][50] = { "�Ŵ��� ������ ƨ�ܳ��ϴ�!", "�����̿� �������ϴ� �Ф�", "�˿� �������Ⱦ��..!" };

#define NUM_OF_FLAG_TYPE 5 // ��� ������ ��
static int FLAG_COUNT[] = {8, 6, 4}; // �� ���� ��µ� ��� ����
static Flag *flags; // ��� ����

#define NUM_OF_OBSTACLE_TYPE 3 // ��ֹ� ������ ��
static int OBSTACLE_COUNT[] = {5, 3, 1}; // �� ���� ��µ� ��ֹ� ����
static Obstacle *obstacles; // ��ֹ� ����

static int puddleFlag = 0; // �� �����̿� �������� üũ�ϴ� �÷���
static int LIMIT_PUDDLE_TIME[] = {10, 5, 3}; // �� ������ ���� �ð�
static int swampFlag = 0; // �˿� �������� üũ�ϴ� �÷���
static int LIMIT_SWAMP_COUNT[] = {9, 6, 3}; // �� ���� ī��Ʈ

