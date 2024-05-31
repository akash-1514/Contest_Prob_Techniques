class Solution {
    public boolean isValid(String word) {
        HashSet<Character> vowel = new HashSet<>();
        vowel.add('a');
        vowel.add('A');
        vowel.add('E');
        vowel.add('I');
        vowel.add('O');
        vowel.add('U');
        vowel.add('e');
        vowel.add('i');
        vowel.add('o');
        vowel.add('u');
        HashSet<Character> conso = new HashSet<>();
        for(char i = 'a';i <= 'z'; i++){
            if(vowel.contains(i)) continue;
            conso.add(i);
        }
        for(char i = 'A';i <= 'Z'; i++){
            if(vowel.contains(i)) continue;
            conso.add(i);
        }
        if(word.length() < 3) return false;
        int ct1 = 0;
        int ct2 = 0;
        char[] cc = word.toCharArray();
        for(int i = 0; i< cc.length; i++){
            if(vowel.contains(cc[i])){
                ct1++;
            }
            if(conso.contains(cc[i])){
                ct2++;
            }
        }
        if(word.indexOf("@") != -1 || word.indexOf("#") != -1 
          || word.indexOf("$") != -1){
            return false;
        }
        if(ct1 == 0 || ct2 == 0){
            return false;
        }
        return true;
    }
}