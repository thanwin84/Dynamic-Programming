// since target parameter is too large, we can't memoize it
class Solution {
    int inf = 600;
public:
	int solve(vector<vector<int>>& stations, int startDist, int remainingFuel,int target, int pos) {
        if (remainingFuel >= target - startDist){
            return 0;
        }
		// checking if we can arrive at the destination with remaining fuel
		if (pos == stations.size()) {
			// enough fuel
			if (remainingFuel >= target - startDist) {
				return 0;
			}
			// not enough fuel
			return inf;
		}
		int distance_to_cover = stations[pos][0] - startDist;
		if (remainingFuel < distance_to_cover) {
			return inf;
		}

		int including = inf;
		int excluding = inf;
		if (distance_to_cover <= remainingFuel) {
			including = solve(stations, stations[pos][0], remainingFuel - distance_to_cover + stations[pos][1], target, pos + 1);
		}
		excluding = solve(stations, startDist, remainingFuel, target, pos + 1);
		return 1 + min(including, excluding);
	}
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
		int result = solve(stations, 0, startFuel, target, 0);
        if (result >= inf){
            return -1;
        }
        return result;
	}
};
