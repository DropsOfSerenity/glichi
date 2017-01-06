#ifndef GLICHI_LOG_H_
#define GLICHI_LOG_H_

void glichi_info(const char *fname, int lo, const char *fxname, const char *str, ...);
#define GLICHI_INFO(...) glichi_info(__FILE__, __LINE__, __func__, __VA_ARGS__)

#endif