#include "Link.h"

int linkCount(Link* l) {
	int i = 1;
	while (l->next) {
		l = l->next;
		i++;
	}
	return i;
}
