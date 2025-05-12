#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job
struct Job {
    char id;       // Job ID
    int deadline;  // Deadline
    int profit;    // Profit
};

// Sort jobs by descending profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job id, deadline, and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort the jobs based on profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline to create time slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    vector<char> schedule(maxDeadline + 1, '-'); // index 1-based
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Try to schedule the job at its deadline or earlier
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (schedule[j] == '-') {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != '-') {
            cout << schedule[i] << " ";
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}

/* 
Enter number of jobs: 5
Enter job id, deadline, and profit:
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
*/