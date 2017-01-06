#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define GLICHI_COLOR_RED     "\x1b[31m"
#define GLICHI_COLOR_GREEN   "\x1b[32m"
#define GLICHI_COLOR_YELLOW  "\x1b[33m"
#define GLICHI_COLOR_BLUE    "\x1b[34m"
#define GLICHI_COLOR_MAGENTA "\x1b[35m"
#define GLICHI_COLOR_CYAN    "\x1b[36m"
#define GLICHI_COLOR_RESET   "\x1b[0m"


void glichi_info(const char *fname, int lineno, const char *fxname, const char *str, ...) {
	va_list args;
	va_start(args, str);

	char buffer[256];
	vsnprintf(buffer, 256, str, args);
	printf("%16s:%d:%s:" GLICHI_COLOR_YELLOW " %s" GLICHI_COLOR_RESET "\n", 
		fname, lineno, fxname, buffer);
}
