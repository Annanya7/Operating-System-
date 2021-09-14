#include<iostream>
using namespace std;
int main() {
	int n, burst_t[20], waiting_t[20], turnat[20], avg_wt = 0, avg_turnat = 0, i, j;
	cout << "Enter total number of processes";
	cin >> n;
	cout << "nEnter Process Burst Timen";
	for (i = 0; i < n; i++) {
		cout << "P[" << i + 1 << "]:";
		cin >> burst_t[i];
	}
	waiting_t[0] = 0;
	for (i = 1; i < n; i++) {
		waiting_t[i] = 0;//waiting time of first process is zero;
		for (j = 0; j < i; j++)
			waiting_t[i] += burst_t[j];
	}
	cout << "\n Burst Timet Waiting Time Turnaround Time\n";

	for (i = 0; i < n; i++) {
		turnat[i] = burst_t[i] + waiting_t[i];
		avg_wt += waiting_t[i];
		avg_turnat += turnat[i];
		cout << "\n" << i + 1 << burst_t[i] << waiting_t[i] << turnat[i] << endl;
	}
	avg_wt /= i;
	avg_turnat /= i;
	cout << "\nAverage Waiting Time:" << avg_wt;
	cout << "\nAverage Turnaround Time:" << avg_turnat;
	return 0;
}
