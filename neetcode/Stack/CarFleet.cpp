#include "config.h"

class Solution {
	public:
		int carFleet(int target, vector<int>& position, vector<int>& speed) {

			vector<pair<int,double>> cars;
			for (int i = 0; i < position.size(); ++i) {
				cars.push_back({position[i], (double)(target - position[i]) / (double)speed[i]});	
			}

			sort(cars.begin(),cars.end());

			int n = 0;
			double maxTime = 0;

			for (int i = cars.size() - 1; i >= 0; --i) {
				if (cars[i].second > maxTime) {
					maxTime = cars[i].second;
					n++;
				}
			}

			return n;

		}
};
