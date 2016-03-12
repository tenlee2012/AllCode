import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class ArrayListTest {
    public static ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1,2,3));
    static {
        System.out.println("--static--");
        for(int e : list){
            System.out.println(e);
        }
    }
    public static void main(String[] args) {
        list.add(0);
        list.add(1);
        list.add(3);
        System.out.println("--main--");
        for(int e : list){
            System.out.println(e);
        }
    }
}
