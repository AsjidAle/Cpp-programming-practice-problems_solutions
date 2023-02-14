#include <iostream>
unsigned int datediff(int y1, int m1, int d1, int y2, int m2, int d2, int &yd, int &md, int &dd)
{
    yd = y1 - y2;
    if (yd < 0)
    {
        yd *= (-1);
    }
    md = m1 - m2;
    if (md < 0)
    {
        md *= (-1);
    }
    dd = d1 - d2;
    if (dd < 0)
    {
        dd *= (-1);
    }
    int months_to_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days_1 = 0;
    for (int i = 0; i < m1; i++)
    {
        total_days_1 += months_to_days[i];
    }
    int total_days_2 = 0;
    for (int i = 0; i < m1; i++)
    {
        total_days_2 += months_to_days[i];
    }
    int x;
    x=(total_days_1-total_days_2);
    if(x<0){x*=(-1);}
    x = (((yd / 4) * 366) + (yd - (yd / 4)) * 365+x+dd);
    return x;
}
unsigned int timediff(int h1,int m1,int s1,int h2,int m2, int s2,int &hd,int &md,int &sd){
    hd=h1-h2;
    if(hd<0){hd*=(-1);}
    md=m1-m2;
    if(md<0){md*=(-1);}
    sd=s2-s1;
    if(s2<0){s2*=(-1);}
    return (hd*60*60+md*60+sd);
}
int main()
{
    int y, d, m;
    std::cout<<datediff(2019,2,3,2011,1,2,y,m,d)<<" is total difference in days";
    std::cout <<"\nyear difference "<<y <<" month difference " << m <<" day differnece "<< d;
    std::cout<<"\nTotal Difference in seconds is "<<timediff(12,2,3,1,5,3,y,d,m);
    std::cout<<"\nHours diference "<<y<<" Minutes difference "<<d<<" Seconds difference "<<m;
    return 0;
}