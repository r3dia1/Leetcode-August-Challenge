class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for(auto it: customers)
        {
            if(it == 'Y')
                penalty++;
        }

        int close_hr = 0;
        int temp_penalty = penalty;
        for(int i=0; i<customers.size(); i++)
        {
            if(customers[i] == 'Y')
                temp_penalty -= 1;
            else if (customers[i] == 'N')
                temp_penalty += 1;

            if(temp_penalty < penalty)
            {
                penalty = temp_penalty;
                close_hr = i + 1;
            } 
        }

        return close_hr;
    }
};