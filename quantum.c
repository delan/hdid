#include "quantum.h"

void hdid_identify_quantum(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_QUANTUM;
}
