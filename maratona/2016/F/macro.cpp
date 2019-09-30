#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

    int AAA = 1;
class No
{
public:
    int m;
    int id;
    No *p;
    No *e;
    No *c;
    No *d;
    No () {id = -1; m = 1; p = NULL; e = NULL, c = NULL; d = NULL;}
    No (int id_e) {id = id_e; m = 1; p = NULL; e = NULL, c = NULL; d = NULL;}
    ~No () {delete e; delete c; delete d;}
    void addM (int id_f, int m_f)
    {
        if (this->c != NULL)
        {
            if (this->c->id == id_f)
            {
                m = m_f + 1;
                if (this->p != NULL)
                {
                    this->p->addM(this->id, this->m);
                }
            }
        }
    }
    void addNo (int pos, No *no)
    {
        switch (pos)
        {
            case 1:
                this->e = no;
                break;
            case 2:
                this->c = no;
                m = no->m + 1;
                if (this->p != NULL) this->p->addM (this->id, this->m);
                break;
            case 3:
                this->d = no;
                break;
        }
        no->p = this;
    }
    int getBigM ()
    {
        int em = -1, cm = -1, dm = -1;
        if (this->e != NULL) em = this->e->getBigM ();
        if (this->c != NULL) cm = this->c->getBigM ();
        if (this->d != NULL) dm = this->d->getBigM ();
        return max (max ( max (em, cm), dm), this->m);
    }
    void correctInput (No **aux)
    {
        if (this->e != NULL)
        {
            No *cure = aux[this->e->id];
            if (cure != NULL)
            {
                delete this->e;
                this->addNo (1, cure);
                aux [this->e->id] = NULL;
                this->e->correctInput (aux);
            }
        }
        if (this->c != NULL)
        {
            No *curc = aux[this->c->id];
            if (curc != NULL)
            {
                delete this->c;
                this->addNo (2, curc);
                aux [this->c->id] = NULL;
                this->c->correctInput (aux);
            }
        }
        if (this->d != NULL)
        {
            No *curd = aux[this->d->id];
            if (curd != NULL)
            {
                delete this->d;
                this->addNo (3, curd);
                aux [this->d->id] = NULL;
                this->d->correctInput (aux);
            }
        }
    }
    void printM ()
    {
        printf ("id: %d | m: %d\n", this->id, this->m);
        if (this->e != NULL) 
        {
            this->e->printM ();
        }
        if (this->c != NULL)
        {
            this->c->printM ();
        }
        if (this->d != NULL)
        {
            this->d->printM ();
        }
    }
};


int main()
{
    int N, M, I, L, K, P, Q, R, i, j;
    scanf ("%d", &N);
    No *auxe[N];
    for (i = 0; i < N; i++) auxe[i] = NULL;
    for (i = 0; i < N; i++)
    {
        scanf ("%d %d %d", &I, &L, &K);
        auxe[I] = new No (I);
        if (L) auxe[I]->e = new No (L);
        if (K) auxe[I]->c = new No (K);
    }
    scanf ("%d", &M);
    No* auxd[M];
    for (i = 0; i < M; i++) auxd[i] = NULL;
    for (i = 0; i < M; i++)
    {
        scanf ("%d %d %d", &P, &Q, &R);
        auxd[P] = new No (P);
        if (Q) auxd[P]->c = new No (Q);
        if (R) auxd[P]->d = new No (R);
    }
    bool flage = true, flagd = true;
    No *roote = auxe[1];
    roote->correctInput (auxe);
    No *rootd = auxd[1];
    rootd->correctInput (auxd);
    while (flage || flagd)
    {
        flage = false; flagd = false;
        for (i = 2; i <= N; i++)
        {
            if (auxe[i] != NULL)
            {
                if (auxe[i]->id != roote->id)
                {
                    roote = auxe[i];
                    roote->correctInput (auxe);
                    flage = true;
                }
            }
        }
        for (i = 2; i <= M; i++)
        {
            if (auxd[i] != NULL)
            {
                if (auxd[i]->id != rootd->id)
                {
                    rootd = auxd[i];
                    rootd->correctInput (auxd);
                    flagd = true;
                }
            }
        }
    }
    //roote->printM();
    //printf ("---------------------------------------------------\n");
    //rootd->printM();
    printf ("%d\n", N + M - min (roote->getBigM (), rootd->getBigM ()));
    return 0;
}
