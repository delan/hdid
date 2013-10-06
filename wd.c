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
void hdid_wd_new_internal(struct hdid_info *info, const char *model);

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
				hdid_wd_new_internal(info, model);
				break;
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

void hdid_wd_new_internal(struct hdid_info *info, const char *model) {
	int raw_capacity = atoi(model + 2);
	const char *suffix = hdid_wd_suffix(model);
	switch (suffix[0]) {
		case 'A':
			info->nominal_megabytes = raw_capacity * 100;
			info->form = HDID_FORM_350_254;
			break;
		case 'B':
			info->nominal_megabytes = raw_capacity * 100;
			info->form = HDID_FORM_250;
			break;
		case 'C':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_250;
			break;
		case 'D':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_250_350_CORRECT;
			break;
		case 'E':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_350_254;
			break;
		case 'F':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_350_254;
			break;
		case 'G':
			info->nominal_megabytes = raw_capacity * 100;
			info->form = HDID_FORM_250_350_INCORRECT;
			break;
		case 'H':
			info->nominal_megabytes = raw_capacity * 100;
			info->form = HDID_FORM_250_350_CORRECT;
			break;
		case 'J':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_250;
			break;
		case 'K':
			info->nominal_megabytes = raw_capacity * 100;
			info->form = HDID_FORM_250_125;
			break;
		case 'L':
			info->nominal_megabytes = raw_capacity * 100;
			info->form = HDID_FORM_250_70;
			break;
		case 'N':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_250_150;
			break;
		case 'S':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_250_70;
			break;
		case 'T':
			info->nominal_megabytes = raw_capacity * 100000;
			info->form = HDID_FORM_250_125;
			break;
	}
	switch (suffix[1]) {
		case 'A':
			info->family = HDID_FAMILY_WD_DESKTOP;
			info->sector_bytes = 512;
			break;
		case 'B':
			info->family = HDID_FAMILY_WD_RE;
			info->sector_bytes = 512;
			info->platters = 3;
			break;
		case 'D':
			info->family = HDID_FAMILY_WD_RAPTOR;
			info->sector_bytes = 512;
			break;
		case 'E':
			info->family = HDID_FAMILY_WD_MOBILE;
			info->sector_bytes = 512;
			break;
		case 'F':
			info->family = HDID_FAMILY_WD_NAS;
			info->sector_bytes = 512;
			break;
		case 'H':
			info->family = HDID_FAMILY_WD_VR;
			info->sector_bytes = 512;
			break;
		case 'K':
			info->family = HDID_FAMILY_WD_XE;
			info->sector_bytes = 512;
			break;
		case 'L':
			info->family = HDID_FAMILY_WD_VR;
			info->sector_bytes = 512;
			break;
		case 'M':
			info->family = HDID_FAMILY_WD_BRAND;
			info->sector_bytes = 512;
			break;
		case 'N':
			info->family = HDID_FAMILY_WD_BRAND;
			info->sector_bytes = 4096;
			break;
		case 'P':
			info->family = HDID_FAMILY_WD_MOBILE;
			info->sector_bytes = 4096;
			break;
		case 'R':
			info->family = HDID_FAMILY_WD_RE;
			info->sector_bytes = 4096;
			break;
		case 'U':
			info->family = HDID_FAMILY_WD_AV;
			info->sector_bytes = 4096;
			break;
		case 'V':
			info->family = HDID_FAMILY_WD_AV;
			info->sector_bytes = 512;
			break;
		case 'W':
			info->family = HDID_FAMILY_WD_VR;
			info->sector_bytes = 4096;
			break;
		case 'Y':
			info->family = HDID_FAMILY_WD_RE;
			info->sector_bytes = 512;
			info->platters = 4;
			break;
		case 'Z':
			info->family = HDID_FAMILY_WD_DESKTOP;
			info->sector_bytes = 4096;
			break;
	}
	switch (suffix[2]) {
		case 'A':
			info->spindle_rpm = 5400;
			info->cache_bytes = 2097152;
			break;
		case 'B':
			info->spindle_rpm = 7200;
			info->cache_bytes = 2097152;
			break;
		case 'C':
			info->spindle_rpm = 5400;
			info->cache_bytes = 16777216;
			break;
		case 'D':
			info->spindle_rpm = 5400;
			info->cache_bytes = 33554432;
			break;
		case 'E':
			info->spindle_rpm = 7200;
			info->cache_bytes = 67108864;
			break;
		case 'F':
			info->spindle_rpm = 10000;
			info->cache_bytes = 16777216;
			break;
		case 'G':
			info->spindle_rpm = 10000;
			info->cache_bytes = 8388608;
			break;
		case 'H':
			info->spindle_rpm = 10000;
			info->cache_bytes = 33554432;
			break;
		case 'J':
			info->spindle_rpm = 7200;
			info->cache_bytes = 8388608;
			break;
		case 'K':
			info->spindle_rpm = 7200;
			info->cache_bytes = 16777216;
			break;
		case 'L':
			info->spindle_rpm = 7200;
			info->cache_bytes = 33554432;
			break;
		case 'P':
			info->spindle_rpm = 5400;
			break;
		case 'R':
			info->spindle_rpm = 5400;
			info->cache_bytes = 67108864;
			break;
		case 'S':
			info->spindle_rpm = 7200;
			info->cache_bytes = 67108864;
			break;
		case 'T':
			info->spindle_rpm = 10000;
			break;
		case 'V':
			info->spindle_rpm = 5400;
			info->cache_bytes = 8388608;
			break;
		case 'Y':
			info->spindle_rpm = 7200;
			break;
	}
	switch (suffix[3]) {
		case 'A':
			info->interface = HDID_INTERFACE_ATA66;
			break;
		case 'B':
			info->interface = HDID_INTERFACE_ATA100;
			break;
		case 'C':
			info->interface = HDID_INTERFACE_ZIF33;
			break;
		case 'D':
			info->interface = HDID_INTERFACE_SATA1;
			break;
		case 'E':
			info->interface = HDID_INTERFACE_ATA133;
			break;
		case 'F':
			info->interface = HDID_INTERFACE_SAS11;
			break;
		case 'G':
			info->interface = HDID_INTERFACE_SAS20;
			break;
		case 'S':
			if (info->family == HDID_FAMILY_WD_MOBILE)
				info->interface = HDID_INTERFACE_SATA1;
			else
				info->interface = HDID_INTERFACE_SATA2;
			break;
		case 'T':
			info->interface = HDID_INTERFACE_SATA2;
			break;
		case 'X':
			info->interface = HDID_INTERFACE_SATA3;
			break;
		case 'Z':
			info->interface = HDID_INTERFACE_SATA3;
			break;
	}
}
