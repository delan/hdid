/*
	Sources:

	*	Model Numbers - WD Internal Drives (Jul 2012)
		http://www.wdc.com/wdproducts/library/other/2579-001028.pdf

	*	Legacy Model and Order Numbers (Nov 2009)
		http://www.wdc.com/wdproducts/library/other/2579-701261.pdf
*/

#include "wd.h"

const char *hdid_wd_suffix(const char *model);
void hdid_wd_old_internal(struct hdid_info *info, const char *model);

void hdid_identify_wd(struct hdid_info *info, const char *model) {
	const char *suffix;
	info->manufacturer = HDID_MAN_WD;
	switch (model[2]) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			suffix = hdid_wd_suffix(model);
			switch (strlen(suffix)) {
			case 2:
				hdid_wd_old_internal(info, model);
				break;
			case 4:
			case 5:
			case 6:
			case 8:
			case 9:
				break;
			}
		case 'A':
		case 'B':
		case 'C':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'M':
		case 'P':
		case 'Q':
		case 'S':
		case 'T':
		case 'U':
		case 'X':
			break;
	}
}

const char *hdid_wd_suffix(const char *model) {
	int i;
	for (i = 2; model[i] >= '0' && model[i] <= '9'; i++);
	return model + i;
}

void hdid_wd_old_internal(struct hdid_info *info, const char *model) {
	info->nominal_megabytes = atoi(model + 2) * 100;
	const char *suffix = hdid_wd_suffix(model);
	switch (suffix[0]) {
		case 'A':
			info->spindle_rpm = 5400;
			break;
		case 'B':
			info->spindle_rpm = 7200;
			break;
		case 'C':
			info->spindle_rpm = 10000;
			break;
		case 'D':
			info->spindle_rpm = 4500;
			break;
		case 'E':
			info->spindle_rpm = 5400;
			break;
		case 'F':
			info->spindle_rpm = 10000;
			break;
		case 'G':
			info->spindle_rpm = 10000;
			break;
		case 'H':
			info->spindle_rpm = 10000;
			break;
		case 'J':
			info->spindle_rpm = 7200;
			break;
		case 'K':
			info->spindle_rpm = 7200;
			break;
		case 'L':
			info->spindle_rpm = 7200;
			break;
		case 'M':
			info->spindle_rpm = 5400;
			break;
		case 'N':
			info->spindle_rpm = 5400;
			break;
		case 'P':
			info->spindle_rpm = 7200;
			break;
		case 'R':
			info->spindle_rpm = 10000;
			break;
		case 'S':
			info->spindle_rpm = 7200;
			break;
		case 'T':
			info->spindle_rpm = 7200;
			break;
		case 'U':
			info->spindle_rpm = 5400;
			break;
		case 'V':
			info->spindle_rpm = 5400;
			break;
		case 'W':
			info->spindle_rpm = 3600;
			break;
		case 'X':
			info->spindle_rpm = 4200;
			break;
		case 'Y':
			info->spindle_rpm = 7200;
			break;
		case 'Z':
			info->spindle_rpm = 7200;
			break;
	}
	switch (suffix[1]) {
		case 'A':
			info->interface = HDID_INTERFACE_ATA66;
			info->form = HDID_FORM_350_254;
			break;
		case 'B':
			info->interface = HDID_INTERFACE_ATA100;
			info->form = HDID_FORM_350_254;
			break;
		case 'C':
			info->interface = HDID_INTERFACE_FIREWIRE;
			info->form = HDID_FORM_350_254;
			break;
		case 'D':
			info->interface = HDID_INTERFACE_SATA1;
			info->form = HDID_FORM_350_254;
			break;
		case 'E':
			info->interface = HDID_INTERFACE_ATA133;
			info->form = HDID_FORM_350_254;
			break;
		case 'P':
			info->interface = HDID_INTERFACE_CFPLUS2;
			info->form = HDID_FORM_CF_50;
			break;
		case 'R':
		case 'S':
			info->interface = HDID_INTERFACE_SATA2;
			info->form = HDID_FORM_350_254;
			break;
		case 'W':
			/* TODO: Home Entertainment A/V Products */
			info->form = HDID_FORM_350_254;
			break;
	}
}
