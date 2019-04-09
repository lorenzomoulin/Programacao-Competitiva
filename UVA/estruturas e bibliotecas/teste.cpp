#include<bits/stdc++.h>
#define CLR(a,b) memset(a, b, sizeof(a))

using namespace std;

map<string , int> teams;
map<string , int> :: iterator it;
int team_goal_dise[100], team_goal_khaise[100], total_khelse[100];
int winner[100], point[100], looser[100], draw[100];

struct data{
string teamname;
int point, goaldise, goal_diff, khelse, jitse;
};

bool cmp(data one, data two)
{
    char bread[105], butter[105];
    if(one.point==two.point)
    {
        if(one.jitse==two.jitse)
        {
            if(one.goal_diff==two.goal_diff)
            {
                if(one.goaldise == two.goaldise)
                {
                    if(one.khelse==two.khelse)
                    {
                        int szbread = one.teamname.size();
                        int szbutter = two.teamname.size();
                        for(int i=0; i<szbread; i++)
                            bread[i] = tolower(one.teamname[i]);
                        for(int i=0; i<szbutter; i++)
                            butter[i] = tolower(two.teamname[i]);
                        return strcmp(bread, butter)<0;
                    }
                    else return one.khelse<two.khelse;
                }
                else return one.goaldise>two.goaldise;
            }
            else return one.goal_diff>two.goal_diff;
        }
        else return one.jitse>two.jitse;
    }
    else return one.point>two.point;
}

int main()
{
    int test, n, m, goalone, goaltwo;
    string name, score, adi1, adi2, tourn_name;
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        getline(cin,tourn_name);
        //getchar();
        teams.clear();
        CLR(team_goal_dise, 0); CLR(team_goal_khaise, 0); CLR(looser,0);
        CLR(total_khelse, 0); CLR(winner, 0); CLR(point, 0); CLR(draw, 0);
        scanf("%d", &n);
        getchar();
        for(int i=0; i<n; i++)
        {
            getline(cin,name);
           // cout<<name<<endl;
            teams[name] = i;
        }
        scanf("%d",&m);
        getchar();
        for(int i=0; i<m; i++)
        {
            getline(cin,score);
            //cout<<score<<endl;
            int sz = score.size(), j;
            goalone = 0; adi1 = "";
            bool hashfound = false;
            for(j=0; score[j]!='@'; j++)
            {
                if(score[j]=='#') { hashfound = true; continue; }
                if(!hashfound)
                {
                    adi1 = adi1 + score[j];
                }
                else if(isdigit(score[j]))
                {
                    goalone = goalone*10 + (score[j]-'0');
                }
            }
            adi2 ="";goaltwo = 0; hashfound = false;
            for(int l=j+1; score[l]!='\0'; l++)
            {
                if(score[l]=='#') {hashfound = true; continue; }
                if(hashfound)
                {
                    adi2 = adi2 + score[l];
                }
                else if(isdigit(score[l]))
                {
                    goaltwo = goaltwo*10 + (score[l]-'0');
                }
            }
            //cout<<goalone<<' '<<adi1<<' '<<goaltwo<<' '<<adi2<<endl;
            team_goal_dise[teams[adi1]] = team_goal_dise[teams[adi1]] + goalone;
            team_goal_dise[teams[adi2]] = team_goal_dise[teams[adi2]] + goaltwo;
            team_goal_khaise[teams[adi1]] = team_goal_khaise[teams[adi1]] + goaltwo;
            team_goal_khaise[teams[adi2]] = team_goal_khaise[teams[adi2]] + goalone;
            total_khelse[teams[adi1]]++;
            total_khelse[teams[adi2]]++;
            if(goalone>goaltwo)
            {
                winner[teams[adi1]]++;
                looser[teams[adi2]]++;
                point[teams[adi1]] = point[teams[adi1]] + 3;
            }
            else if(goalone<goaltwo)
            {
                winner[teams[adi2]]++;
                looser[teams[adi1]]++;
                point[teams[adi2]] = point[teams[adi2]] + 3;
            }
            else
            {
                draw[teams[adi1]]++;
                draw[teams[adi2]]++;
                point[teams[adi1]] = point[teams[adi1]] + 1;
                point[teams[adi2]] = point[teams[adi2]] + 1;
            }
        }
        /*for(it=teams.begin(); it!=teams.end(); ++it)
        {
            cout<<it->first<<' '<<point[teams[it->first]]<<' ';
            cout<<total_khelse[teams[it->first]]<<' '<<winner[teams[it->first]]<<' ';
            cout<<draw[teams[it->first]]<<' '<<looser[teams[it->first]]<<' ';
            cout<<team_goal_dise[teams[it->first]]<<' '<<team_goal_khaise[teams[it->first]]<<endl;
        }*/
        data total_teams[100];
        for(it=teams.begin(); it!=teams.end(); ++it)
        {
            total_teams[it->second].point = point[it->second];
            total_teams[it->second].jitse = winner[it->second];
            total_teams[it->second].goal_diff = team_goal_dise[it->second] - team_goal_khaise[it->second];
            total_teams[it->second].goaldise = team_goal_dise[it->second];
            total_teams[it->second].khelse = total_khelse[it->second];
            total_teams[it->second].teamname = it->first;

        }
        sort(total_teams, total_teams+n, cmp);
        cout<<tourn_name<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<i+1<<')'<<' '<<total_teams[i].teamname<<' '<<total_teams[i].point<<"p, "<<total_teams[i].khelse<<"g ("<<winner[teams[total_teams[i].teamname]]<<'-';
            cout<<draw[teams[total_teams[i].teamname]]<<'-'<<looser[teams[total_teams[i].teamname]]<<"), "<<total_teams[i].goal_diff<<"gd (";
            cout<<team_goal_dise[teams[total_teams[i].teamname]]<<'-'<<team_goal_khaise[teams[total_teams[i].teamname]]<<')'<<endl;
        }
        if(test)
            printf("\n");
        //CLR(total_teams,0);
    }
    return 0;
}
