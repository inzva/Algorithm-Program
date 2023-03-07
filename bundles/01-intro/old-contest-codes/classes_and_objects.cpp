class Student{
public:
    int scores[5];
    
    void input(){
        for (int i=0; i < 5; i++)
            scanf("%d", scores + i);
    }
    
    int calculateTotalScore(){
        int ans = 0;
        for (int i=0; i < 5; i++)
            ans += scores[i];
        return ans;
    }
};