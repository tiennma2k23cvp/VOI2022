#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "475376A";
// Số test kiểm tra
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        int n = Rand(1, 10);
        inp << n << endl;
        for (int i = 1; i <= n; i++)
        {
            int a = Rand(-10000, 10000);
            inp << a << " ";
        }
        inp << endl;
        int q = Rand(1, 10);
        inp << q << endl;
        while (q--)
        {
            int type = rd() % 2;
            inp << type << ' ';
            if (type == 0)
            {
                int u = Rand(1, n);
                if (u < 0)
                    u += n;
                inp << u << ' ';
                int v = Rand(-10000, 10000);
                inp << v << ' ' << endl;
            }
            else
            {
                int u = Rand(1, n), v = Rand(1, n);
                if (u > v)
                    swap(u, v);
                inp << u << ' ' << v << endl;
            }
        }
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}