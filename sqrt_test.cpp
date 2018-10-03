#include <cstdio>
#include <cstdint>

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
	while (1) {
		float x;
		scanf("%f", &x);
		float y = fast_sqrt(x);
		printf("%f\n", y);
	}

	return 0;
}