class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        List<String> supplyList = new ArrayList<>();
        for (String supply : supplies) {
            supplyList.add(supply);
        }

        Map<String, Set<String>> recipeMap = new HashMap<>();
        Map<String, Set<String>> ingredientMap = new HashMap<>();
        for (int i = 0; i < recipes.length; i++) {
            List<String> ingredientList = ingredients.get(i);
            Set<String> ingredientSet = new HashSet<>(ingredientList);
            recipeMap.put(recipes[i], ingredientSet);
            for (String ingredient : ingredientList) {
                Set<String> recipeSet = ingredientMap.getOrDefault(ingredient, new HashSet<>());
                recipeSet.add(recipes[i]);
                ingredientMap.put(ingredient, recipeSet);
            }
        }

        List<String> result = new LinkedList<>();
        for (int i = 0; i < supplyList.size(); i++) {
            String supply = supplyList.get(i);
            if (!ingredientMap.containsKey(supply)) {
                continue;
            }
            Set<String> recipeSet = ingredientMap.get(supply);
            for (String recipe : recipeSet) {
                if (!recipeMap.containsKey(recipe)) {
                    continue;
                }
                Set<String> ingredientSet = recipeMap.get(recipe);
                ingredientSet.remove(supply);
                if (ingredientSet.isEmpty()) {
                    recipeMap.remove(recipe);
                    supplyList.add(recipe);
                    result.add(recipe);
                }
            }
        }

        return result;
    }
}