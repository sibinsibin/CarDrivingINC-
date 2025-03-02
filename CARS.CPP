#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawCar(int x, int y) {
    // Outer white border
    setcolor(WHITE);
    rectangle(x - 2, y - 2, x + 82, y + 32);
    rectangle(x + 18, y - 22, x + 62, y + 2);
    
    // Body of the car (Smaller)
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(x, y, x + 80, y + 30);
    floodfill(x + 1, y + 1, RED);
    rectangle(x + 20, y - 20, x + 60, y);
    floodfill(x + 21, y - 19, RED);
    
    // Inner white border
    setcolor(WHITE);
    rectangle(x + 2, y + 2, x + 78, y + 28);
    rectangle(x + 22, y - 18, x + 58, y - 2);
    
    // Windows (Black)
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(x + 30, y - 20, x + 50, y);
    floodfill(x + 31, y - 19, BLACK);
    
    // Wheels of the car
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 20, y + 30, 10);
    floodfill(x + 20, y + 30, BLACK);
    circle(x + 60, y + 30, 10);
    floodfill(x + 60, y + 30, BLACK);
}

void drawRoad() {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(0, 350, getmaxx(), 450); // Extended road to full frame width
    floodfill(1, 351, WHITE);
    
    // Draw fully white road stripes
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    for (int i = 20; i < getmaxx(); i += 40) { // Adjusted to ensure full extension
        rectangle(i, 395, i + 20, 405);
        floodfill(i + 1, 396, WHITE);
    }
}

void drawTrees() {
    for (int i = 10; i < getmaxx(); i += 150) {
        // Tree trunk
        setcolor(BROWN);
        setfillstyle(SOLID_FILL, BROWN);
        rectangle(i + 10, 250, i + 20, 350); // Smaller trunk
        floodfill(i + 11, 251, BROWN);
        
        // Christmas tree-style Leaves
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        int poly[8] = {i - 10, 270, i + 35, 270, i + 12, 240, i + 13, 240};
        fillpoly(4, poly);
        int poly2[8] = {i - 5, 250, i + 30, 250, i + 12, 220, i + 13, 220};
        fillpoly(4, poly2);
        int poly3[8] = {i, 230, i + 25, 230, i + 12, 200, i + 13, 200};
        fillpoly(4, poly3);
    }
}

void drawClouds() {
    setcolor(DARKBLUE);
    setfillstyle(SOLID_FILL, DARKBLUE);
    for (int i = 50; i < getmaxx(); i += 200) {
        fillellipse(i, 100, 30, 20);
        fillellipse(i + 20, 90, 35, 25);
        fillellipse(i + 40, 100, 30, 20);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int x, y = 370; // Adjusted position inside the road
    
    while (!kbhit()) { // Run until a key is pressed
        for (x = 60; x < getmaxx() - 150; x += 5) { // Adjusted to keep the car inside the road
            cleardevice(); // Clear previous frame
            drawRoad(); // Draw the extended road
            drawTrees(); // Draw Christmas tree-style trees on the roadside
            drawClouds(); // Draw properly shaped dark blue clouds
            drawCar(x, y); // Draw car at new position inside the road
            delay(50); // Small delay for animation
        }
    }
    
    getch(); // Wait for key press
    closegraph(); // Close graphics mode
    return 0;
}
