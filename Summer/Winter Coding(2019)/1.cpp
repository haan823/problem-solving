using namespace std;

long long solution(int w, int h)
{
    long long answer = 1;
    long long l_w = w;
    long long l_h = h;
    long long gcd;
    long long small;
    if (w < h)
    {
        small = w;
    }
    else
    {
        small = h;
    }

    for (long long i = small; i > 0; i--)
    {
        if (l_w % i == 0 && l_h % i == 0)
        {
            gcd = i;
            break;
        }
    }
    answer = (l_w * l_h) - gcd * ((l_w / gcd) + (l_h / gcd) - 1);
    return answer;
}