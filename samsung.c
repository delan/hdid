#include "samsung.h"

void hdid_identify_samsung(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_SAMSUNG;
}
