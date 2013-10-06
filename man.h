#ifndef HDID_MAN_H
#define HDID_MAN_H

enum hdid_man_t {
	HDID_MAN_UNKNOWN,
	HDID_MAN_WD,
	HDID_MAN_SEAGATE,
	HDID_MAN_MAXTOR,
	HDID_MAN_SAMSUNG,
	HDID_MAN_HITACHI,
	HDID_MAN_TOSHIBA,
	HDID_MAN_CONNER,
	HDID_MAN_QUANTUM,
	HDID_MAN_IBM,
};

extern const char *const hdid_man_list[];

#endif
