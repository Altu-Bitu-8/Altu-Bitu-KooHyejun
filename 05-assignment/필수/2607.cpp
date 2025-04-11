
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

// 알파벳 빈도를 계산하는 함수
map<char, int> getCharFrequency(const string& word) {
    map<char, int> frequency;
    for (char c : word) {
        frequency[c]++;
    }
    return frequency;
}

// 비슷한 단어인지 확인하는 함수
bool isSimilarWord(const map<char, int>& baseFreq, const string& target, int baseLength) {
    int targetLength = target.size();
    if (abs(baseLength - targetLength) > 1) {
        return false; // 길이 차이가 2 이상이면 비슷하지 않음
    }

    map<char, int> targetFreq = getCharFrequency(target);
    int add = 0, remove = 0, diff = 0;

    // 빈도 차이를 계산
    for (auto& [ch, count] : baseFreq) {
        int gap = targetFreq[ch] - count;
        if (gap > 0) {
            add += gap;
        }
        else if (gap < 0) {
            remove += -gap;
        }
    }

    // targetFreq에 남아있는 추가 문자를 확인
    for (auto& [ch, count] : targetFreq) {
        if (baseFreq.find(ch) == baseFreq.end()) {
            add += count;
        }
    }

    diff = add + remove;

    // 비슷한 단어 조건: 문자 교환, 추가, 삭제가 1 이하일 경우
    return diff <= 2 && max(add, remove) <= 1;
}

int main() {
    int wordCount;
    cin >> wordCount;

    string baseWord;
    cin >> baseWord;
    int baseLength = baseWord.size();
    map<char, int> baseFreq = getCharFrequency(baseWord);

    int similarCount = 0;
    for (int i = 1; i < wordCount; i++) {
        string currentWord;
        cin >> currentWord;

        if (isSimilarWord(baseFreq, currentWord, baseLength)) {
            similarCount++;
        }
    }

    cout << similarCount << '\n';
    return 0;
}
