#include "wd.h"

void hdid_identify_wd(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_WD;
}
