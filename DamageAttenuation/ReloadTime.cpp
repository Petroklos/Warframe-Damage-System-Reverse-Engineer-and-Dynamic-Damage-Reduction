#include "ReloadTime.h"

ReloadTime::ReloadTime() {
	reload = 0;
	divider = 0;
}

ReloadTime::ReloadTime(double r) {
	reload = r;
	divider = 0;
}

ReloadTime::ReloadTime(double r, double d) {
	reload = r;
	divider = d;
}

void ReloadTime::setReload(double r) {
	reload = r;
}

void ReloadTime::setDivider(double d) {
	divider = d;
}

double ReloadTime::getReload() {
	return reload;
}

double ReloadTime::getDivider() {
	return divider;
}

double ReloadTime::calculate() {
	return reload / (1 + divider);
}