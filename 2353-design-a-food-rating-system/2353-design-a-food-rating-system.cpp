class FoodRatings {
public:
    unordered_map<string, pair<string, int>>food_cuisine;
    unordered_map<string, set<pair<int, string>>>cuisine_rating_food; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i) {
            food_cuisine[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_rating_food[cuisines[i]].insert({-1 * ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food].first;
        int prevRating = food_cuisine[food].second;
        
        food_cuisine[food].second = newRating;
        cuisine_rating_food[cuisine].erase({-1 * prevRating, food});
        cuisine_rating_food[cuisine].insert({-1 * newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisine_rating_food[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */