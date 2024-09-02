class FreqStack {

public:
    int max_number=0;
    map<int, int> map_one;
    map<int, stack<int>> map_two;

    FreqStack()
    {

    }

    void push(int val) 
    {
        ++map_one[val];
        map_two[map_one[val]].push(val);
        max_number = max(max_number,map_one[val]); 
    }

    int pop() 
    {
        int output = map_two[max_number].top();

        map_two[max_number].pop();
        --map_one[output];
        if (map_two[max_number].empty())
            --max_number;

        return output;
    }
};