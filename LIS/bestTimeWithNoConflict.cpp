class Pair {
public:
	int age;
	int score;
	Pair(int age, int score) {
		this->age = age;
		this->score = score;
	}
};
bool comp(Pair& p1, Pair& p2) {
	if (p1.age < p2.age) {
		return true;
	}
	else if (p1.age == p2.age) {
		return p1.score < p2.score;
	}
	return false;
}
class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		vector<Pair> pair_list;
		vector<int> trackSum(scores.size(), 0);
		for (int i = 0; i < scores.size(); i++) {
			pair_list.push_back(Pair(ages[i], scores[i]));
		}
		sort(pair_list.begin(), pair_list.end(), comp);
		
		int possibleAns;
		int n = ages.size();
		int best_score = pair_list[0].score;
		trackSum[0] = best_score;
		for (int i = 1; i < n; i++) {
			trackSum[i] = pair_list[i].score;
			for (int j = 0; j < i; j++) {
				int possibleSum;
				if (pair_list[i].age == pair_list[j].age) {
					possibleSum = pair_list[i].score + trackSum[j];
					trackSum[i] = max(possibleSum, trackSum[i]);
				}
				else if (pair_list[i].age > pair_list[j].age) {
					if (pair_list[i].score >= pair_list[j].score) {
						possibleSum = pair_list[i].score + trackSum[j];
						trackSum[i] = max(possibleSum, trackSum[i]);
					}
				}
			}
			best_score = max(best_score, trackSum[i]);
		}
		return best_score;
	}
};
