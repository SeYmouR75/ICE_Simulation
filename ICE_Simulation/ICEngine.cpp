#include "ICEngine.h"
#include <cmath>

void ICEngine::Start(int environment_temp) {
	double Vh = 0, Vc = 0, m = 0, v = 0;
	current_temp = environment_temp;

	while (current_temp < overheat_temp) {

		if (overheat_time < M.size() && overheat_time < V.size()) {
			m = M[overheat_time];
			v = V[overheat_time];
		}

		acceleration = m / I;

		N = m * v / 1000;

		if (N_max < N) N_max = N;

		Vh = m * Hm + pow(v, 2) * Hv;
		Vc = C * (environment_temp - current_temp);

		current_temp += Vh;
		current_temp -= Vc;

		overheat_time++;
	}
}