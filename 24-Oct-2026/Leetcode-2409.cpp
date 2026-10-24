
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aam = stoi(arriveAlice.substr(0, 2));
        int alm = stoi(leaveAlice.substr(0, 2));
        int aad = stoi(arriveAlice.substr(3, 2));
        int ald = stoi(leaveAlice.substr(3, 2));

        int bam = stoi(arriveBob.substr(0, 2));
        int blm = stoi(leaveBob.substr(0, 2));
        int bad = stoi(arriveBob.substr(3, 2));
        int bld = stoi(leaveBob.substr(3, 2));

        int cnt = 0;

        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j <= days[i - 1]; j++) {

                bool alice = (i > aam || (i == aam && j >= aad)) &&
                             (i < alm || (i == alm && j <= ald));

                bool bob = (i > bam || (i == bam && j >= bad)) &&
                           (i < blm || (i == blm && j <= bld));

                if (alice && bob) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
