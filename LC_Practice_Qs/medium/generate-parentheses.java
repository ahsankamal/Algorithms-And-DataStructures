class Solution {
    private List<String> p_list;
    public List<String> generateParenthesis(int n) {
         p_list = new ArrayList<>();
        p_list = generate("", 0, 0, n);
        return p_list;
    }
    
    private List<String>  generate(String s, int open, int close, int n){

        if(s.length() > 2*n){
            return p_list;
        }

        if(open < n){
            generate(s + "(", open+1, close, n);
        }

        if(close < open){
            generate(s + ")", open, close+1, n);
        }

        if(s.length() == 2*n){
            p_list.add(s);
        }

        return p_list;
    }
}
