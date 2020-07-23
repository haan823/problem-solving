#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int test_case;
char input[100][1000][2];

class cube
{
public:
    char top[3][3];
    char bottom[3][3];
    char front[3][3];
    char back[3][3];
    char right_[3][3];
    char left_[3][3];

    void Init_()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                top[i][j] = 'w';
                bottom[i][j] = 'y';
                front[i][j] = 'r';
                back[i][j] = 'o';
                right_[i][j] = 'b';
                left_[i][j] = 'g';
            }
        }
    }

    void U_plus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = front[0][i];
            front[0][i] = right_[0][i];
            right_[0][i] = back[0][i];
            back[0][i] = left_[0][i];
            left_[0][i] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = top[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                top[i][j] = tmp[i][j];
            }
        }
    }

    void U_minus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = front[0][i];
            front[0][i] = left_[0][i];
            left_[0][i] = back[0][i];
            back[0][i] = right_[0][i];
            right_[0][i] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[2 - j][i] = top[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                top[i][j] = tmp[i][j];
            }
        }
    }

    void D_plus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = front[2][i];
            front[2][i] = left_[2][i];
            left_[2][i] = back[2][i];
            back[2][i] = right_[2][i];
            right_[2][i] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = bottom[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                bottom[i][j] = tmp[i][j];
            }
        }
    }

    void D_minus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = front[2][i];
            front[2][i] = right_[2][i];
            right_[2][i] = back[2][i];
            back[2][i] = left_[2][i];
            left_[2][i] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[2 - j][i] = bottom[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                bottom[i][j] = tmp[i][j];
            }
        }
    }

    void F_plus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[2][i];
            top[2][i] = left_[2 - i][2];
            left_[2 - i][2] = bottom[0][2 - i];
            bottom[0][2 - i] = right_[i][0];
            right_[i][0] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = front[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                front[i][j] = tmp[i][j];
            }
        }
    }

    void F_minus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[2][i];
            top[2][i] = right_[i][0];
            right_[i][0] = bottom[0][2 - i];
            bottom[0][2 - i] = left_[2 - i][2];
            left_[2 - i][2] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[2 - j][i] = front[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                front[i][j] = tmp[i][j];
            }
        }
    }

    void B_plus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[0][2 - i];
            top[0][2 - i] = right_[2 - i][2];
            right_[2 - i][2] = bottom[2][i];
            bottom[2][i] = left_[i][0];
            left_[i][0] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = back[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                back[i][j] = tmp[i][j];
            }
        }
    }

    void B_minus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[0][2 - i];
            top[0][2 - i] = left_[i][0];
            left_[i][0] = bottom[2][i];
            bottom[2][i] = right_[2 - i][2];
            right_[2 - i][2] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[2 - j][i] = back[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                back[i][j] = tmp[i][j];
            }
        }
    }

    void L_plus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[i][0];
            top[i][0] = back[2 - i][2];
            back[2 - i][2] = bottom[i][0];
            bottom[i][0] = front[i][0];
            front[i][0] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = left_[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                left_[i][j] = tmp[i][j];
            }
        }
    }

    void L_minus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[i][0];
            top[i][0] = front[i][0];
            front[i][0] = bottom[i][0];
            bottom[i][0] = back[2 - i][2];
            back[2 - i][2] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[2 - j][i] = left_[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                left_[i][j] = tmp[i][j];
            }
        }
    }

    void R_plus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[i][2];
            top[i][2] = front[i][2];
            front[i][2] = bottom[i][2];
            bottom[i][2] = back[2 - i][0];
            back[2 - i][0] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[j][2 - i] = right_[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                right_[i][j] = tmp[i][j];
            }
        }
    }

    void R_minus()
    {
        for (int i = 0; i < 3; i++)
        {
            char tmp = top[i][2];
            top[i][2] = back[2 - i][0];
            back[2 - i][0] = bottom[i][2];
            bottom[i][2] = front[i][2];
            front[i][2] = tmp;
        }
        char tmp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tmp[2 - j][i] = right_[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                right_[i][j] = tmp[i][j];
            }
        }
    }
};

int main()
{
    cube c;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j][0];
            cin >> input[i][j][1];
        }
    }
    for (int i = 0; i < test_case; i++)
    {
        c.Init_();
        for (int j = 0; j < 1000; j++)
        {
            if (input[i][j][0] == 'F')
            {
                if (input[i][j][1] == '+')
                {
                    c.F_plus();
                }
                else
                {
                    c.F_minus();
                }
            }
            else if (input[i][j][0] == 'B')
            {
                if (input[i][j][1] == '+')
                {
                    c.B_plus();
                }
                else
                {
                    c.B_minus();
                }
            }
            else if (input[i][j][0] == 'U')
            {
                if (input[i][j][1] == '+')
                {
                    c.U_plus();
                }
                else
                {
                    c.U_minus();
                }
            }
            else if (input[i][j][0] == 'D')
            {
                if (input[i][j][1] == '+')
                {
                    c.D_plus();
                }
                else
                {
                    c.D_minus();
                }
            }
            else if (input[i][j][0] == 'L')
            {
                if (input[i][j][1] == '+')
                {
                    c.L_plus();
                }
                else
                {
                    c.L_minus();
                }
            }
            else if (input[i][j][0] == 'R')
            {
                if (input[i][j][1] == '+')
                {
                    c.R_plus();
                }
                else
                {
                    c.R_minus();
                }
            }
            else
            {
                break;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << c.top[j][k];
            }
            cout << "\n";
        }
    }
}