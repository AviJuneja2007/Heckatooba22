#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int cook[],int n,int p,int time){
    int count = 0;
    for(int i=0;i<n;i++){
        int t = 0;
        int next_time = cook[i];
        while(t + next_time <= time){
            count++;
            t+= next_time;
            next_time += cook[i];
            if(count >= p){
            return true;
            }
        }
    }
    return false;
    
}

int minTimeNeeded(int cook[],int n,int p){
    int s = 0;
    int e = cook[n-1]*(p*(p+1))/2;

    int finalAns = 0;
    while(s <= e){
        int mid = (s+e)/2;
        if(isPossible(cook,n,p,mid)){
            finalAns = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return finalAns;

}

int main(){
    int t;
    cin>>t;

    while(t--){
        int p;
        cin>>p;

        int n;
        cin>>n;

        int cook[51];

        for(int i=0;i<n;i++){
            cin>>cook[i];
        }
        sort(cook,cook+n);
        cout<<minTimeNeeded(cook,n,p)<<endl;
    }
}