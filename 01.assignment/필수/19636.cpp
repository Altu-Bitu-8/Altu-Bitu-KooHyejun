#include <iostream>
using namespace std;

struct Person {
    int weight;
    int bmr;
    int threshold;
    int days;
    int intake;
    int activity;
};

int main() {
    Person de;
    cin >> de.weight >> de.bmr >> de.threshold;
    cin >> de.days >> de.intake >> de.activity;

    int noChangeWeight = de.weight + (de.intake-de.bmr-de.activity) * de.days;

    if (noChangeWeight <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << noChangeWeight << ' ' << de.bmr << '\n';
    }


    int weight = de.weight, bmr = de.bmr;

    for (int i = 0; i < de.days; i++) {
        int dailyChange = de.intake-bmr-de.activity;
        weight += dailyChange;

        if (abs(dailyChange) > de.threshold) {
            bmr += (dailyChange < 0) ? (dailyChange-1) / 2 : dailyChange / 2;
        }
    }

    if (weight <= 0 || bmr <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight <<' ' << bmr <<' ';
        cout << ((de.bmr-bmr > 0) ? "YOYO" : "NO") << '\n';
    }
}
