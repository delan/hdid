#include "hdid.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s [HDD model]\n", argv[0]);
		return 1;
	}
	hdid_print(hdid_identify(argv[1]));
	return 0;
}
