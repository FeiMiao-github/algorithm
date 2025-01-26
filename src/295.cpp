#include <comm.h>
#include <functional>
#include <ostream>
#include <queue>

template <typename T> class Gt {
public:
    bool operator()(T a, T b) { return a > b; }
};

template <typename T> class Le {
public:
    bool operator()(T a, T b) { return a < b; }
};

template <typename T, template <typename> typename Func> class Heap;

template <typename T, template <typename> typename Func>
std::ostream &operator<<(std::ostream &os, Heap<T, Func> &hp);

template <typename T, template <typename> typename Func> class Heap {
public:
    void push(T a) {
        data.push_back(a);
        size_t i = data.size() - 1;
        while (i > 0) {
            size_t j = (i - 1) >> 1;
            if (func(data[i], data[j])) {
                swap(data[i], data[j]);
            }
            i = j;
        }
    }
    T pop() {
        T ret = data[0];
        swap(data[0], data[data.size() - 1]);
        data.pop_back();
        size_t i = 0;
        while (2 * i + 1 < data.size()) {
            size_t l = i * 2 + 1, r = i * 2 + 2;
            size_t tgt_id = i;
            if (func(data[l], data[tgt_id])) {
                tgt_id = l;
            }
            if (r < data.size() && func(data[r], data[tgt_id])) {
                tgt_id = r;
            }
            swap(data[i], data[tgt_id]);
            i = tgt_id;
        }
        return ret;
    }

    T peek() { return data[0]; }

    size_t size() const { return data.size(); }

    friend std::ostream &operator<< <T, Func>(std::ostream &os,
                                              Heap<T, Func> &hp);

    std::vector<T> data;
    Func<T> func;
};

template <typename T, template <typename> typename Func>
std::ostream &operator<<(std::ostream &os, Heap<T, Func> &hp) {
    os << hp.data;
    return os;
}

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        if (leHeap.size() == 0 || num >= leHeap.peek()) {
            leHeap.push(num);
            if (leHeap.size() > gtHeap.size() + 1) {
                int v = leHeap.pop();
                gtHeap.push(v);
            }
        } else {
            gtHeap.push(num);
            if (gtHeap.size() > leHeap.size()) {
                auto v = gtHeap.pop();
                leHeap.push(v);
            }
        }
    }

    double findMedian() {
        if (gtHeap.size() == leHeap.size()) {
            return (gtHeap.peek() + leHeap.peek()) / 2.0;
        } else {
            return leHeap.peek();
        }
    }

    Heap<int, Gt> gtHeap;
    Heap<int, Le> leHeap;
};

void test(bool cond, const string &desc, const string &emsg = "") {
    if (cond) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << desc << ":" << emsg << "\n";
    }
}

void test1() {
    MedianFinder md;
    md.addNum(1);
    md.addNum(2);
    test(abs(md.findMedian() - 1.5) < 10e-5, "find median 1.5");

    md.addNum(3);

    double res = md.findMedian();
    stringstream ss;
    ss << res;
    test(abs(res - 2.0) < 10e-5, "find median 2.0", ss.str());
}

int main() {
    // test1();
    priority_queue<int, vector<int>, std::less<int>> pqless;
    for (int i : {1, 4, 5, 2, 3}) {
        pqless.push(i);
    }
    while (!pqless.empty()) {
        std::cout << pqless.top() << "\n";
        pqless.pop();
    }
    return 0;
}
