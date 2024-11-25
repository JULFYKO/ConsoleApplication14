#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::sort;
class PriorityQueue {
private:
    struct Element {
        int value;
        int priority;
        Element(int v, int p) : value(v), priority(p) {}
    };
    vector<Element> queue;
    static bool compare(const Element& a, const Element& b) {
        return a.priority > b.priority;
    }

public:
    bool IsEmpty() const {
        return queue.empty();
    }

    bool IsFull() const {
        return false;
    }

    void InsertWithPriority(int value, int priority) {
        queue.emplace_back(value, priority);
        sort(queue.begin(), queue.end(), compare);
    }

    int PullHighestPriorityElement() {
        if (IsEmpty()) {
            cout << "err.\n";
            return -1;
        }
        int value = queue.front().value;
        queue.erase(queue.begin());
        return value;
    }

    int Peek() const {
        if (IsEmpty()) {
            cout << "err.\n";
            return -1;
        }
        return queue.front().value;
    }

    void Show() const {
        if (IsEmpty()) {
            cout << "err.\n";
            return;
        }
        cout << "queue elements:\n";
        for (const auto& elem : queue) {
            cout << "(" << elem.value << ", " << elem.priority << ")\n";
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.InsertWithPriority(10, 2);
    pq.InsertWithPriority(20, 5);
    pq.InsertWithPriority(15, 3);

    cout << "queue:\n";
    pq.Show();

    cout << "highest priority element: " << pq.Peek() << "\n";

    cout << "pull highest priority element: " << pq.PullHighestPriorityElement() << "\n";

    cout << "queue after pulling highest priority element:\n";
    pq.Show();

    return 0;
}
