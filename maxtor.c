#include "maxtor.h"

void hdid_identify_maxtor(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_MAXTOR;
}
