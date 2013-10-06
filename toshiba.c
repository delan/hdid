#include "toshiba.h"

void hdid_identify_toshiba(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_TOSHIBA;
}
