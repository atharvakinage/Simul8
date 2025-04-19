#include <raylib.h>

class Walker{

private:
        int x,y;

public:

        Walker(int width,int height){
            x = width/2;
            y = height/2;
        }

        void render(){
            DrawPixel(x, y, WHITE);
        }

        void step(){
            int choice = GetRandomValue(0,3);
            
            if(choice == 0){
                x++;
            }
            else if (choice == 1){
                x--;
            }
            else if (choice == 2){
                y++;
            }
            else{
                y--;
            }
        }

         void reset(int width, int height) {
        x = width / 2;
        y = height / 2;
    }
        

        
};


int main(void){
    const int width = 800;
    const int height = 600;
    InitWindow(width, height, "Random walker :D");
    SetTargetFPS(60);
    
    Walker w(width,height);
    
    int i = 1;
    while(!WindowShouldClose()){
        w.step();
        if (IsKeyPressed(KEY_R)) {
            w.reset(width, height);
        }
        BeginDrawing();
        w.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;


}




