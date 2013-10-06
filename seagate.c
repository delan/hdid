#include "seagate.h"

void hdid_identify_seagate(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_SEAGATE;
}
