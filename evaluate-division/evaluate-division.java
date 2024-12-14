class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        List<Double> ans = new ArrayList<>();
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            double value = values[i];

            graph.putIfAbsent(a, new HashMap<>());
            graph.putIfAbsent(b, new HashMap<>());

            graph.get(a).put(b, value);
            graph.get(b).put(a, 1.0 / value);
        }
        for (int i = 0; i < queries.size(); i++) {
            String a = queries.get(i).get(0);
            String b = queries.get(i).get(1);
            Set<String> visited = new HashSet<>();
            double val = dfs(a, b, graph, visited);
            if (val != 0.0) ans.add(val);
            else ans.add(-1.0);
        }
        double[] result = new double[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        return result;
    }
    double dfs(String a, String b, Map<String, Map<String, Double>> graph, Set<String> visited){
        if (!graph.containsKey(a) || !graph.containsKey(b)) return 0.0;
        if (graph.get(a).containsKey(b)) return graph.get(a).get(b);
        visited.add(a);
        for (Map.Entry<String, Double> entry : graph.get(a).entrySet()) {
            String nextNode = entry.getKey();
            double value = entry.getValue();
            if (!visited.contains(nextNode)) {
                double result = dfs(nextNode, b, graph, visited);
                if (result != 0.0) {
                    graph.get(a).put(b, value * result);
                    return graph.get(a).get(b);
                }
            }
        }
        return 0.0;
    }
}