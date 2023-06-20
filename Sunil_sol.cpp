#include <iostream>
#include <vector>

using namespace std;

//  p = Power of Abhimanyu, a = Number of times Abhimanyu can skip fighting the enemy, 
//  b = Number of times Abhimanyu can recharge his power

bool canAbhimanyuCrossChakravyuha(int p, int a, int b, const vector<int>& enemies) {
    int n = enemies.size();
    int currPower = p;
    int rechargeCount = 0;

    for (int i = 0; i < n; i++) {
        // Check if Abhimanyu's power is less than the current enemy's power
        if (currPower < enemies[i])
            return false;

        // Check if Abhimanyu can skip fighting the enemy
        if (a > 0) {
            a--;
            continue;
        }

        // Reduce Abhimanyu's power by the enemy's power
        currPower -= enemies[i];

        // Check if the enemy can regenerate and attack from behind
        if ((i + 1) % 11 == 3 || (i + 1) % 11 == 7) {
            int regenPower = enemies[i] / 2;
            if (currPower <= regenPower)
                return false;

            // Abhimanyu is attacked from behind, so reduce his power again
            currPower -= regenPower;
        }

        // Check if Abhimanyu can recharge his power
        if (rechargeCount < b) {
            rechargeCount++;
            currPower = p; // Recharge Abhimanyu's power
        }
    }

    return true; // Abhimanyu successfully crossed the Chakravyuha
}

int main() {
    // Test case 1
    vector<int> enemies1 = {1, 2, 6, 8, 5, 3, 1, 7, 9, 3, 2};
    int p1 = 15;
    int a1 = 3;
    int b1 = 5;
    if (canAbhimanyuCrossChakravyuha(p1, a1, b1, enemies1))
        cout << "Abhimanyu can cross the Chakravyuha for test case 1." << endl;
    else
        cout << "Abhimanyu cannot cross the Chakravyuha for test case 1." << endl;

    // Test case 2
    vector<int> enemies2 = {1, 2, 6, 8, 5, 3, 1, 4, 9, 3, 2};
    int p2 = 4;
    int a2 = 1;
    int b2 = 4;
    if (canAbhimanyuCrossChakravyuha(p2, a2, b2, enemies2))
        cout << "Abhimanyu can cross the Chakravyuha for test case 2." << endl;
    else
        cout << "Abhimanyu cannot cross the Chakravyuha for test case 2." << endl;

    return 0;
}