#include "Rendering.h"
#include <thread>
#include <iostream>

using namespace std;

static void sysRender(Link* link) {
	cout << "thread sysRender started" << endl;
	cout << linkCount(link) << " objs in list" << endl;
	Rendering renderSys(link);
	renderSys.render();
	renderSys.~Rendering();
	cout << "thread sysRender ended" << endl;
}

int main(int argc, char** argv) {
	Link* link = new Link();

	thread Render(sysRender, link);

	// test add new obj to link list
	//Sleep(500);
	//list->next = new Link();
	//cout << "New objects is added" << endl;

	Render.join();

	cout << (link->next ? "leak" : "empty") << endl;
	delete link;
	return 0;
}
