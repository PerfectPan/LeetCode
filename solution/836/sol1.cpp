class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0],y1=rec1[1],x2=rec1[2],y2=rec1[3];

        int x11=rec2[0],y11=rec2[1],x21=rec2[2],y21=rec2[3];

        x1=max(x1,x11),y1=max(y1,y11);
        x2=min(x2,x21),y2=min(y2,y21);
        return x1<x2 && y1<y2;
    }
};

