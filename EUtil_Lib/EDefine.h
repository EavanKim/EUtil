#pragma once

/**
* 
* @brief 단순 선언에 관해 모아두는 위치
* @details 라이브러리에서 사용하는 모든 형을 이곳에서 선언해놓고, 필요한 경우 전체 형변환을 이곳에서 수행합니다.
* @author EavanKim
* @date 2022-04-28
* @version 0.0.1
* 
*/

typedef volatile long		EBOOL;
typedef char				SCHAR;
typedef wchar_t				ECHAR;
typedef int32_t				EINT;
typedef int64_t				EINT64;
typedef float				EFLOAT;
typedef double				EDOUBLE;
typedef volatile long		EVINT;
typedef volatile long long	EVINT64;

#if _WIN64
typedef int64_t EPTRINT;
#else
typedef int32_t EPTRINT;
#endif