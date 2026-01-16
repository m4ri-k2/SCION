#ifndef SCION_TYPES_H
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
    MODE_NORMAL = 0,
    MODE_SAFE
}
mode_t;

typedef struct 
{
    uint32_t seq; // 시퀀스 값. 음수 나오면 그것대로 문제기 때문에 무조건 unsigned
    uint64_t timestamp; // timestamp 값. 동일한 이유로 무조건 unsigned
    bool     valid; // 시퀀스랑 timestamp 값 포함 계산값에 대한 bool값. 이걸로 해당 계산값들이 판단 근거로 사용될 수 있나 없나를 분류.
} 
message_meta_t;

typedef struct 
{
    uint32_t lane_id;
    uint32_t seq;
    uint64_t timestamp;

    health_t health;
    mode_t   recommended_mode;
} 
decision_summary_t;

#endif
