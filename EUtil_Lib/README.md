EUtil

EUtil은 개인 프로젝트입니다.
EUtil은 동시성 지원을 목표로 설계되었습니다.

EUtil 중요 고려사항

EUtil은 1개의 Process Thread와 2개의 Main Task Thread를 상시 유지하는 상태에서 다수의 Worker Thread를 사용해 병렬로 업무를 처리하는 것을 목표로 하고 있습니다.

작업 중 고민사항
특정 프로젝트에서는 Thread 정합성을 위해 생성 및 삭제되는 Thread ID를 통일시킬 수 있도록 하는 조치를 수행하는데 이 부분에 대해서 어떻게 접근하고 EUtil에 녹여낼 수 있는지 고민해보기.
