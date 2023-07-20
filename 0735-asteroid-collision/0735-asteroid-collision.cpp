//Using Stack
class Solution {
  public: vector < int > asteroidCollision(vector < int > & asteroids) {
    vector < int > ans;
    int n = asteroids.size();
    ans.push_back(asteroids[0]);
    for (int i = 1; i < n; i++) {
      if (ans.size() == 0) {
        ans.push_back(asteroids[i]);
        continue;
      }
      int asteroid = asteroids[i];
      int top = ans.back();

      if (asteroid < 0 && top < 0 || asteroid > 0 && top > 0) { // Both are moving in same directions
        ans.push_back(asteroid);
      } else if (top > 0 && asteroid < 0) { // Collison Occurs

        int sum = top + asteroid;
        if (sum == 0) {
          ans.pop_back();
        } else if (sum < 0) {
          ans.pop_back();
          i--;
        }

      } else {
        ans.push_back(asteroid);
      }
    }

    return ans;
  }
};