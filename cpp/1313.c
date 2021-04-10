#include<stdio.h>
#include<string.h>


char result[3][5];    /*每道的牌*/

static void ChooseFiveFromEight(char *iCard)
{
    int i = 0;
    int k = 0;
    int j[5] = {0};
    char iCardRemain[8] = {0};

    for(j[0] = 0; j[0] < 8; j[0]++)
    {
        for(j[1] = 0; j[1] < 8; j[1]++)
        {
            if(j[0] >= j[1])
            {
                continue;
            }
            for(j[2] = 0; j[2] < 8; j[2]++)
            {
                if((j[0] >= j[2]) || (j[1] >= j[2]))
                {
                    continue;
                }
                for(j[3] = 0; j[3] < 8; j[3]++)
                {
                    if((j[0] >= j[3]) || (j[1] >= j[3]) || (j[2] >= j[3]))
                    {
                        continue;
                    }
                    for(j[4] = 0; j[4] < 8; j[4]++)
                    {
                        if((j[0] >= j[4]) || (j[1] >= j[4]) || (j[2] >= j[4]) ||\
                           (j[3] >= j[4]))
                        {
                            continue;
                        }

                        memcpy(iCardRemain, iCard, 8 * sizeof(char));

                        /*存入中道*/
                        result[1][0] = iCardRemain[j[0]];
                        result[1][1] = iCardRemain[j[1]];
                        result[1][2] = iCardRemain[j[2]];
                        result[1][3] = iCardRemain[j[3]];
                        result[1][4] = iCardRemain[j[4]];

                        if(result[0][0] > result[1][0])
                        {
                            continue;
                        }

                        /*把iScore中剩下的3张牌移到前3个索引中*/
                        for(i = 0, k = 0; i < 3; i++)
                        {
                            for(; k < 8; k++)
                            {
                                if((k == j[0]) || (k == j[1]) || (k == j[2] || \
                                    (k == j[3]) || (k == j[4])))
                                {
                                    continue;
                                }
                                memcpy(iCardRemain + i, iCardRemain + k, sizeof(char));
                                k++;
                                break;
                            }
                        }

                        /*存入头道*/
                        result[2][0] = iCardRemain[0];
                        result[2][1] = iCardRemain[1];
                        result[2][2] = iCardRemain[2];

                        /*打印*/
                        printf("%c %c %c %c %c  %c %c %c %c %c  %c %c %c\n", \
                                result[0][0], result[0][1], result[0][2], result[0][3], result[0][4], \
                                result[1][0], result[1][1], result[1][2], result[1][3], result[1][4], \
                                result[2][0], result[2][1], result[2][2]);
                    }
                }
            }
        }
    }
}

static void GetPerPlayerValue1313(char *iCard)
{
    int i = 0;
    int k = 0;
    int j[5] = {0};
    char card[13] = {0};

    /*13张中先找5张*/
    for(j[0] = 0; j[0] < 13; j[0]++)
    {
        for(j[1] = 0; j[1] < 13; j[1]++)
        {
            if(j[0] >= j[1])
            {
                continue;
            }
            for(j[2] = 0; j[2] < 13; j[2]++)
            {
                if((j[0] >= j[2]) || (j[1] >= j[2]))
                {
                    continue;
                }
                for(j[3] = 0; j[3] < 13; j[3]++)
                {
                    if((j[0] >= j[3]) || (j[1] >= j[3]) || (j[2] >= j[3]))
                    {
                        continue;
                    }
                    for(j[4] = 0; j[4] < 13; j[4]++)
                    {
                        if((j[0] >= j[4]) || (j[1] >= j[4]) || (j[2] >= j[4]) ||\
                           (j[3] >= j[4]))
                        {
                            continue;
                        }

                        memcpy(card, iCard, 13 * sizeof(char));
                        memset(result, 0, 3 * 5 * sizeof(char));

                        /*存入尾道*/
                        result[0][0] = card[j[0]];
                        result[0][1] = card[j[1]];
                        result[0][2] = card[j[2]];
                        result[0][3] = card[j[3]];
                        result[0][4] = card[j[4]];

                        /*把card中剩下的8张牌移到前8个索引中*/
                        for(i = 0, k = 0; i < 8; i++)
                        {
                            for(; k < 13; k++)
                            {
                                if((k == j[0]) || (k == j[1]) || (k == j[2] || \
                                    (k == j[3]) || (k == j[4])))
                                {
                                    continue;
                                }
                                memcpy(card + i, card + k, sizeof(char));
                                k++;
                                break;
                            }
                        }

                        /*从剩下的8张牌中再任意选5张牌*/
                        ChooseFiveFromEight(card);
                    }
                }
            }
        }
    }
}

int main(void)
{
    int a = 0;
    char iCard[13] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};

    GetPerPlayerValue1313(iCard);

    return 0;
}
