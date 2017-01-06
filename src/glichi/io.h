#ifndef GLICHI_IO_H
#define GLICHI_IO_H

#define STR(x) #x

typedef enum
{
	GLICHI_KEY_Z = 0,
	GLICHI_KEY_X,
	GLICHI_KEY_UP,
	GLICHI_KEY_DOWN,
	GLICHI_KEY_LEFT,
	GLICHI_KEY_RIGHT,
	GLICHI_KEY_LAST
} glichi_key;

static inline char* glichi_key_str(glichi_key key) {
	switch(key) {
		case GLICHI_KEY_Z: return "Z";
		case GLICHI_KEY_X: return "X";
		case GLICHI_KEY_UP: return "[up]";
		case GLICHI_KEY_DOWN: return "[down]";
		case GLICHI_KEY_LEFT: return "[left]";
		case GLICHI_KEY_RIGHT: return "[right]";
		default: return "";
	}
}

void glichi_io_update();

#endif