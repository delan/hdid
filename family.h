#ifndef HDID_FAMILY_H
#define HDID_FAMILY_H

enum hdid_family_t {
	HDID_FAMILY_UNKNOWN,
	HDID_FAMILY_WD_DESKTOP,
	HDID_FAMILY_WD_RE,
	HDID_FAMILY_WD_RAPTOR,
	HDID_FAMILY_WD_MOBILE,
	HDID_FAMILY_WD_NAS,
	HDID_FAMILY_WD_VR,
	HDID_FAMILY_WD_XE,
	HDID_FAMILY_WD_BRAND,
	HDID_FAMILY_WD_AV,
};

extern const char *const hdid_family_list[];

#endif
