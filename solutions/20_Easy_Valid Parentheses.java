class Solution {
    public boolean isValid(String s) {
        boolean valid = true;
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            char x = s.charAt(i);
            if (x == '(' || x == '{' || x == '[') {
                stack.push(x);
            } else {
                if (stack.empty()) {
                    valid = false;
                    break;
                }
                char content = stack.pop();
                if ((x == ')' && content != '(') || (x == '}' && content != '{') || (x == ']' && content != '[')) {
                    valid = false;
                    break;
                }
            }
        }
        return valid && stack.empty();
    }
}