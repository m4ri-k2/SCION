#ifndef SCION_LANE_H // lane 내부의 상태를 정의. lane이 뭘 해야 되는 지에 대해서.
#define SCION_LANE_H

#include "common/types.h" 

typedef struct {
    uint32_t lane_id; // lane당 각자 가진 고유 아이디. 번호

    uint32_t last_seq; // 해당 lane이 마지막으로 정상처리했음이 인증된 시퀀스 번호
    uint64_t last_timestamp; // 해당 lane이 마지막으로 정상처리했음이 인정된 timestamp 번호 

    health_t health; // 해당 lane 자체를 판단 근거로서 얼마나 신뢰가능한지에 대한 등급-OK/SUSPECT/FAILED. 
} lane_state_t; // 누적 기록.

void lane_init(lane_state_t *lane, uint32_t lane_id); // 해당 lane 상태 값 초기화 후 해당 상태 값이 어느 lane인지 지정. -2번 lane 값이 5면 5라고 지정하라는 뜻

decision_summary_t lane_step(lane_state_t *lane); // 해당 lane이 가진 상태로 사이클 하나를 수행함. 또한, lane 내부 판단은 내부에만 저장

#endif
