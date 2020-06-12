class Solution {
    public List<Integer> peopleIndexes(List<List<String>> favoriteCompanies) {
        int companyId = 0;
        Map<String, Integer> companyIds = new HashMap<>();
        for (List<String> companies : favoriteCompanies) {
            for (String company : companies) {
                if (!companyIds.containsKey(company)) {
                    companyIds.put(company, companyId);
                    companyId++;
                }
            }
        }
        List<Set<Integer>> favorite = new LinkedList<>();
        for (List<String> companies : favoriteCompanies) {
            Set<Integer> favSet = new HashSet<>();
            for (String company : companies) {
                favSet.add(companyIds.get(company));
            }
            favorite.add(favSet);
        }
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < favorite.size(); i++) {
            int count = 0;
            for (Set<Integer> favSet: favorite) {
                if (favSet.containsAll(favorite.get(i))) {
                    count++;
                }
            }
            if (count <= 1) {
                result.add(i);
            }
        }
        return result;
    }
}