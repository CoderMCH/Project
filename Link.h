#pragma once

#include "Object.h"

// TBD: write it as template
struct Link {
	Object* obj = new Object();
	Link* next = nullptr;
};
int linkCount(Link* l);
