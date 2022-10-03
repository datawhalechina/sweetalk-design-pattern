package design_patterns.java.flyweight;

import java.util.HashMap;
import java.util.Map;

public class WebSiteFactory {
    private Map<String,WebSite> flyweights = new HashMap<>();

    public WebSite getWebSiteCategory(String key) {
        if(!flyweights.containsKey(key)) {
            flyweights.put(key, new ConcreteWebSite(key));
        }
        return flyweights.get(key);
    }

    public int getWebSiteCount() {
        return flyweights.size();
    }
}
