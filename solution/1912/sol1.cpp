class MovieRentingSystem {
public:
    struct Info{
        int movie,price,status;
        Info(int m,int p,int s):movie(m),price(p),status(s){}
        bool operator<(const Info&rhs)const{
            if (price==rhs.price){
                return movie<rhs.movie;
            }
            return price < rhs.price;
        }
    };
    struct Node{
        int sid,price;
        Node(int id,int p):sid(id),price(p){}
        bool operator<(const Node&rhs)const{
            if (price==rhs.price){
                return sid<rhs.sid;
            }
            return price < rhs.price;
        }
    };
    struct Node2{
        int sid,movie,price;
        Node2(int id,int m,int p):sid(id),movie(m),price(p){}
        bool operator<(const Node2&rhs)const{
            if (price==rhs.price){
                if (sid==rhs.sid){
                    return movie<rhs.movie;
                }
                return sid<rhs.sid;
            }
            return price < rhs.price;
        }
    };
    set<Node> S[10010];
    set<Node2> S2;
    map<int,pair<int,int>> sp[300010];
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i=0;i<entries.size();++i){
            int id=entries[i][0],m=entries[i][1],p=entries[i][2];
            sp[id][m]={p,0};
            S[m].insert(Node(id,p));
        }
        S2.clear();
    }
    
    vector<int> search(int movie) {
        auto x=S[movie];
        int i=0;
        vector<int> res;
        for (auto it=x.begin();it!=x.end();++it){
            i++;
            if (i==6){
                break;
            }
            res.emplace_back(it->sid);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int p=sp[shop][movie].first;
        auto it2=S[movie].find(Node(shop,p));
        // cout<<(it2->price)<<" "<<(it2->sid)<<" "<<shop<<" "<<p<<endl;
        S[movie].erase(it2);
        S2.insert(Node2(shop,movie,p));
        sp[shop][movie].second=1;;
    }
    
    void drop(int shop, int movie) {
        int p=sp[shop][movie].first;
        S[movie].insert(Node(shop,p));
        auto it2=S2.find(Node2(shop,movie,p));
        S2.erase(it2);
        sp[shop][movie].second=0;;
    }
    
    vector<vector<int>> report() {
        int i=0;
        vector<vector<int>> res;
        for (auto it=S2.begin();it!=S2.end();++it){
            i++;
            if (i==6){
                break;
            }
            res.emplace_back(vector<int>{it->sid,it->movie});
        }
        return res;
    }
};
/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

