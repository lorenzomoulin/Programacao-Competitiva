#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int II = 0;

class No
{
public:
    int id;
    No *p;
    vector <No *> f;
    No (int a)
    {
        p = NULL;
        id = a;
    }
    No (int i, int a)
    {
        p = NULL;
        id = a;
        f.push_back (new No (i));
    }
    ~No ()
    {
        for (int i = 0; i < this->f.size (); i++)
            delete this->f[i];
    }
    void Correct (vector <No *> *inp)
    {
        for (int i = 0; i < (*inp).size (); i++)
        {
            if (i + 1 == this->id) continue;
            if ((*inp)[i] == NULL) continue;
            for (int j = 0; j < this->f.size (); j++)
            {
                if ((*inp)[i]->id == this->f[j]->id)
                {
                    delete this->f[j];
                    this->f[j] = (*inp)[i];
                    (*inp)[i] = NULL;
                }
            }
        }
        for (int i = 0; i < this->f.size (); i++)
        {
            this->f[i]->Correct (inp);
        }
    }
    void Print (int l)
    {
        for (int i = 0; i < l; i++) printf ("\t");
        if (l > 0) printf ("%d: ", this->p->id);
        printf ("%d\n", this->id);
        for (int i = 0; i < this->f.size (); i++)
            this->f[i]->Print (l + 1);
    }
};

int main() {
    int n, i, j, a;
    No *r;
    scanf ("%d", &n);
    vector <No *> inp (n - 1);
    for (i = 1; i < n; i++)
    {
        scanf ("%d", &a);
        inp[i - 1] = new No (i + 1, a);
        printf ("%d: %d\n", inp[i - 1]->id, inp[i - 1]->f.back ()->id);
    }
    r = inp[0];
    r->Print (0);
    r->Correct (&inp);
    for (i = 1; i < inp.size (); i++)
    {
        if (inp[i] == NULL) continue;
        r = inp[i];
        r->Correct (&inp);
    }
    delete r;
}
