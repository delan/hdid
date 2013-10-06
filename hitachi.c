#include "hitachi.h"

void hdid_identify_hitachi(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_HITACHI;
}
