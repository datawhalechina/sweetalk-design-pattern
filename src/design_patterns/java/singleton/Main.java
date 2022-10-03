package design_patterns.java.singleton;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Singleton s1 = Singleton.getInstance();
        Singleton s2 = Singleton.getInstance();

        if(s1 == s2) {
            System.out.println("两个对象是相同的实例。");
        }

        // 多线程
        Set<String> instanceSet = Collections.synchronizedSet(new HashSet<>());
        for (int i = 0; i < 100; i++) {
            new Thread(() -> {
                instanceSet.add(Singleton.getInstance().toString());
            }).start();
        }
        for (String instance : instanceSet) {
            System.out.println(instance);
        }
    }
}
