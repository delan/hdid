#include "core.h"

struct hdid_info hdid_identify(char *model) {
	struct hdid_info info = {0};
	size_t len = strlen(model);
	model = hdid_minstr(model, 4);
	switch (model[0]) {
	case '2':
		switch (model[1]) {
		case 'B':
		case 'R':
			hdid_identify_maxtor(&info, model);
			break;
		}
		break;
	case '3':
		hdid_identify_maxtor(&info, model);
		break;
	case '4':
		switch (model[1]) {
		case 'G':
		case 'K':
		case 'W':
			hdid_identify_maxtor(&info, model);
			break;
		}
		break;
	case '5':
		hdid_identify_maxtor(&info, model);
		break;
	case '6':
		switch (model[1]) {
		case 'L':
			hdid_identify_maxtor(&info, model);
			break;
		}
		break;
	case '7':
		hdid_identify_maxtor(&info, model);
		break;
	case '8':
		hdid_identify_maxtor(&info, model);
		break;
	case '9':
		hdid_identify_maxtor(&info, model);
		break;
	case 'A':
		switch (model[1]) {
		case 'S':
		case 'T':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'B':
		switch (model[1]) {
		case 'F':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'C':
		switch (model[1]) {
		case 'F':
			switch (model[2]) {
			case 'A':
			case 'L':
			case 'N':
			case 'P':
			case 'S':
				hdid_identify_conner(&info, model);
				break;
			}
			break;
		case 'P':
			if (len == 5)
				hdid_identify_quantum(&info, model);
			else
				hdid_identify_conner(&info, model);
			break;
		case 'R':
		case 'X':
		case 'Y':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'D':
		switch (model[1]) {
		case 'A':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'E':
		switch (model[1]) {
		case 'A':
		case 'B':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'J':
			hdid_identify_maxtor(&info, model);
			break;
		case 'L':
		case 'M':
		case 'N':
		case 'P':
			if (len == 5)
				hdid_identify_quantum(&info, model);
			else
				hdid_identify_maxtor(&info, model);
			break;
		case 'R':
		case 'S':
		case 'T':
			hdid_identify_maxtor(&info, model);
			break;
		case 'U':
			if (len == 5)
				hdid_identify_quantum(&info, model);
			else
				hdid_identify_maxtor(&info, model);
			break;
		case 'V':
		case 'W':
			hdid_identify_maxtor(&info, model);
			break;
		case 'X':
			if (len == 5)
				hdid_identify_quantum(&info, model);
			else
				hdid_identify_maxtor(&info, model);
			break;
		case 'Y':
			hdid_identify_maxtor(&info, model);
			break;
		}
		break;
	case 'F':
		switch (model[1]) {
		case 'B':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'G':
		switch (model[1]) {
		case 'M':
		case 'P':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'H':
		switch (model[1]) {
		case 'A':
			hdid_identify_samsung(&info, model);
			break;
		case 'C':
			hdid_identify_hitachi(&info, model);
			break;
		case 'D':
		case 'E':
		case 'M':
			switch (model[2]) {
			case 'C':
			case 'E':
			case 'J':
			case 'N':
			case 'S':
			case 'T':
				hdid_identify_hitachi(&info, model);
				break;
			default:
				hdid_identify_samsung(&info, model);
				break;
			}
			break;
		case 'N':
			if (len == 5)
				hdid_identify_quantum(&info, model);
			else
				hdid_identify_samsung(&info, model);
			break;
		case 'S':
			hdid_identify_samsung(&info, model);
			break;
		case 'T':
			hdid_identify_hitachi(&info, model);
			break;
		case 'U':
			switch (model[2]) {
			case 'C':
			case 'E':
			case 'J':
			case 'N':
			case 'S':
			case 'T':
				hdid_identify_hitachi(&info, model);
				break;
			default:
				hdid_identify_samsung(&info, model);
				break;
			}
			break;
		case 'X':
		case 'Y':
		case 'Z':
			hdid_identify_samsung(&info, model);
			break;
		}
		break;
	case 'K':
		switch (model[1]) {
		case 'A':
		case 'N':
		case 'U':
		case 'W':
		case 'X':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'L':
		switch (model[1]) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'M':
		case 'T':
			hdid_identify_quantum(&info, model);
			break;
		case 'X':
			switch (model[2]) {
			case 'T':
				hdid_identify_maxtor(&info, model);
				break;
			}
			break;
		}
		break;
	case 'M':
		switch (model[1]) {
		case 'K':
			hdid_identify_toshiba(&info, model);
			break;
		case 'U':
		case 'V':
			hdid_identify_quantum(&info, model);
			break;
		case 'X':
			switch (model[2]) {
			case 'T':
				hdid_identify_maxtor(&info, model);
				break;
			}
			break;
		}
		break;
	case 'P':
		switch (model[1]) {
		case 'I':
		case 'X':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'R':
		switch (model[1]) {
		case 'R':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'S':
		switch (model[1]) {
		case 'A':
		case 'E':
		case 'G':
		case 'R':
			hdid_identify_quantum(&info, model);
			break;
		case 'T':
			if (len == 5)
				hdid_identify_quantum(&info, model);
			else
				hdid_identify_seagate(&info, model);
			break;
		}
		break;
	case 'T':
		switch (model[1]) {
		case 'B':
		case 'D':
		case 'M':
		case 'N':
		case 'R':
		case 'S':
		case 'X':
		case 'Y':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'V':
		switch (model[1]) {
		case 'K':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	case 'W':
		switch (model[1]) {
		case 'D':
			hdid_identify_wd(&info, model);
			break;
		}
		break;
	case 'X':
		switch (model[1]) {
		case 'C':
			hdid_identify_quantum(&info, model);
			break;
		}
		break;
	}
	free(model);
	return info;
}

void hdid_print(struct hdid_info info) {
	printf(
		"Manufacturer:           %s\n",
		hdid_man_list[info.manufacturer]
	);
}
