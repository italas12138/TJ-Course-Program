
class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<string> number;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            number.push_back(to_string(nums[i]));

        int max, large;
        string temp,result;

        //��ÿ�����ݽ��зֽ⣬�������˳��
        for (int i = 0; i < n; i++)
        {
            max = i;
            for (int j = i + 1; j < n; j++)
            {
                large = 0;
                int x = 0, y = 0;
                while (1)
                {
                    if (number[j][x] > number[max][y])
                    {
                        large = 1;//��־��Ҫ�����ݱ任
                        break;
                    }
                    else if (number[j][x] == number[max][y])//�����λ��ȣ����Խ��бȽ�
                    {
                        ++x;
                        ++y;
                        if (y == (int)number[max].length() && x == (int)number[j].length())
                            break;
                        if (y == (int)number[max].length())
                            y = 0;
                        if (x == (int)number[j].length())
                            x = 0;
                    }
                    else
                        break;
                }
                if (large)
                    max = j;
            }
            //ʵ�ֽ���
            if (max != i) {
                temp = number[i];
                number[i] = number[max];
                number[max] = temp;
            }
            result += number[i];
        }

        return result;
    }
};