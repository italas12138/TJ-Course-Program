/*#include <iostream>
using namespace std;

#define maxsize 1000

int far[maxsize][maxsize];

void Floyd(int n, int far[][maxsize])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (far[i][j] > far[i][k] + far[k][j])
                    far[i][j] = far[i][k] + far[k][j];
            }
        }
        far[k][k] = 0;
    }


    return;
}

void put_path(int far[][maxsize], int hor[][2], int gra[], int horse, int grass)
{
    for (int i = 0; i < horse; ++i)
    {
        int path = 0x7fffffff;
        for (int j = 0; j < grass; ++j)
        {
            if (far[hor[i][0]-1][gra[j]-1] + far[gra[j]-1][hor[i][1]-1] < path)
                path = far[hor[i][0]-1][gra[j]-1] + far[gra[j]-1][hor[i][1]-1];
        }
        cout << path << end_spacel;
    }
    return;
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            far[i][j] = 1000000;

    int v1, v2, fartance;
    for (int i = 0; i < M; ++i)
    {
        cin >> v1 >> v2 >> fartance;
        far[v1 - 1][v2 - 1] = fartance;
        far[v2 - 1][v1 - 1] = fartance;
    }

    int grass, horse;
    cin >> grass >> horse;

    int gra[maxsize];
    int hor[maxsize][2];

    for (int i = 0; i < grass; ++i)
        cin >> gra[i];

    for (int i = 0; i < horse; ++i)
        cin >> hor[i][0] >> hor[i][1];

    Floyd(N, far);

    put_path(far, hor, gra, horse, grass);

    return 0;
}*/


#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;


int far[1005][1005];
int gra[1005];
struct horse {
    int star_space;
    int end_space;
}hor[1005];


void floyd(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (far[j][k] > far[j][i] + far[i][k])
                    far[j][k] = far[j][i] + far[i][k];
            }
        }
        far[i][i] = 0;
    }

}

void output_path(int grass, int horse)
{
    for (int i = 0; i < horse; i++)
    {
        int path = 0x3f3f3f3f;
        for (int j = 0; j < grass; j++)
        {
            if (far[hor[i].star_space][gra[j]] + far[gra[j]][hor[i].end_space] < path)
                path = far[hor[i].star_space][gra[j]] + far[gra[j]][hor[i].end_space];
        }
        printf("%d\n", path);
    }


}

int main()
{
    int n, m;
    memset(far, 0x3f, sizeof(far));
    scanf("%d%d", &n, &m);


    for (int i = 0; i < m; i++)
    {
        int x_i, y_i, w_i;
        scanf("%d%d%d", &x_i, &y_i, &w_i);
        if (far[x_i][y_i] > w_i)
        {
            far[x_i][y_i] = w_i;
            far[y_i][x_i] = w_i;
        }
    }
    int grass, horse;
    scanf("%d%d", &grass, &horse);
    for (int i = 0; i < grass; i++)
        scanf("%d", &gra[i]);
    for (int i = 0; i < horse; i++)
        scanf("%d%d", &hor[i].star_space, &hor[i].end_space);


    floyd(n);


    output_path(grass, horse);

    return 0;
}