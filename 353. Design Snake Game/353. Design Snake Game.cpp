class SnakeGame {
public:
    int score = 0;
    list<pair<int,int>> snake;
    set<pair<int,int>> body;
    vector<vector<int>> foods;
    int food_index = 0;
    int R,C;    
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        R = height;
        C = width;
        foods = food;
        snake.push_front({0,0});
        body.insert({0,0});
    }
    
    int move(string direction) {
        //4 direction
        pair<int,int> head = snake.front();
        int r = head.first;
        int c = head.second;
        
        //move the head first
        if(direction=="U"){
            r--;
        }else if(direction=="D"){
            r++;
        }else if(direction=="L"){
            c--;
        }else{
            c++;
        }
        //cout<<r<<" "<<c<<endl;
        //see if hit the border
        if(r<0 || r>=R || c<0 || c>=C) return -1;
        //see if eat a food
        if(food_index < foods.size() && foods[food_index][0]== r && foods[food_index][1]==c){
            score++;
            food_index++;
            //put the new head into the list
            snake.push_front({r,c});
            body.insert({r,c});
        }else{ // does not eat a food
            //delete tail
            body.erase(snake.back());
            snake.pop_back();
            //see if collapse with body
            if(body.count({r,c})) return -1;
            //else not collapse
            snake.push_front({r,c});
            body.insert({r,c});
        }

        return score;


    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
