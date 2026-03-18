#include <iostream>
#include <list>
#include <string>

using namespace std;

struct job {
	int id;
	int pages;
	job(int id, int pages) : id(id), pages(pages) {}
};

int main() {

	int n; cin >> n;
	list<job> jobs;

	int totalPages = 0;

	string ans = "";

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "ADD") {
			int id; int pages;
			cin >> id >> pages;

			totalPages += pages;

			jobs.emplace_back(job(id, pages));
			continue;
		}

		if (cmd == "PROCESS") {
			if (jobs.empty()) {
				ans += "NO JOB\n";
				continue;
			}
			totalPages -= jobs.front().pages;
			ans += "Processed " + to_string(jobs.front().id) + '\n';
			jobs.pop_front();
			continue;
		}

		if (cmd == "NEXT") {
			if (jobs.empty()) {
				ans += "NO JOB\n";
				continue;
			}
			ans += to_string(jobs.front().id) + ' ' + to_string(jobs.front().pages) + '\n';
			continue;
		}

		if (cmd == "TOTAL") {
			ans += to_string(jobs.size()) + '\n';
			continue;
		}

		if (cmd == "PAGES") {
			ans += to_string(totalPages) + '\n';
			continue;
		}

	}

	cout << ans;

	return 0;

}
