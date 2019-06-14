//log.h 日志头文件
#ifndef _LOG_H_
#define _LOG_H_

/*
#define IC_NO_LOG_LEVEL			0
#define IC_DEBUG_LEVEL			1
#define IC_INFO_LEVEL			2
#define IC_WARNING_LEVEL		3
#define IC_ERROR_LEVEL			4; 
*/

/************************************************************************/
/* 
const char *file：文件名称
int line：文件行号
int level：错误级别
		0 -- 没有日志
		1 -- debug级别
		2 -- info级别
		3 -- warning级别
		4 -- err级别
int status：错误码
const char *fmt：可变参数
*/
/************************************************************************/
//实际使用的Level
//***应该用enum class ERRORCODE***
//尽可能优先使用强类型枚举。
//但是如果改过来因为该类型要做_Log函数的参数
//强转太麻烦，只能改成现在这样。
enum ERRORCODE{
    RIGHT=0,
    FUNC_FAILED,
    SQLQUERY_FAILED,
    DECODE_FAILED
};
extern int  Level[5];
void _Log(const char *file, int line, int level, int status, const char *fmt, ...);

#endif //_LOG_H_
