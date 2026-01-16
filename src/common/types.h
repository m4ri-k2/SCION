#ifndef SCION_TYPES_H // 말그대로 SCION에서의 기본 타입 정의
#define SCION_TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef enum // lane 상태평가
{
    HEALTH_OK = 0, 
    HEALTH_SUSPECT,
    HEALTH_FAILED
}
health_t;

typedef enum // os 모드
{
    MODE_NORMAL = 0, // 정상
    MODE_SAFE // 안전-비정상
}
mode_t;

typedef struct // 시퀀스/timestamp 값 구조체
{
    uint32_t seq; // 시퀀스 값. 음수 나오면 그것대로 문제기 때문에 무조건 unsigned
    uint64_t timestamp; // timestamp 값. 동일한 이유로 무조건 unsigned
    bool     valid; // 시퀀스랑 timestamp 값 포함 계산값에 대한 bool값. 이걸로 해당 계산값들이 판단 근거로 사용될 수 있나 없나를 분류.
} 
message_meta_t;

typedef struct // lane 하나당 해당 주기에 대해 내린 판단 요약본
{
    uint32_t lane_id; // lane 고유 아이디. 해당 값이 몇 번 lane에서 나왔는지
    uint32_t seq; // lane 간 시퀀스 값-지연 및 오류 감지용
    uint64_t timestamp; // lane 간 timestamp 값-지연 및 오류 감지용

    health_t health; // 해당 lane의 신뢰도 상태 평가
    mode_t   recommended_mode; // lane 하나 당 상태 권고. 결정값 아님. 2oo3/3oo3은 투표 가서 함. 
} 
decision_summary_t;

#endif
