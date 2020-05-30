#include "models.c"

#define IS_TEST 0 // 이 실행이 테스트인지 여부

#define FIELD_SIZE 25 // Field 크기
#define LIMIT_TIME 60 * 3 // 게임 진행 시간(초)
#define LIMIT_COUNT 1000 // 이동 가능 횟수
static int x = 2, y = 1; // x, y 좌표
static int score = 0; // 점수
static int LEVEL = 0; // 난이도

static char *GAME_MESSAGE = ""; // 알림창에 뜰 메세지
const char FLAG_TYPES[][50] = { "꽝!", "시작 지점으로 다시!", "펑~ 보물들이 사라져버렸어요!", "보물 탐지기!", "보물 획득!" };
const char OBSTACLE_TYPES[][50] = { "거대한 바위에 튕겨납니다!", "웅덩이에 빠졌습니다 ㅠㅠ", "늪에 빠져버렸어요..!" };

#define NUM_OF_FLAG_TYPE 5 // 깃발 종류의 수
static int FLAG_COUNT[] = {8, 6, 4}; // 한 번에 출력될 깃발 개수
static Flag *flags; // 깃발 정보

#define NUM_OF_OBSTACLE_TYPE 3 // 장애물 종류의 수
static int OBSTACLE_COUNT[] = {5, 3, 1}; // 한 번에 출력될 장애물 개수
static Obstacle *obstacles; // 장애물 정보

static int puddleFlag = 0; // 물 웅덩이에 빠졌는지 체크하는 플래그
static int LIMIT_PUDDLE_TIME[] = {10, 5, 3}; // 물 웅덩이 제한 시간
static int swampFlag = 0; // 늪에 빠졌는지 체크하는 플래그
static int LIMIT_SWAMP_COUNT[] = {9, 6, 3}; // 늪 제한 카운트

