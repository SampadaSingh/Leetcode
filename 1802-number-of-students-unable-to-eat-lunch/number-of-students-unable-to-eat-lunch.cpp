class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int preferenceCount[2] = {0}; // preferenceCount[0] for students who prefer 0 sandwiches, preferenceCount[1] for students who prefer 1 sandwiches
        
        for (int student : students)
            preferenceCount[student]++;
        
        for (int sandwich : sandwiches) {
            if (preferenceCount[sandwich] == 0)
                break; // No students left who prefer this type of sandwich
            preferenceCount[sandwich]--;
        }
        
        return preferenceCount[0] + preferenceCount[1];
    }
};
