#include "methods.h"

void toUpperCase(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void toLowerCase(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}
