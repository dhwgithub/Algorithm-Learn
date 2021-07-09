/**

������ռ�ȳ���һ���Ԫ�س�֮Ϊ��ҪԪ�ء�����һ�� ���� ���飬�ҳ����е���ҪԪ�ء���û�У����� -1 �������ʱ�临�Ӷ�Ϊ O(N) ���ռ临�Ӷ�Ϊ O(1) �Ľ��������

 

ʾ�� 1��

���룺[1,2,5,9,5,9,5,5,5]
�����5
ʾ�� 2��

���룺[3,2]
�����-1
ʾ�� 3��

���룺[2,2,1,1,1,2,2]
�����2
*/ 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cond = -1;
        int count = 0;
        int key = nums.size() / 2;

        for (int i = 0; i < nums.size(); i ++) {
            if (count == 0) {
                cond = nums[i];
            }
            
            if (nums[i] == cond) {
                count ++;
            }
            else {
                count --;
            }
        }

        count = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (cond == nums[i]) {
                count ++;
            }
        }

        return count > key ? cond : -1;
    }
};
