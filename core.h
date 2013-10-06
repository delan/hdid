#ifndef HDID_CORE_H
#define HDID_CORE_H

#include <stdio.h>
#include <string.h>
#include "util.h"
#include "man.h"
#include "interface.h"
#include "form.h"
#include "family.h"

struct hdid_info {
	enum hdid_man_t manufacturer;
	int spindle_rpm;
	long nominal_megabytes;
	enum hdid_interface_t interface;
	enum hdid_form_t form;
	int sector_bytes;
	int platters;
	long cache_bytes;
	enum hdid_family_t family;
};

struct hdid_info hdid_identify(char *model);
void hdid_print(struct hdid_info info);

#include "maxtor.h"
#include "quantum.h"
#include "seagate.h"
#include "samsung.h"
#include "conner.h"
#include "toshiba.h"
#include "hitachi.h"
#include "wd.h"

#endif
