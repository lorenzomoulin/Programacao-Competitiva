#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
using namespace std;

struct team{
    char name[50];
    int points, wins, goals_diff, goals_scored, games_played;
    int ties, losses, goals_against;
};

bool char_cmp(char a, char b){
    return tolower(a) < tolower(b);
}

bool cmp(team a, team b){
    if (a.points == b.points){
        if (a.wins == b.wins){
            if (a.goals_diff == b.goals_diff){
                if(a.goals_scored == b.goals_scored){
                    if (a.games_played == b.games_played){
                        string c = a.name, d = b.name;
                        return lexicographical_compare(all(c), all(d), char_cmp);
                        
                    }   
                    
                    return a.games_played < b.games_played;
                }
                
                else 
                    return a.goals_scored > b.goals_scored;
            }
            
            else
                return a.goals_diff > b.goals_diff;
        }
        else 
            return a.wins > b.wins;
    }
    else 
        return a.points > b.points;
}

int main(){
    
    int n;
    scanf("%d\n", &n);
    
    while(n--){
        char tournament[200];
        scanf("%[^\n]\n", tournament);
        int t;
        //printf("%s\n", tournament);
        scanf("%d\n", &t);
        team times[t];
        
        rep(i, 0 , t){
            char temp[50];
            scanf("%[^\n]\n", temp);
            strcpy(times[i].name, temp);
            times[i].wins = times[i].points = times[i].goals_diff = times[i].goals_scored = 0;
            times[i].goals_against = times[i].games_played = times[i].ties = times[i].losses = 0;
            
        }
        //printf("debug\n");
        int n_jogos;
        scanf("%d\n", &n_jogos);
        rep(i,0 , n_jogos){
            char time1[50], time2[50];
            int goals1, goals2;
            scanf("%[^#]#%d@%d#%[^\n]\n", time1, &goals1, &goals2, time2);
            
            //update teams
            rep(j, 0, t){
                
                if(!strcmp(times[j].name, time1)){
                    times[j].games_played++, times[j].wins+= goals1 > goals2;
                    times[j].losses += goals1 < goals2, times[j].ties += goals1 == goals2;
                    times[j].goals_against += goals2, times[j].goals_scored += goals1;
                    times[j].goals_diff += goals1 - goals2;
                    goals1 == goals2? times[j].points++: (goals1 > goals2? times[j].points += 3: times[j].points += 0);
                }
                else if(!strcmp(times[j].name, time2)){
                    times[j].games_played++, times[j].wins+= goals2 > goals1;
                    times[j].losses += goals2 < goals1, times[j].ties += goals1 == goals2;
                    times[j].goals_against += goals1, times[j].goals_scored += goals2;
                    times[j].goals_diff += goals2 - goals1;
                    goals1 == goals2? times[j].points++: (goals2 > goals1? times[j].points += 3: times[j].points += 0);
                }
            }     
        }
        printf("%s\n", tournament);
        sort(times, times + t, cmp);
        rep(i, 0, t){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, times[i].name, times[i].points, times[i].games_played, times[i].wins, times[i].ties, times[i].losses, times[i].goals_diff, times[i].goals_scored, times[i].goals_against);
        }
        if(n >= 1)
            printf("\n");
    }
    return 0;
}
