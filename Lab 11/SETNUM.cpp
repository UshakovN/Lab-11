#include "SETNUM.h"
#include "EXCEPTIONS.h"

SETNUM::SETNUM(int z) {
	if (z > MAX || z < MIN) throw BAD_VALUE("Некорректное значение. Значение лежит вне разрешенного диапазона!\n");
	else {
		size = 1;
		x = new int[size];
		x[size - 1] = z;
	}
}

SETNUM::SETNUM() {
	x = nullptr;
	size = 0;
}

SETNUM::SETNUM(const SETNUM& set, int z) {
	size = 0;
	x = new int[set.size];
	int j = 0;
	for (int i = 0; i < set.size; i++) {
		if (set.x[i] <= z) {
			x[j] = set.x[i];
			j++; size++;
		}
	}
}

SETNUM::operator int() const {
	int sum = 0;
	for (int i = 0; i < size; i++) { sum += x[i]; }
	if (size != 0) sum /= size;
	else sum = 0;
	return sum;
}

void SETNUM::Init(int z) {
	if (z > MAX || z < MIN) throw BAD_VALUE("Некорректное значение. Значение лежит вне разрешенного диапазона!\n");
	else {
		size = 1;
		x = new int[size];
		x[size - 1] = z;
	}
}

void SETNUM::AddSort(int k, int z) {
	if (size == 0) { Init(z); }
	else {
		int* y = new int[++size]; int i;
		for (i = 0; i < k; i++) { y[i] = x[i]; }
		y[i] = z;
		for (; i < size; i++) { y[i + 1] = x[i]; }
		delete[] x; x = y;
	}
	return;
}

bool SETNUM::Contains(int z) const {
	int i = 0; bool fl = false;
	while (!fl && i < size) {
		if (x[i] == z) fl = true;
		else i++;
	}
	return fl;
}

int SETNUM::Element(int z) const {
	int i = 0; bool fl = false;
	while (!fl && i < size) {
		if (x[i] > z) fl = true;
		else i++;
	}
	return i;
}

void SETNUM::AddElement(int z) {
	if (!Contains(z)) {
		AddSort(Element(z), z);
	}
	return;
}

void SETNUM::DelSort(int k, int z) {
	if (size != 0) {
		int* y = new int[--size]; int i;
		for (i = 0; i < k - 1; i++) { y[i] = x[i]; }
		for (; i < size; i++) { y[i] = x[i + 1]; }
		delete[] x; x = y;
	}
	return;
}

void SETNUM::DeleteElement(int z) {
	if (Contains(z)) {
		DelSort(Element(z), z);
	}
	return;
}

void SETNUM::Output() const {
	printf("Множество чисел: ");
	for (int i = 0; i < size; i++) { printf("%d ", x[i]); }
	printf("\n");
}

SETNUM::~SETNUM() {
	delete[] x;
	size = 0;
}

bool SETNUM::operator == (const SETNUM& other) const {
	int i = 0; bool fl = true;
	if (size != other.size) { fl = false; }
	while (i < size && fl) {
		if (x[i] != other.x[i]) fl = false;
		i++;
	}
	return fl;
}

SETNUM& SETNUM::operator += (int z) {
	if (z > MAX || z < MIN) throw BAD_VALUE("Некорректное значение. Значение лежит вне разрешенного диапазона!\n"); 
	else {
		if (Contains(z)) throw REPEAT_ADD("Повторное добавление. Элемент уже находится в множестве!\n");
		else {
			AddSort(Element(z), z);
		}
	}
	return *this;
}

SETNUM SETNUM::operator + (const SETNUM& other) const {
	SETNUM s(*this);
	for (int i = 0; i < other.size; i++) {
		s.AddElement(other.x[i]);
	}
	return s;
}

SETNUM SETNUM::operator - (const SETNUM& other) const {
	SETNUM s(*this);
	for (int i = 0; i < other.size; i++) {
		s.DeleteElement(other.x[i]);
	}
	return s;
}

SETNUM SETNUM::operator * (const SETNUM& other) const {
	SETNUM s1; int j = 0;
	for (int i = 0; i < size; i++) {
		if (Contains(x[i]) && other.Contains(x[i])) {
			s1.AddSort(j, x[i]); j++;
		}
	}
	return s1;
}

SETNUM& SETNUM::operator -= (int z) {
	if (!Contains(z)) throw (REPEAT_DEL("Удаление элемента, которого нет в множестве."));
	else {
		DelSort(Element(z), z);
	}
	return *this;
}

SETNUM& SETNUM::operator = (const SETNUM& other) {
	size = other.size;
	x = new int[other.size];
	for (int i = 0; i < other.size; i++) {
		x[i] = other.x[i];
	}
	return *this;
}
