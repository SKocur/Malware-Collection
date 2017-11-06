#include <thread>
#include <iostream>

// Change this value to fit your requirements
#define NUM_CORES 4

void executor() {
	double *i = 0;
	while (true) {
		(*i++) + 3.14;
	}
}

int main() {
	std::cout << "Available CPU cores: " << std::thread::hardware_concurrency() << std::endl;

	std::thread threads[NUM_CORES];

	for (int i = 0; i < NUM_CORES; i++) {
		threads[i] = std::thread(executor);
	}

	for (int i = 0; i < NUM_CORES; i++) {
		threads[i].join();
	}
}
