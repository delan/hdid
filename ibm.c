#include "ibm.h"

void hdid_identify_ibm(struct hdid_info *info, const char *model) {
	info->manufacturer = HDID_MAN_IBM;
}
