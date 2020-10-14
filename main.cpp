#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

void findNextLargest(vector<int> arr, vector<int> &res, int n) {
    queue<int> q;

    for (int i = n - 1; i >= 0; i--) {
        queue<int> temp;
        while (!q.empty() && q.front() >= arr[i]) {
            temp.push(q.front());
            q.pop();
        }
        q = temp;
        res[i] = (q.empty()) ? -1 : q.back();
        q.push(arr[i]);
    }
}

void findPreviousLargest(vector<int> arr, vector<int> &res, int n) {
    queue<int> q;

    for (int i = 0; i < n; i++) {
        queue<int> temp;
        while (!q.empty() && q.front() >= arr[i]) {
            temp.push(q.front());
            q.pop();
        }
        q = temp;
        res[i] = q.empty() ? -1 : q.back();
        q.push(arr[i]);
    }
}

void findNextSmallest(vector<int> arr, vector<int> &res, int n) {
    queue<int> q;

    for (int i = n - 1; i >= 0; i--) {
        queue<int> temp;
        while (!q.empty() && q.front() < arr[i]) {
            temp.push(q.front());
            q.pop();
        }
        q = temp;
        res[i] = q.empty() ? -1 : q.back();
        q.push(arr[i]);
    }
}

void findPreviousSmallest(vector<int> arr, vector<int> &res, int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        queue<int> temp;
        while (!q.empty() && q.front() < arr[i]) {
            temp.push(q.front());
            q.pop();
        }
        q = temp;
        res[i] = q.empty() ? -1 : q.back();
        q.push(arr[i]);
    }
}

void print(const vector<int> &res, const vector<int> &arr, const string &s) {
    cout << s << endl;
    for (int i:arr)
        cout << i << "  ";
    cout << endl;
    for (int i:res)
        cout << i << " ";
    cout << "\n\n";
}
//Largest -->  decreasing queue
//Smallest --> increasing queue

int main() {
    vector<int> arr = {2, 4, 51, 3, 1, 99, 2, 55, 2, 5, 6, 88, 5};
//    vector<int> arr = {5, 3, 1, 2, 4};
    int n = arr.size();
    vector<int> res(n, -1);

    //Next Largest
    findNextLargest(arr, res, n);
    print(res, arr, "Next Largest of each element in the array:");

    //Previous Largest
    fill(res.begin(), res.end(), -1);
    findPreviousLargest(arr, res, n);
    print(res, arr, "Previous Largest of each element in the array:");


    //Next Smallest
    fill(res.begin(), res.end(), -1);
    findNextSmallest(arr, res, n);
    print(res, arr, "Next Smallest of each element in the array:");

    //Previous Smallest
    fill(res.begin(), res.end(), -1);
    findPreviousSmallest(arr, res, n);
    print(res, arr, "Previous Smallest of each element in the array:");


    return 0;
}
