#include "lane.h" // lane의 한 주기 처리 루프. 해당 함수는 lane 내부 누적된 상태 읽고 해당 한 주기에 대한 판단 결과를 요약본으로 저장함. 결정본/비교목적 아니고 요약. 

void lane_init(lane_state_t *lane, uint32_t lane_id) // lane 인스턴스 초기화  
{
    lane->lane_id = lane_id;
    lane->last_seq = 0;
    lane->last_timestamp = 0;
    lane->health = HEALTH_OK;
}

decision_summary_t lane_step(lane_state_t *lane) // 
{
    decision_summary_t out = {0};

    out.lane_id = lane->lane_id; // 해당 판단 요약이 어느 lane에서 생성되었는지 식별
    out.seq = lane->last_seq; // lane이 마지막으로 유효하다고 인정한 기준 시점 메타데이터
    out.timestamp = lane->last_timestamp; // 상동
    out.health = lane->health; // 현재 이 lane을 판단 근거로 사용할 수 있는 신뢰도 수준
    out.recommended_mode = MODE_NORMAL; // 기본권고모드

    return out; // lane 단위 판단 요약을 시스템 계층으로 전달
}

// v1 단계에서는 lane_step이 누적 상태를 그대로 요약해 보고함. 입력 무결성 검사 및 health 전이 로직은 단계적으로 추가됨.
