class Student
{
    int scores[5];
    public:
    void input()
    {
        for(int i=0;i<5;i++)
        {
            cin>>scores[i];
        }
    }
    int calculateTotalScore()
    {
        int total=0;
        for(int i=0;i<5;i++)
        {
            total+=scores[i];
        }
        return total;
    }
};