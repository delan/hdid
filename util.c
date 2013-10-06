#include "util.h"

char *hdid_minstr(const char *in, size_t min) {
	size_t len = strlen(in);
	char *out = calloc(
		len < min ? min : len + 1,
		sizeof(char)
	);
	strncpy(out, in, len);
	return out;
}
