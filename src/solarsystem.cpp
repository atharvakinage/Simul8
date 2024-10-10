#include <raylib.h>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <rlgl.h>

using namespace std;

class Planet {
private:
    float radius;                  
    float distance;               
    float angle;                   
    float orbitSpeed;     
    vector<Planet> moons;

public:
   
    Planet(float r, float d, float o){
        radius = r;
        distance = d;
        orbitSpeed = o;
        angle = GetRandomValue(0,2*PI);
    }
        
    void orbit() {
        angle += orbitSpeed; 
        for (auto& moon : moons) {
            moon.orbit();
        }
    }

    void spawnMoons(int total, int level) {
        moons.reserve(total);
        for (int i = 0; i < total; i++) {
            float r = radius/(level * 2);
            float d = GetRandomValue(75,200);   
            float o = static_cast<float>(rand()) / RAND_MAX * 0.2f - 0.1f; 
            moons.emplace_back(r, d/level, o); 

            if (level < 3) {
                int num = GetRandomValue(0,4);
                moons.back().spawnMoons(num, level+1);
            }
        }
    }

    void show(Vector2 center) {
        Vector2 pos = {center.x + distance * cos(angle), center.y + distance * sin(angle)};
        
        DrawCircleV(pos, radius, BLACK);

        for (auto& moon : moons) {
            moon.show(pos);
        }
    }
};

int main(void) {
    const int width = 800;
    const int height = 600;
    InitWindow(width, height, "My Solar System :D");

    Planet sun(50, 0, 0); 
    sun.spawnMoons(4, 1);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        sun.orbit(); 

        BeginDrawing();
        ClearBackground(RAYWHITE);

        sun.show({width/2, height/2});

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
