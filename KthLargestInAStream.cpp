
#include <vector>
#include <set>
using namespace std;

class KthLargest {
public:
    int k;
    multiset<int> s;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);

            if (s.size() > k) {
                s.erase(s.begin());
            }
        }
    }

    int add(int val) {
        s.insert(val);

        if (s.size() > k) {
            s.erase(s.begin());
        }

        return *s.begin();
    }
};
