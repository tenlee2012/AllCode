public class StringCharTest {
    public static void main(String[] args) {
        String s = new String("hello");
        StringBuilder sb = new StringBuilder("java");
        char[] c = {'w', 'o', 'r', 'l', 'd'};
        change(s, sb, c);
        System.out.println(s);
        System.out.println(sb);
        System.out.println(c);
    }
    public static void change(String s, StringBuilder sb, char c[]) {
        s = "haha";
        sb.setCharAt(0, 'a');
        c[0] = 'b';
    }
}
