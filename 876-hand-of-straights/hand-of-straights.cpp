class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int, int> map;

        if (n % groupSize != 0) {
            return false;
        }

        for (int& freq : hand) {
            map[freq]++;
        }

        while (!map.empty()) {
            int curr = map.begin()->first; //smallest card

            for (int i = 0; i < groupSize; i++) {
                if (map[curr + i] == 0) {
                    return false;
                }
                
                map[curr + i]--;
                if (map[curr + i] < 1) {
                    map.erase(curr + i);
                }
            }
        }
        return true;
    }
};