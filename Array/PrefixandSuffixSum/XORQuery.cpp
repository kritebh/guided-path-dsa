vector<int> xorQuery(vector<vector<int>> &queries)
{
	vector<int> ans;
    int temp =0;
    for(auto q:queries){
        int condition,operand;
        condition =q[0];
        operand = q[1];
        if(condition ==1){
            ans.push_back(operand^temp);
        }
        else if(condition==2){
           temp^=operand;
        }
    }
    
     for(int i=0;i<ans.size();i++){
        ans[i]=ans[i]^temp;
    }
    
    return ans;
}