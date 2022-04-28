#pragma once

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