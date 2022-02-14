class Solution {
public:
    int p[5005],t[5005],pp[5005],ans[5005];
    bool isMagic(vector<int>& target) {
        int n=target.size();
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j) p[j]=j;
            int tot=0;
            int tot2=n;
            bool f=true;
            for (;f;){
                int even=tot2/2;
                int e=0,o=0;
                for (int j=1;j<=tot2;++j){
                    // cout<<tot2<<" "<<j<<" "<<p[j]<<endl;
                    if (j&1){
                        o++;
                        // cout<<o<<endl;
                        if (even+o<=i){
                            ans[tot+even+o]=p[j];
                            // printf("tot=%d ans[tot]=%d %d\n",tot,ans[tot],target[tot-1]);
                            if (ans[tot+even+o]!=target[tot+even+o-1]){
                                f=false;
                                break;
                            }
                        } else {
                            pp[even+o-i]=p[j];
                            // printf("even+o-i = %d %d\n",even+o-i,p[j]);
                        }
                    } else {
                        e++;
                        if (e<=i){
                            ans[tot+e]=p[j];
                            // printf("tot=%d ans[tot]=%d %d\n",tot,ans[tot],target[tot-1]);
                            if (ans[tot+e]!=target[tot+e-1]){
                                f=false;
                                break;
                            }
                        } else {
                            pp[e-i]=p[j];
                            // printf("even-i = %d %d\n",e-i,p[j]);
                        }
                    }
                }
                if (!f) break;
                tot+=i;
                int tot3=0;
                // puts("---");
                for (int k=1;k<=tot2-i;++k){
                    p[++tot3]=pp[k];
                    // printf("%d ",pp[k]);
                }
                // puts("");
                tot2=tot3;
                if (tot2==0) break;
            }
            if (f) return true;
            // cout<<"i "<<i<<endl;
        }
        return false;
    }   
};

