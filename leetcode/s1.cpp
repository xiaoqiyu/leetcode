#include<iostream>
#include<cmath>
#include<vector>
#include<time.h>
#include<stdlib.h>

using namespace std;

const long long LEVEL = 8;
const long long LogN = LEVEL;
const long long N = pow(2, LEVEL);

vector<vector<long long> > tree;
long long nodeNumber = 2 * N;
long long M = LogN;
long long S = LogN;
long long STASHSIZE = 5;
long long ROUND = 10;

long long PERCENT = 10000;

vector<long long> MaxStashSize;

vector<long long> positionMap;
vector<long long> flushNode;
vector<long long> stash;

int main1(){
    long long LeftPath;
    long long RightPath;
    long long level;
    
    
    srand(time(NULL));
    
    tree.clear();
    tree.resize(nodeNumber);
    
    stash.clear();
    positionMap.clear();
    positionMap.resize(N / M, 0);
    
    long long cur = 0;
    long long flushPath;
    MaxStashSize.resize(ROUND, 0);
    for (int r = 0; r < ROUND; r++){
        for (long long i = 0; i < N / M; i++){ // num of trunk : i is trunk id
            //if (i * PERCENT * M > (cur - 100 * r) * N){
            //    cout << cur << "//" << PERCENT << endl;
            //    cur++;
            //}
            
            if (positionMap[i] == 0){
                flushPath = rand() % N + 1;
                for (long long j = 0; j < M; j++){
                    stash.push_back(i * M + j);
                }
            }
            else{
                flushPath = positionMap[i];
            }
            
    
            
            //get flush node
            flushNode.clear();
            LeftPath = flushPath + N - 1;
            RightPath = LeftPath + S - 1;
            level = N + N - 1;
            for (long long j = LEVEL; j >= 1; j--){
                for (long long k = LeftPath; k <= RightPath; k++){
                    if (k > level){
                        flushNode.push_back(k - (level + 1) / 2);
                    }
                    else{
                        flushNode.push_back(k);
                    }
                    
                }
                LeftPath /= 2;
                RightPath /= 2;
                level /= 2;
            }
            flushNode.push_back(1);
            
            cout<<"i:"<<i <<endl;
            for(long long j = 0; j < flushNode.size(); ++ j)
            {
                cout<<flushNode[j] <<endl;
            }
            return 0;
            
            long long newPath = rand() % N + 1;
            if(positionMap[i] == 0){
                positionMap[i] = newPath;
                //positionMap[i] = flushPath;
            }else{
                positionMap[i] = newPath;
            }
            
            for (vector<long long>::iterator vi = flushNode.begin(); vi != flushNode.end(); vi++){
                for (int j = 0; j < tree[*vi].size(); j++){
                    stash.push_back(tree[*vi][j]);
                }
                tree[*vi].clear();
            }
            
            
            
            for (long long k = 0; k < flushNode.size(); k++){
                for (vector<long long>::iterator vi = stash.begin(); vi != stash.end();){
                    if (tree[flushNode[k]].size() == STASHSIZE){
                        break;
                    }
                    int flag = 0;
                    long long BlockPathLeft = positionMap[*vi / M] + N - 1;
                    long long BlockPathRight = BlockPathLeft + S - 1;
                    if (BlockPathRight > nodeNumber - 1){
                        BlockPathRight -= N;
                    }
                    
                    level = N;
                    while (flushNode[k] < level){
                        BlockPathLeft /= 2;
                        BlockPathRight /= 2;
                        level /= 2;
                        cout<<"level is: "<<level<<endl;
                    }
                    
                    
                    if (BlockPathRight < BlockPathLeft){
                        if (BlockPathLeft <= flushNode[k] || BlockPathRight >= flushNode[k]){
                            tree[flushNode[k]].push_back(*vi);
                            vi = stash.erase(vi);
                            flag = 1;
                        }
                    }
                    else{
                        if (BlockPathLeft <= flushNode[k] && BlockPathRight >= flushNode[k]){
                            tree[flushNode[k]].push_back(*vi);
                            vi = stash.erase(vi);
                            flag = 1;
                        }
                    }
                    if (0 == flag){
                        vi++;
                    }
                    
                }
                
            }
            if (MaxStashSize[r] < stash.size()){
                MaxStashSize[r] = stash.size();
            }
        }
    }
    
    for (int i = 0; i < MaxStashSize.size(); i++){
        cout << "round " << i << " Max Stash Size: " << MaxStashSize[i] << endl;
    }
    
    
    return 0;
}
