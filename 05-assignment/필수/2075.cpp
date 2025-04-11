#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N;
    cin >> N;

    //최소 힙을 사용하여 N개의 가장 큰 값 유지
    priority_queue<int, vector<int>, greater<int>> smallHeap;

    int num;
    for (int i = 0; i < N * N; i++) { //모든 값을 하나씩 입력받기
        cin >> num;

        //힙의 크기가 N보다 작은 경우 그냥 삽입
        if (smallHeap.size() < N) {
            smallHeap.push(num);
        }
        else if (smallHeap.top() < num) {
            //힙의 크기가 N이면 가장 작은 값보다 큰 경우만 교체
            smallHeap.pop();
            smallHeap.push(num);
        }
    }
    //N번째로 큰 수는 최소 힙의 top에 위치
    cout << smallHeap.top() << '\n';
    return 0;

}