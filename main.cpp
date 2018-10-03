#include <iostream>
#include <cstdint>
#include <cmath>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

float fast_sqrt(float number) {
	union {
		float f;
		uint32_t i;
	} conv;

	float x2;
	const float threehalfs = 1.5f;

	x2 = number * 0.5f;
	conv.f = number;
	conv.i = 0x1FBD1EB8 + (conv.i >> 1);
	conv.f = conv.f * (threehalfs - (x2 * conv.f * conv.f));
	return conv.f;
}

int main() {
	float x;
	DWORD start, end;

	start = timeGetTime();
	for (int i = 0; i < 10000000; i++) {
		x = static_cast<float>(i);
		fast_sqrt(x);
	}
	end = timeGetTime();
	std::cout << "闇のsqrt = " << (double)(end - start) / 1000 << "sec.\n";

	start = timeGetTime();
	for (int i = 0; i < 10000000; i++) {
		x = static_cast<float>(i);
		std::sqrt(x);
	}
	end = timeGetTime();
	std::cout << "Mathライブラリ = " << (double)(end - start) / 1000 << "sec.\n";

	while(1) {}

	return 0;
}