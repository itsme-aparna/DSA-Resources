class Solution {
public:
int myAtoi(string s) {
stringstream ss;

    int z=0;
for(int i=0;i<s.length();i++)
{
if(s[i]>=48 && s[i]<=57)
{
z++;
}
}
int num;
ss<<s;
ss>>num;
if(z==0)
{
return 0;
}
else
{
return num;
}
}
};