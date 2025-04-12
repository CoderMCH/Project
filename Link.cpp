#include "Link.h"

int linkCount(Link* l) {
	if (l == nullptr) return 0;

	int i = 1;
	while (l->next) {
		l = l->next;
		i++;
	}
	return i;
}
