#include "comm.h"

class ATM {
public:
    ATM() : m_vec(5, 0) {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++)
        {
            m_vec[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ret(5, 0);
        vector<int> tmp_vec = m_vec;
        int v[5] = {20, 50, 100, 200, 500};
        int i = 4;
        while (true)
        {         
            if (amount == 0)
            {
                break;
            }
            else if (i < 0)
            {
                break;
            }

            int r = amount / v[i];
            int n = std::min(r, tmp_vec[i]);
            amount = amount - n * v[i];
            tmp_vec[i] -= n;
            ret[i] = n;

            i--;
        }

        if (amount == 0)
        {
            m_vec = tmp_vec;
            return ret;
        }
 
        return vector<int>{-1};
    }

    std::vector<int> m_vec;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */


int main()
{
    ATM s;
    vector<int> v1 {0, 0, 1, 2, 1};
    s.deposit(v1);
    std::cout << "with draw 600: " << s.withdraw(600) << "\n";
    vector<int> v2 { 0,1,0,1,1 };
    s.deposit(v2);
    std::cout << "with draw 600: " << s.withdraw(600) << "\n";
    std::cout << "with draw 550: " << s.withdraw(550) << "\n";
    return 0;
}